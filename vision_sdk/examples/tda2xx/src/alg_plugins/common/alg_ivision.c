/*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

#include <examples/tda2xx/src/alg_plugins/common/include/alg_ivision.h>
#include <src/utils_common/include/utils_mem.h>

/*#define DEBUG_MEM_ALLOC*/


typedef struct IM_Fxns
{
  IVISION_Fxns * fxns;

} IM_Fxns;

/**
 *******************************************************************************
 * \brief This function allocates memory for IVISION algorothm
 *
 * \param  numMemRec         [IN] Number of objects
 * \param  memRec            [IN] pointer to the memory records
 *
 * \return  SYSTEM_LINK_STATUS_SOK on success
 *
 *******************************************************************************
 */
Int32 AlgIvision_allocMem(System_LinkMemAllocInfo *info, UInt32        numMemRec,
                           IALG_MemRec  *memRec)
{
    UInt32 memRecId;
    Int32 status = SYSTEM_LINK_STATUS_SOK;
    Utils_HeapId heapId;

    /*
     * Algorithm requests memory to be allocated from different kinds Of
     * memories like DDR, DMEM, L2 etc,
     * This function should take care of allocating memory as per the
     * requirements of the algorithm
     *
     */

    /* Do a dummy free to reset sratch heap pointer to heap base
     * for L2 memory
     */
    status = Utils_memFree(UTILS_HEAPID_L2_LOCAL,0,0);
    UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

    for (memRecId = 0; memRecId < numMemRec; memRecId++)
    {
        switch(memRec[memRecId].space)
        {
            default:
                UTILS_assert(0);
                break;
            case IALG_EPROG:
            case IALG_IPROG:
            case IALG_ESDATA:
            case IALG_EXTERNAL:
                #ifdef DEBUG_MEM_ALLOC
                Vps_printf(
                    " ALG_IVISION: DDR_MEM: %d: Requesting %d B ...",
                    memRecId, memRec[memRecId].size
                    );
                #endif

                if(memRecId==0)
                {
                    heapId = UTILS_HEAPID_DDR_CACHED_LOCAL;
                }
                else
                {
                    heapId = UTILS_HEAPID_DDR_CACHED_SR;
                }

                if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
                {
                    memRec[memRecId].base = Utils_memAlloc(
                                                    heapId,
                                                    memRec[memRecId].size,
                                                    memRec[memRecId].alignment
                                                  );

                    UTILS_assert(memRec[memRecId].base != NULL);
                }
                else
                {
                     memRec[memRecId].base = System_allocLinkMemAllocInfo(
                                info,
                                memRec[memRecId].size,
                                memRec[memRecId].alignment);
                }


                #ifdef DEBUG_MEM_ALLOC
                Vps_printf(
                    " ALG_IVISION: DDR_MEM: %d: Allocated %d B @ 0x%08x !!!",
                    memRecId, memRec[memRecId].size,
                    memRec[memRecId].base
                    );
                #endif


                break;
            case IALG_DARAM0:
            case IALG_DARAM1:
            case IALG_SARAM:
            case IALG_SARAM1:
            case IALG_DARAM2:
            case IALG_SARAM2:
                #ifdef DEBUG_MEM_ALLOC
                Vps_printf(
                    " ALG_IVISION: L2_MEM: %d: Requesting %d B ...",
                    memRecId, memRec[memRecId].size
                    );
                #endif

                if(memRec[memRecId].attrs==IALG_SCRATCH)
                {
                    /*
                     * Allocate in DMEM/L2
                     *
                     * L2/DMEM alloc is ASSUMED to be of scratch type
                     */
                    memRec[memRecId].base = Utils_memAlloc(
                                                    UTILS_HEAPID_L2_LOCAL,
                                                    memRec[memRecId].size,
                                                    memRec[memRecId].alignment
                                                  );

                    #ifdef DEBUG_MEM_ALLOC
                    Vps_printf(
                        " ALG_IVISION: L2_MEM: %d: Allocated %d B @ 0x%08x !!!",
                        memRecId, memRec[memRecId].size,
                        memRec[memRecId].base
                        );
                    #endif

                }
                else
                {
                    if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
                    {
                        memRec[memRecId].base = Utils_memAlloc(
                                                    UTILS_HEAPID_DDR_CACHED_LOCAL,
                                                    memRec[memRecId].size,
                                                    memRec[memRecId].alignment
                                                  );
                    }
                    else
                    {
                        memRec[memRecId].base = System_allocLinkMemAllocInfo(
                                info,
                                memRec[memRecId].size,
                                memRec[memRecId].alignment);
                    }

                    #ifdef DEBUG_MEM_ALLOC
                    Vps_printf(
                        " ALG_IVISION: DDR_MEM: %d: Allocated %d B @ 0x%08x !!!",
                        memRecId, memRec[memRecId].size,
                        memRec[memRecId].base
                        );
                    #endif
                }
                UTILS_assert(memRec[memRecId].base != NULL);


                break;
        }
    }

    return SYSTEM_LINK_STATUS_SOK;
}


/**
 *******************************************************************************
 *
 * \brief This function frees memory for the IVISION algorithm
 *
 * \param  numMemRec         [IN] Number of objects
 * \param  memRec            [IN] pointer to the memory records
 *
 * \return  SYSTEM_LINK_STATUS_SOK on success
 *
 *******************************************************************************
 */
Int32 AlgIvision_freeMem(const System_LinkMemAllocInfo *info, UInt32        numMemRec,
                          IALG_MemRec  *memRec)
{
    UInt32 memRecId;
    Int32 status = SYSTEM_LINK_STATUS_SOK;
    Utils_HeapId heapId;

    for (memRecId = 0; memRecId < numMemRec; memRecId++)
    {
        switch(memRec[memRecId].space)
        {
            default:
                UTILS_assert(0);
                break;
            case IALG_EPROG:
            case IALG_IPROG:
            case IALG_ESDATA:
            case IALG_EXTERNAL:
                if(memRecId==0)
                {
                    heapId = UTILS_HEAPID_DDR_CACHED_LOCAL;
                }
                else
                {
                    heapId = UTILS_HEAPID_DDR_CACHED_SR;
                }

                if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
                {
                    status = Utils_memFree(
                                    heapId,
                                    memRec[memRecId].base,
                                    memRec[memRecId].size
                                   );
                    UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);
                }

                break;
            case IALG_DARAM0:
            case IALG_DARAM1:
            case IALG_SARAM:
            case IALG_SARAM1:
            case IALG_DARAM2:
            case IALG_SARAM2:
                if(memRec[memRecId].attrs==IALG_SCRATCH)
                {
                    status = Utils_memFree(
                                        UTILS_HEAPID_L2_LOCAL,
                                        memRec[memRecId].base,
                                        memRec[memRecId].size
                                      );
                }
                else
                {
                    if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
                    {
                        status = Utils_memFree(
                                        UTILS_HEAPID_DDR_CACHED_LOCAL,
                                        memRec[memRecId].base,
                                        memRec[memRecId].size
                                      );
                    }
                }
                UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);
                break;
        }
    }

    return status;
}

Void *AlgIvision_create_useLinkMem(System_LinkMemAllocInfo *info, const IVISION_Fxns *fxns, IALG_Params *pAlgPrms)
{
    UInt32 numMemRec;
    IALG_MemRec   *memRec;
    IM_Fxns *algHandle = NULL;
    Int32 status = SYSTEM_LINK_STATUS_SOK;

    numMemRec = fxns->ialg.algNumAlloc();

    /*
     * Allocate memory for the records. These are NOT the actual memory of
     * tha algorithm
     */
    if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
    {
        memRec    = (IALG_MemRec *)malloc(numMemRec * sizeof(IALG_MemRec));
    }
    else
    {
        memRec = System_allocLinkMemAllocInfo(
                                info,
                                numMemRec * sizeof(IALG_MemRec),
                                2);
    }

    if(memRec != NULL)
    {
        status = fxns->ialg.algAlloc(pAlgPrms, NULL, memRec);
        if(status==IALG_EOK)
        {
            status = AlgIvision_allocMem(info, numMemRec, memRec);
            if(status==IALG_EOK)
            {
                status = fxns->ialg.algInit
                (
                    (IALG_Handle)(&algHandle),
                    memRec,
                    NULL,
                    pAlgPrms
                );

                if(status != IALG_EOK)
                {
                    algHandle = NULL;
                }
                else
                {
                    algHandle = (IM_Fxns *)memRec[0].base;
                }
            }
        }
        if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
        {
            free(memRec);
        }
    }

    return algHandle;
}

Void *AlgIvision_create(const IVISION_Fxns *fxns, IALG_Params *pAlgPrms)
{
    return AlgIvision_create_useLinkMem(NULL, fxns, pAlgPrms);
}

Int32 AlgIvision_delete_useLinkMem(System_LinkMemAllocInfo *info, Void *algHandle)
{
    UInt32 numMemRec;
    IALG_MemRec   *memRec;
    IM_Fxns *ivision = (IM_Fxns *)algHandle;
    Int32 status = SYSTEM_LINK_STATUS_EFAIL;

    numMemRec = ivision->fxns->ialg.algNumAlloc();

    /*
     * Allocate memory for the records. These are NOT the actual memory of
     * tha algorithm
     */
    if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
    {
        memRec    = (IALG_MemRec *)malloc(numMemRec * sizeof(IALG_MemRec));
    }
    else
    {
        memRec = System_allocLinkMemAllocInfo(
                                info,
                                numMemRec * sizeof(IALG_MemRec),
                                2);
    }

    if(memRec != NULL)
    {
        status = ivision->fxns->ialg.algFree(algHandle, memRec);
        if(status==IALG_EOK)
        {
            status = AlgIvision_freeMem(info, numMemRec, memRec);
        }
        if((info== NULL) || (System_useLinkMemAllocInfo(info)==FALSE))
        {
            free(memRec);
        }
    }

    return status;
}

Int32 AlgIvision_delete(Void *algHandle)
{
    return AlgIvision_delete_useLinkMem(NULL, algHandle);
}


Int32 AlgIvision_process(Void *algHandle,
        IVISION_InBufs *inBufs,
        IVISION_OutBufs *outBufs,
        IVISION_InArgs *inArgs,
        IVISION_OutArgs *outArgs)
{
    IM_Fxns *ivision = (IM_Fxns *)algHandle;
    Int32 status = SYSTEM_LINK_STATUS_SOK;

    ivision->fxns->ialg.algActivate(
        (IALG_Handle)ivision
        );

    status = ivision->fxns->algProcess(
                    (IVISION_Handle)ivision,
                    inBufs,
                    outBufs,
                    inArgs,
                    outArgs
        );


    ivision->fxns->ialg.algDeactivate(
        (IALG_Handle)ivision
        );

    return status;
}

Int32 AlgIvision_control(Void *algHandle,
                    IALG_Cmd cmd,
                    const IALG_Params *inParams,
                    IALG_Params *outParams)
{
    IM_Fxns *ivision = (IM_Fxns *)algHandle;
    Int32 status = SYSTEM_LINK_STATUS_SOK;

    status = ivision->fxns->algControl(
                    (IVISION_Handle)ivision,
                    cmd,
                    inParams,
                    outParams
        );

    return status;
}

Void AlgIvision_activate(Void *algHandle)
{
    IM_Fxns *ivision = (IM_Fxns *)algHandle;

    ivision->fxns->ialg.algActivate(
        (IALG_Handle)ivision
        );

}

Void AlgIvision_deActivate(Void *algHandle)
{
    IM_Fxns *ivision = (IM_Fxns *)algHandle;

    ivision->fxns->ialg.algDeactivate(
        (IALG_Handle)ivision
        );
}
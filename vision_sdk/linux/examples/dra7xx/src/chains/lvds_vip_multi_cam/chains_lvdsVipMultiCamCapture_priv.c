/*
*******************************************************************************
*
* Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
* ALL RIGHTS RESERVED
*
*******************************************************************************
*/

/*
*******************************************************************************
*
* IMPORTANT NOTE:
*  This file is AUTO-GENERATED by Vision SDK use case generation tool
*
*******************************************************************************
*/
#include "chains_lvdsVipMultiCamCapture_priv.h"
Void chains_lvdsVipMultiCamCapture_SetLinkId(chains_lvdsVipMultiCamCaptureObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE_0;
       pObj->SyncLinkID                     = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->IPCOut_IPU1_0_A15_0_0LinkID    = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_A15_0_IPU1_0_0LinkID     = A15_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->EpSinkLinkID                   = SYSTEM_LINK_ID_EP_0;
}

Void chains_lvdsVipMultiCamCapture_ResetLinkPrms(chains_lvdsVipMultiCamCaptureObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       SyncLink_CreateParams_Init(&pObj->SyncPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_A15_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_A15_0_IPU1_0_0Prm);
}

Void chains_lvdsVipMultiCamCapture_SetPrms(chains_lvdsVipMultiCamCaptureObj *pObj){
}

Void chains_lvdsVipMultiCamCapture_ConnectLinks(chains_lvdsVipMultiCamCaptureObj *pObj){

       //Capture -> Sync
       pObj->CapturePrm.outQueParams.nextLink = pObj->SyncLinkID;
       pObj->SyncPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->SyncPrm.inQueParams.prevLinkQueId = 0;

       //Sync -> IPCOut_IPU1_0_A15_0_0
       pObj->SyncPrm.outQueParams.nextLink = pObj->IPCOut_IPU1_0_A15_0_0LinkID;
       pObj->IPCOut_IPU1_0_A15_0_0Prm.inQueParams.prevLinkId = pObj->SyncLinkID;
       pObj->IPCOut_IPU1_0_A15_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_IPU1_0_A15_0_0 -> IPCIn_A15_0_IPU1_0_0
       pObj->IPCOut_IPU1_0_A15_0_0Prm.outQueParams.nextLink = pObj->IPCIn_A15_0_IPU1_0_0LinkID;
       pObj->IPCIn_A15_0_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_A15_0_0LinkID;
       pObj->IPCIn_A15_0_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_A15_0_IPU1_0_0 -> EpSink
       pObj->IPCIn_A15_0_IPU1_0_0Prm.outQueParams.nextLink = pObj->EpSinkLinkID;
       pObj->EpSinkPrm.inQueParams.prevLinkId = pObj->IPCIn_A15_0_IPU1_0_0LinkID;
       pObj->EpSinkPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_lvdsVipMultiCamCapture_Create(chains_lvdsVipMultiCamCaptureObj *pObj, Void *appObj){

       Int32 status;

       chains_lvdsVipMultiCamCapture_SetLinkId(pObj);
       chains_lvdsVipMultiCamCapture_ResetLinkPrms(pObj);

       chains_lvdsVipMultiCamCapture_SetPrms(pObj);
       chains_lvdsVipMultiCamCapture_SetAppPrms(pObj, appObj);

       chains_lvdsVipMultiCamCapture_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SyncLinkID, &pObj->SyncPrm, sizeof(pObj->SyncPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_A15_0_0LinkID, &pObj->IPCOut_IPU1_0_A15_0_0Prm, sizeof(pObj->IPCOut_IPU1_0_A15_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_A15_0_IPU1_0_0LinkID, &pObj->IPCIn_A15_0_IPU1_0_0Prm, sizeof(pObj->IPCIn_A15_0_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->EpSinkLinkID, &pObj->EpSinkPrm, sizeof(pObj->EpSinkPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCamCapture_Start(chains_lvdsVipMultiCamCaptureObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->EpSinkLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCamCapture_Stop(chains_lvdsVipMultiCamCaptureObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->EpSinkLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCamCapture_Delete(chains_lvdsVipMultiCamCaptureObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->EpSinkLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_lvdsVipMultiCamCapture_printBufferStatistics(chains_lvdsVipMultiCamCaptureObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->SyncLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->EpSinkLinkID);
       Task_sleep(500);
}

Void chains_lvdsVipMultiCamCapture_printStatistics(chains_lvdsVipMultiCamCaptureObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->SyncLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->EpSinkLinkID);
       Task_sleep(500);
}

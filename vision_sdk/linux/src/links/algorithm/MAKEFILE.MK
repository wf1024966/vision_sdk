
include $(vision_sdk_PATH)/linux/build/common_header_a15.mk

INCLUDE+= $(LINUX_COMMON_INC) -I$(ipc_PATH)/linux/include -I$(ipc_PATH)/hlos_common/include -I$(ipc_PATH)/packages -I$(kernel_PATH)/include/generated/uapi 
INCLUDE+= $(LINK_API_INC) -I$(vision_sdk_PATH)/linux/src/osa/include -I$(vision_sdk_PATH)/linux -I$(edma_PATH)/packages $(LINUX_COMMON_INC) $(OSA_KERMOD_INC)

include $(vision_sdk_PATH)/linux/build/common_footer_a15.mk

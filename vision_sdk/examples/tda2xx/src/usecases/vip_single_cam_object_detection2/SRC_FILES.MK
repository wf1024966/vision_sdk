
SRCDIR += $(vision_sdk_PATH)/examples/tda2xx/src/usecases/vip_single_cam_object_detection2

SRCS_$(IPU_PRIMARY_CORE) += \
        chains_vipSingleCameraObjectDetect2Tda3xx_priv.c \
        chains_vipSingleCameraObjectDetect2Tda3xx.c \

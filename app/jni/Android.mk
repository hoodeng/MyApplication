LOCAL_PATH := $(call my-dir)


include $(CLEAR_VARS)
LOCAL_MODULE    := inner
LOCAL_SRC_FILES := lib/libinner.so

LOCAL_EXPORT_C_INCLUDES := lib/include
include $(PREBUILT_SHARED_LIBRARY)


include $(CLEAR_VARS)
LOCAL_MODULE    := outter
LOCAL_SRC_FILES := Outter.cpp
LOCAL_LDLIBS    += -L$(SYSROOT)/lib -llog
LOCAL_CFLAGS    := -g

LOCAL_SHARED_LIBRARIES := inner
include $(BUILD_SHARED_LIBRARY)
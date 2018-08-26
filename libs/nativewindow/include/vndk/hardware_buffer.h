/*
 * Copyright 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_VNDK_NATIVEWINDOW_AHARDWAREBUFFER_H
#define ANDROID_VNDK_NATIVEWINDOW_AHARDWAREBUFFER_H

// vndk is a superset of the NDK
#include <android/hardware_buffer.h>

#include <cutils/native_handle.h>

__BEGIN_DECLS

const native_handle_t* AHardwareBuffer_getNativeHandle(const AHardwareBuffer* buffer);


/**
 * Buffer pixel formats.
 */
enum {
    /* for future proofing, keep these in sync with system/graphics-base.h */

    /* same as HAL_PIXEL_FORMAT_BGRA_8888 */
    AHARDWAREBUFFER_FORMAT_B8G8R8A8_UNORM           = 5,
    /* same as HAL_PIXEL_FORMAT_YV12 */
    AHARDWAREBUFFER_FORMAT_YV12                     = 0x32315659,
    /* same as HAL_PIXEL_FORMAT_Y8 */
    AHARDWAREBUFFER_FORMAT_Y8                       = 0x20203859,
    /* same as HAL_PIXEL_FORMAT_Y16 */
    AHARDWAREBUFFER_FORMAT_Y16                      = 0x20363159,
    /* same as HAL_PIXEL_FORMAT_RAW16 */
    AHARDWAREBUFFER_FORMAT_RAW16                    = 38, // was 32
    /* same as HAL_PIXEL_FORMAT_RAW10 */
    AHARDWAREBUFFER_FORMAT_RAW10                    = 43, // was 37
    /* same as HAL_PIXEL_FORMAT_RAW12 */
    AHARDWAREBUFFER_FORMAT_RAW12                    = 44, // was 38
    /* same as HAL_PIXEL_FORMAT_RAW_OPAQUE */
    AHARDWAREBUFFER_FORMAT_RAW_OPAQUE               = 42, // was 36
    /* same as HAL_PIXEL_FORMAT_IMPLEMENTATION_DEFINED */
    AHARDWAREBUFFER_FORMAT_IMPLEMENTATION_DEFINED   = 40, // was 34
    /* same as HAL_PIXEL_FORMAT_YCBCR_420_888 */
    AHARDWAREBUFFER_FORMAT_Y8Cb8Cr8_420             = 41, // was 35
#ifdef STE_HARDWARE
    AHARDWAREBUFFER_FORMAT_YCbCr_422_P        = 18,
    AHARDWAREBUFFER_FORMAT_YCbCr_420_P        = 19,
    AHARDWAREBUFFER_FORMAT_YCbCr_420_I        = 21,
    AHARDWAREBUFFER_FORMAT_CbYCrY_422_I       = 22,
    AHARDWAREBUFFER_FORMAT_CbYCrY_420_I       = 23,
    AHARDWAREBUFFER_FORMAT_YCbCr_420_SP_TILED = 32,
    AHARDWAREBUFFER_FORMAT_YCbCr_420_SP       = 33,
    AHARDWAREBUFFER_FORMAT_YCrCb_420_SP_TILED = 34,
    AHARDWAREBUFFER_FORMAT_YCrCb_422_SP       = 35,
    AHARDWAREBUFFER_FORMAT_YCrCb_422_P        = 36,
    AHARDWAREBUFFER_FORMAT_YCrCb_420_P        = 37,
    /* STE: Added Support of YUV42XMBN, required for Copybit CC acceleration */
    AHARDWAREBUFFER_FORMAT_YCBCR42XMBN        = 14,
#endif
    /* same as HAL_PIXEL_FORMAT_YCBCR_422_SP */
    AHARDWAREBUFFER_FORMAT_YCbCr_422_SP             = 16,
    /* same as HAL_PIXEL_FORMAT_YCRCB_420_SP */
    AHARDWAREBUFFER_FORMAT_YCrCb_420_SP             = 17,
    /* same as HAL_PIXEL_FORMAT_YCBCR_422_I */
    AHARDWAREBUFFER_FORMAT_YCbCr_422_I              = 20,
};

__END_DECLS

#endif /* ANDROID_VNDK_NATIVEWINDOW_AHARDWAREBUFFER_H */

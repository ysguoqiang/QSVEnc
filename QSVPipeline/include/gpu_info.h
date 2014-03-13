﻿//  -----------------------------------------------------------------------------------------
//    QSVEnc by rigaya
//  -----------------------------------------------------------------------------------------
//   ソースコードについて
//   ・無保証です。
//   ・本ソースコードを使用したことによるいかなる損害・トラブルについてrigayaは責任を負いません。
//   以上に了解して頂ける場合、本ソースコードの使用、複製、改変、再頒布を行って頂いて構いません。
//  -----------------------------------------------------------------------------------------

#ifndef _GPU_INFO_H_
#define _GPU_INFO_H_

#include <tchar.h>

int getGPUInfo(const char *VendorName, TCHAR *buffer, unsigned int buffer_size, bool driver_version_only);

#endif //_GPU_INFO_H_

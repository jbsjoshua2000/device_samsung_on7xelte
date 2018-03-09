/*
   Copyright (c) 2018, The LineageOS Project. All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.
   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <android-base/properties.h>
#include <android-base/logging.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void init_target_properties()
{
    std::string platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G610F") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xeltedd/on7xelte:7.0/NRD90M/G610FDDU1BQL9:user/release-keys");
        property_override("ro.build.description", "on7xeltedd-user 7.0 NRD90M G610FDDU1BQL9 release-keys");
        property_override("ro.product.model", "SM-G610F");
    } else if (bootloader.find("G610L") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xeltekl/on7xelte:7.0/NRD90M/G610LKLU1BQL3:user/release-keys");
        property_override("ro.build.description", "on7xeltekl-user 7.0 NRD90M G610LKLU1BQL3 release-keys");
        property_override("ro.product.model", "SM-G610L");
    } else if (bootloader.find("G610K") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xeltekk/on7xelte:7.0/NRD90M/G610KKKU1BQL3:user/release-keys");
        property_override("ro.build.description", "on7xeltekk-user 7.0 NRD90M G610KKKU1BQL3 release-keys");
        property_override("ro.product.model", "SM-G610K");
    } else if (bootloader.find("G610S") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xelteks/on7xelte:7.0/NRD90M/G610SKSU1BQL3:user/release-keys");
        property_override("ro.build.description", "on7xelteks-user 7.0 NRD90M G610SKSU1BQL3 release-keys");
        property_override("ro.product.model", "SM-G610S");
    } else if (bootloader.find("G610M") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xelteub/on7xeltektt:7.0/NRD90M/G610MUBU1BRB1:user/release-keys");
        property_override("ro.build.description", "on7xelteub-user 7.0 NRD90M G610MUBU1BRB1 release-keys");
        property_override("ro.product.model", "SM-G610M");
    } else if (bootloader.find("G610Y") == 0) {
        property_override("ro.build.fingerprint", "samsung/on7xeltezt/on7xeltektt:7.0/NRD90M/G610YZTU1AQK1:user/release-keys");
        property_override("ro.build.description", "on7xeltezt-user 7.0 NRD90M G610YZTU1AQK1 release-keys");
        property_override("ro.product.model", "SM-G610Y");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}

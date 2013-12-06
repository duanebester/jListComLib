//
//  listCom.h
//  listCom
//
//  Created by Angelo Scialabba on 11/13/13.
// 
//

#ifndef __listCom__listCom__
#define __listCom__listCom__

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
#include <jni.h>


#define MAXPATHLEN 1024

typedef struct SerialDevice {
    char port[MAXPATHLEN];
    char locationId[MAXPATHLEN];
    char vendorId[MAXPATHLEN];
    char productId[MAXPATHLEN];
    char manufacturer[MAXPATHLEN];
    char serialNumber[MAXPATHLEN];
} stSerialDevice;


typedef struct DeviceListItem {
    struct SerialDevice value;
    struct DeviceListItem *next;
    int* length;
} stDeviceListItem;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobjectArray JNICALL Java_cc_arduino_packages_discoverers_SerialLister_serialPortList(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif

#endif
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
#include <JavaVM/jni.h>

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jobjectArray JNICALL Java_cc_arduino_serial_SerialLister_serialPortList(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif

#endif /* defined(__listCom__listCom__) */

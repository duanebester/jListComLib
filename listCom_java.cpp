//
//  listCom.cpp
//  listCom
//
//  Created by Angelo Scialabba on 11/13/13.
//  
//

#include "listCom_java.h"
#ifdef WIN

#include "src_win/listCom.c"

#elif defined(MAC)

#include "src_mac/listCom.c"

#else

#warning No platform specified

#endif

JNIEXPORT jobjectArray JNICALL Java_cc_arduino_serial_SerialLister_serialPortList(JNIEnv *env, jobject obj){
    
    jclass mapClass = env->FindClass("java/util/HashMap");
    jmethodID mapCtor = env->GetMethodID(mapClass,"<init>","(I)V");    
    jmethodID put = env->GetMethodID(mapClass,"put","(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;");
	
    int len,index;
    stDeviceListItem* devices,*temp;
	
	len = 0;
    devices = GetSerialDevices();
    temp = devices;
    
    len = *(devices->length);
    
    devices = temp;    
    index = 0;
    
	//create the hash map
    jobjectArray devicesArray = env->NewObjectArray(len, env->FindClass("java/util/HashMap"),0);
	
	//populate the hash map
    while(devices!=NULL){
	
        jobject mapObj = env->NewObject(mapClass,mapCtor,3);
        env->CallObjectMethod(mapObj, put,env->NewStringUTF("port"), env->NewStringUTF(devices->value.port));
        env->CallObjectMethod(mapObj, put,env->NewStringUTF("vendorId"), env->NewStringUTF(devices->value.vendorId));
        env->CallObjectMethod(mapObj, put,env->NewStringUTF("productId"), env->NewStringUTF(devices->value.productId));
        temp = devices;
        devices = devices->next;
        free(temp);
        env->SetObjectArrayElement(devicesArray, index, mapObj);
        env->DeleteLocalRef(mapObj);
        index++;
        
    }
	
    return devicesArray;
	
}
/*
 * Copyright (C) 2010 The Android Open Source Project
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

#ifndef ANDROID_GUI_SENSOR_MANAGER_H
#define ANDROID_GUI_SENSOR_MANAGER_H

#include <map>
#include <unordered_map>

#include <stdint.h>
#include <sys/types.h>

#include <binder/IBinder.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>

#include <utils/Errors.h>
#include <utils/StrongPointer.h>
#include <utils/Singleton.h>
#include <utils/Vector.h>
#include <utils/String8.h>

#include <sensor/SensorEventQueue.h>

// ----------------------------------------------------------------------------
// Concrete types for the NDK
struct ASensorManager { };

struct native_handle;
typedef struct native_handle native_handle_t;

// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

class ISensorServer;
class Sensor;
class SensorEventQueue;
// ----------------------------------------------------------------------------

class SensorManager :
#ifdef STE_HARDWARE
    public ASensorManager,
    public Singleton<SensorManager>
#else
    public ASensorManager
#endif
{
public:
    static SensorManager& getInstanceForPackage(const String16& packageName);
#ifdef STE_HARDWARE
    SensorManager();
    ~SensorManager();
#else
    ~SensorManager();
#endif

#ifdef COMPAT_SENSORS_M
    ssize_t getSensorList(Sensor const* const** list) const;
#else
    ssize_t getSensorList(Sensor const* const** list);
#endif
    ssize_t getDynamicSensorList(Vector<Sensor>& list);
    Sensor const* getDefaultSensor(int type);
#ifdef STE_HARDWARE
    sp<SensorEventQueue> createEventQueue();
    sp<SensorEventQueue> createEventQueue(String8 packageName, int mode = 0);
#else
    sp<SensorEventQueue> createEventQueue(String8 packageName = String8(""), int mode = 0);
#endif
    bool isDataInjectionEnabled();

private:
    // DeathRecipient interface
    void sensorManagerDied();
    static status_t waitForSensorService(sp<ISensorServer> *server);

    SensorManager(const String16& opPackageName);
#ifdef COMPAT_SENSORS_M
    status_t assertStateLocked() const;
#else
    status_t assertStateLocked();
#endif

private:
    static Mutex sLock;
    static std::map<String16, SensorManager*> sPackageInstances;

#ifdef COMPAT_SENSORS_M
    mutable Mutex mLock;
    mutable sp<ISensorServer> mSensorServer;
    mutable Sensor const** mSensorList;
    mutable Vector<Sensor> mSensors;
    mutable sp<IBinder::DeathRecipient> mDeathObserver;
#else
    Mutex mLock;
    sp<ISensorServer> mSensorServer;
    Sensor const** mSensorList;
    Vector<Sensor> mSensors;
    sp<IBinder::DeathRecipient> mDeathObserver;
#endif
    const String16 mOpPackageName;
};

// ----------------------------------------------------------------------------
}; // namespace android

#endif // ANDROID_GUI_SENSOR_MANAGER_H

#pragma once

#ifdef __MINGW32__
    #ifndef BOOST_USE_WINDOWS_H
        #define BOOST_USE_WINDOWS_H
    #endif
#endif

#include <winsock2.h>
#include <windows.h>
#include <stdint.h>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>
#include <mingw.future.h>
#include <mingw.thread.h>
#include <sysinfoapi.h>
#include <processthreadsapi.h>
#include <intrin.h>

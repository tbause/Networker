// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#define _WIN32_WINNT 0x0502

// BOOST includes
// Note: Needs to come before windows.h to resolve definition conflict!
// #define WIN32_LEAN_AND_MEAN
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>

// Standard Windows includes

#include <string>
#include <iostream>
#include <vector>
#include <chrono>

// TODO: reference additional headers your program requires here
#include "libNetwork.h"
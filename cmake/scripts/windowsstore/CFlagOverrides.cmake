# compiler flags
if(DEFINED ENV{MAXTHREADS})
  set(MP_FLAG "/MP$ENV{MAXTHREADS}")
else()
  set(MP_FLAG "/MP")
endif()
string(APPEND CMAKE_C_FLAGS_INIT " /D_UNICODE /DUNICODE ${MP_FLAG} /DWIN32 /D_WINDOWS /W3 /Zi /DTARGET_WINDOWS")
string(APPEND CMAKE_C_FLAGS_INIT " /DWINAPI_FAMILY=2 /DTARGET_WINDOWS_STORE /D_WINSOCK_DEPRECATED_NO_WARNINGS /D_CRT_NONSTDC_NO_DEPRECATE")
string(APPEND CMAKE_C_FLAGS_DEBUG_INIT " /D_DEBUG /MDd /Ob0 /Od /RTC1 /D_ITERATOR_DEBUG_LEVEL=0")
string(APPEND CMAKE_C_FLAGS_RELEASE_INIT " /MD /Ox /Ob2 /Oi /Ot /Oy /GL /DNDEBUG")
# linker flags
string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT " /DYNAMICBASE /NXCOMPAT /APPCONTAINER")
# win32 specific flags
if("$ENV{Platform}" STREQUAL X86)
  string(APPEND CMAKE_C_FLAGS_INIT " /arch:SSE2")
  string(APPEND CMAKE_SHARED_LINKER_FLAGS_INIT " /SAFESEH")
endif()

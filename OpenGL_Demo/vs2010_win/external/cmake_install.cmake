# Install script for directory: D:/Users/wanxwang/advanced_OS/OpenGL_Demo/samples/external

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/OpenGLSDKSamples")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("D:/Users/wanxwang/advanced_OS/OpenGL_Demo/vs2010_win/external/AntTweakBar/cmake_install.cmake")
  include("D:/Users/wanxwang/advanced_OS/OpenGL_Demo/vs2010_win/external/stbi/cmake_install.cmake")
  include("D:/Users/wanxwang/advanced_OS/OpenGL_Demo/vs2010_win/external/libogg/cmake_install.cmake")
  include("D:/Users/wanxwang/advanced_OS/OpenGL_Demo/vs2010_win/external/libvorbis/cmake_install.cmake")

endif()


cmake_minimum_required(VERSION 3.29)
project(ProjectNPA)

set(CMAKE_CXX_STANDARD 20)
set(WPD_PACK_PATH "C:/Libraries/WpdPack")

include_directories(${WPD_PACK_PATH}/Include)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(WINPCAP_LIB "${WPD_PACK_PATH}/Lib/x64/Packet.lib" "${WPD_PACK_PATH}/Lib/x64/wpcap.lib")
else()
    set(WINPCAP_LIB "${WPD_PACK_PATH}/Lib" "${WPD_PACK_PATH}/Lib/wpcap.lib")
endif()

add_executable(ProjectNPA main.cpp
        include/PacketAnalyzer.h
        src/PacketAnalyzer.cpp
        include/Utils.h
        src/Utils.cpp
        include/ConnectionRecord.h
        include/ConnectionCache.h
        src/ConnectionCache.cpp)
target_link_libraries(ProjectNPA ${WINPCAP_LIB})

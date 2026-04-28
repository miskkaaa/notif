# notif api CPM configuration because i need it fuck you
# add this to your cmake file:
# CPMAddPackage(NAME notif FORGEJO_REPOSITORY miskaa/notif VERSION 1.0.1)

# possibly you can also download this file and include it yourself
# like include("path/to/notif/cpm.cmake")
include(FetchContent)

# get CPM if not available
if(NOT DEFINED CPM_VERSION)
    FetchContent_Declare(
        CPM
        GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake
        GIT_TAG v0.38.1
    )
    FetchContent_MakeAvailable(CPM)
endif()

# ^^ thats not needed if you already have CPM in your project


# CPM package configuration for notif
if(NOT TARGET notif::notif)
    CPMAddPackage(
        NAME notif
        VERSION 1.0.1
        GIT_REPOSITORY https://forgejo.hlelo.cc/Miskaa/notif.git
        GIT_TAG v1.0.x.3.3
        OPTIONS
            "GEODE_SDK $ENV{GEODE_SDK}"
    )
endif()

# link automatically
if(TARGET notif::notif)
    target_link_libraries(${PROJECT_NAME} PRIVATE notif::notif)
    target_include_directories(${PROJECT_NAME} PRIVATE ${notif_SOURCE_DIR}/src/includes)
endif()
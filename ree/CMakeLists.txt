cmake_minimum_required(VERSION 3.16)

if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER ${CMAKE_CURRENT_SOURCE_DIR}/../env/aarch64-linux-gnu/bin/aarch64-linux-gnu-gcc)
endif()

project(hello_ta)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_C_STANDARD_REQUIRED True)

# ========================================================
# SET PATH
# ========================================================

set(SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../env/optee-sdk)
set(TEEC_INCLUDE_DIR ${SDK_PATH}/ca_sdk/aarch64-linux-gnu-gcc/include)
set(TEEC_LIB_DIR     ${SDK_PATH}/ca_sdk/aarch64-linux-gnu-gcc/lib)

# ========================================================
# ADD FILE
# ========================================================

set(OPTEE_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB OPTEE_SRC_FILES ${OPTEE_SRC_DIR}/*.c)

add_executable(${PROJECT_NAME}
    ${OPTEE_SRC_FILES}
)

# ========================================================
# LINKING
# ========================================================

link_directories(
    ${TEEC_LIB_DIR}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${TEEC_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    ${TEEC_LIB_DIR}/libteec.so
)
cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

project(serial_interface_piezo_motor)

# enable_testing()

include_directories(
  include
  # CTest
)

link_directories(/usr/lib)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/piezointerface.cpp
)

# add_executable(testing
#   tests/protocol_concatenate.cpp
# )


# add_test(NAME ProtocolConcat COMMAND testing)

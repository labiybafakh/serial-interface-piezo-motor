cmake_minimum_required(VERSION 3.27)


project(serial_interface_piezo_motor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_CXX_STANDARD 17)

# enable_testing()

include_directories(
  include
  # CTest
)

# link_directories(/usr/lib)


add_executable(${PROJECT_NAME}
    src/main.cpp
    src/piezointerface.cpp
)

# add_executable(testing
#   tests/protocol_concatenate.cpp
# )


# add_test(NAME ProtocolConcat COMMAND testing)

#include "piezeo_interface.hpp"


std::string set_position(int position, int step){
    // The command to run the motor based on serial protocol
    std::string buffer = "X1J" + std::to_string(position) + ",0," + std::to_string(step) + "\r";

    return buffer;
}

int stop(int port){
    // The command to stop the motor controller based on serial protocol
    std::string command = "X1S\r";

    // Writing to the serial port
    int bytes_sent = write(port, command.c_str(), command.size());

    if (bytes_sent < 0) {
        std::cerr << "Error " << errno << " from write: " << strerror(errno) << std::endl;
    } else {
        std::cout << "Command sent to the motor controller." << std::endl;
    }

    return bytes_sent;
}

int target_position(int port, int position, int step){
    std::string command = set_position(position, step);
    // Writing to the serial port
    int bytes_sent = write(port, command.c_str(), command.size());

    if (bytes_sent < 0) {
        std::cerr << "Error " << errno << " from write: " << strerror(errno) << std::endl;
    } else {
        std::cout << "Command sent to the motor controller." << std::endl;
    }

    return bytes_sent;
}
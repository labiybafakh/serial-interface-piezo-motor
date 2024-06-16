#include "piezeo_interface.hpp"

PiezoMotor::PiezoMotor(std::string &serial_port){
    serial_port_ = serial_port.c_str();

    fd_ = open(serial_port_, O_RDWR | O_NOCTTY | O_SYNC); //open the serial port
    if (fd_ < 0) { 
        std::cerr << "Error opening " << serial_port_ << ": " << strerror(errno) << std::endl;
    }

    struct termios tty;
    memset(&tty, 0, sizeof(tty));
    if (tcgetattr(fd_, &tty) != 0) {
        std::cerr << "Error from tcgetattr: " << strerror(errno) << std::endl;
    }

    // Set baud rate read and write
    cfsetospeed(&tty, B115200); 
    cfsetispeed(&tty, B115200);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_cflag &= ~(PARENB | PARODD);              // No parity
    tty.c_cflag &= ~CSTOPB;                         // 1 stop bit
    tty.c_cflag &= ~CRTSCTS;                        // No hardware flow control

    if (tcsetattr(fd_, TCSANOW, &tty) != 0) {
        std::cerr << "Error from tcsetattr: " << strerror(errno) << std::endl;
    }
}

PiezoMotor::~PiezoMotor(){
    close(fd_);
}

bool PiezoMotor::move_step(int &n_step, int &freq){
    // The command to run the motor based on serial protocol
    std::string buffer = "X1J" + std::to_string(n_step) + ",0," + std::to_string(freq) + "\r";

    // Writing to the serial port
    int bytes_sent = write(fd_, buffer.c_str(), buffer.size());

    if (bytes_sent < 0) {
        std::cerr << "Error " << errno << " from write: " << strerror(errno) << std::endl;
        return false;
    } else {
        std::cout << "Command sent to the motor controller." << std::endl;
        return true;
    }

}

bool PiezoMotor::set_position(int position){
    // The command to run the motor based on serial protocol
    std::string buffer = "X1T" + std::to_string(position) + "1000" + "\r";
    int bytes_sent = write(fd_, buffer.c_str(), buffer.size());

    if (bytes_sent < 0) {
        std::cerr << "Error " << errno << " from write: " << strerror(errno) << std::endl;
        return false;
    } else {
        std::cout << "Command sent to the motor controller." << std::endl;
        return true;
    }
}

int PiezoMotor::stop(){
    // The command to stop the motor controller based on serial protocol
    std::string command = "X1S\r";

    // Writing to the serial port
    int bytes_sent = write(fd_, command.c_str(), command.size());

    if (bytes_sent < 0) {
        std::cerr << "Error " << errno << " from write: " << strerror(errno) << std::endl;
    } else {
        std::cout << "Command sent to the motor controller." << std::endl;
    }

    return bytes_sent;
}

std::string PiezoMotor::read_position(){
    float position = 0;
    int available_bytes;

    std::string response="";

    const std::string command = "X1E\r";
    ssize_t bytes_written = write(fd_, command.c_str(), command.length());

    if (bytes_written < 0) {
        std::cerr << "Error writing to serial port" << std::endl;
    }

    char buffer[15];
    memset(buffer, '\0', sizeof(buffer));

    ssize_t num_bytes = read(fd_, buffer, sizeof(buffer));
    response = buffer;

    std::string substring = "X1E:";


    size_t pos = response.find(substring);

    // Check if the substring was found
    if (pos != std::string::npos) {
        // Erase the substring from the string
        response.erase(pos, substring.length());
    }


    std::chrono::milliseconds(200);

    return response;
}
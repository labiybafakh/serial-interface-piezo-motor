#include "piezeo_interface.hpp"


int main() {
    const char *portname = "/dev/ttyUSB0";
    int fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC); //open the serial port
    if (fd < 0) { 
        std::cout << "Error opening " << portname << ": " << strerror(errno) << std::endl;
        return -1;
    }

    struct termios tty;
    memset(&tty, 0, sizeof tty);
    if (tcgetattr(fd, &tty) != 0) {
        std::cout << "Error from tcgetattr: " << strerror(errno) << std::endl;
        return -1;
    }

    // Set baud rate read and write
    cfsetospeed(&tty, B115200); 
    cfsetispeed(&tty, B115200);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    tty.c_cflag &= ~(PARENB | PARODD);              // No parity
    tty.c_cflag &= ~CSTOPB;                         // 1 stop bit
    tty.c_cflag &= ~CRTSCTS;                        // No hardware flow control

    if (tcsetattr(fd, TCSANOW, &tty) != 0) {
        std::cout << "Error from tcsetattr: " << strerror(errno) << std::endl;
        return -1;
    }

    target_position(fd, 1000, 1000);
    sleep(3); //sleep for 3 seconds
    target_position(fd, -1000, 1000);
    sleep(3);
    stop(fd);

    close(fd);
    return 0;
}

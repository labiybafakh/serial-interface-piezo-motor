#include "piezeo_interface.hpp"


int main(int argc, const char * argv[]) {

    std::string portname = argv[1];
    std::cout << "Serial port: " << portname << std::endl; 

    PiezoMotor motor(portname);
    sleep(5);

    std::string data = motor.read_position();

    std::cout << "Position:  "<< motor.read_position() << std::endl;

 

    return 0;
}

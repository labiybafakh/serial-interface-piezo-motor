#include "piezeo_interface.hpp"


int main(int argc, const char * argv[]) {

    std::string portname = argv[1];
    std::cout << "Serial port: " << portname << std::endl; 

    PiezoMotor motor(portname);
    sleep(5);

    // std::string data = motor.read_position();

    // std::cout << "Position:  "<< motor.read_position() << std::endl;

    int run = 1000;
    int run_b = -1000;
    int step = 1000;
    motor.set_position(0);
    // sleep(3);
    // motor.read_position();
    // sleep(3);
    // motor.move_step(run, step);
    // motor.read_position();
    // sleep(3);
    // motor.move_step(run_b, step);
    // motor.read_position();
    // sleep(3);

    // sleep(3); //sleep for 3 seconds
    // std::cout << "Position:  "<< motor.read_position() << std::endl;
    // motor.target_position(run_b, step);
    // sleep(3);
    // motor.stop();
    // std::cout << "Position:  "<< motor.read_position() << std::endl;

    return 0;
}

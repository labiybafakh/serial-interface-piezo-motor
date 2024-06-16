#ifndef piezo_interface_hpp
#define piezo_interface_hpp

#include <iostream>
#include <fcntl.h>    
#include <errno.h>    
#include <termios.h>  
#include <unistd.h>   
#include <string.h> 
#include <string>
#include <sys/ioctl.h>
#include <cstring>


class PiezoMotor{
    private:
        const char* serial_port_;
        struct termios options;
        int fd_;

    public:
        PiezoMotor(std::string &serial_port);
        ~PiezoMotor();
        bool set_position(int position);
        int stop();
        // int target_position(int &position, int &step);
        bool move_step(int &n_step, int &freq);
        std::string read_position();

};


#endif
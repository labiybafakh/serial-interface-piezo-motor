#ifndef piezo_interface_hpp
#define piezo_interface_hpp

#include <iostream>
#include <fcntl.h>    
#include <errno.h>    
#include <termios.h>  
#include <unistd.h>   
#include <string.h> 

std::string set_position(int position, int step);
int stop(int port);
int target_position(int port, int position, int step);

#endif
# serial-interface-piezo-motor

This repository is used to control a Piezo Motor using Piezo LEGS Controller PMD401.

The interface is based on [this technical manual](https://piezomotor.com/wp-content/uploads/2023/03/150025_PMD401_Technical_Manual.pdf)

## Build
```bash
mkdir build
cmake ..
cmake --build .
```

## Run
```bash
./serial_interface_piezo_motor 
```
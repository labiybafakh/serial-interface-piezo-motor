# serial-interface-piezo-motor

This repository is used to control a Piezo Motor using Piezo LEGS Controller PMD401.

The interface is based on [this technical manual](https://piezomotor.com/wp-content/uploads/2023/03/150025_PMD401_Technical_Manual.pdf)

## Install Clang
```bash
sudo apt-get update && sudo apt-get install -y clang libc++-dev libc++abi-dev
```

## Build
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

## Run
```bash
./serial_interface_piezo_motor 
```
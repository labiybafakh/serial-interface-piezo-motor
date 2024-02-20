#include <cassert>
#include "piezeo_interface.hpp"

void test_protocol_concatenate() {
    // Test case 1: Normal inputs
    assert(set_position(1000, 600) == "X1J1000,0,600\r" && "set_position with positive position and step failed");

    // Test case 2: Negative inputs
    assert(set_position(-1000, -600) == "X1J-1000,0,-600\r" && "set_position with negative position and step failed");

    // Test case 3: Zero inputs
    assert(set_position(0, 0) == "X1J0,0,0\r" && "set_position with zero position and step failed");

    std::cout << "All tests passed." << std::endl;
}

int main() {
    test_protocol_concatenate();

    return 0;
}
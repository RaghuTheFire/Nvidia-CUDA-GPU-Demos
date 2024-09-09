#include <iostream>
#include <cuda_runtime.h>

void checkBandwidth() 
{
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    
    for (int device = 0; device < deviceCount; ++device) 
    {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, device);
        
        std::cout << "Device " << device << ": " << prop.name << std::endl;
        std::cout << "Memory Bandwidth (GB/s): " << prop.memoryClockRate * prop.memoryBusWidth / 8.0e6 << std::endl;
    }
}

int main() 
{
    checkBandwidth();
    return 0;
}



# CPUvsGPUBenchMark.cpp
This C++ code is designed to check and display the memory bandwidth of CUDA-capable devices (typically GPUs) in a system. 
Here's a breakdown of what the code does: 
1. The code includes necessary headers: iostream for input/output operations and cuda_runtime.h for CUDA-related functions.
2. A function called checkBandwidth() is defined:
- It first gets the count of CUDA devices in the system using cudaGetDeviceCount().
- Then, it loops through each device.
- For each device, it retrieves the device properties using cudaGetDeviceProperties().
- It prints the device number and name.
- It calculates and prints the memory bandwidth in GB/s using the formula: (memory clock rate * memory bus width) / 8.0e6
3. The main() function simply calls checkBandwidth() and then returns 0. When run, this program will list all CUDA-capable devices in the system along with their names and calculated memory bandwidths. This information can be useful for developers working on CUDA applications to understand the capabilities of the available hardware.

# Compilation command:
# nvcc -o CPUvsGPUBenchMark CPUvsGPUBenchMark.cpp


# CputoGpuBandWidth.cpp
This C++ code is designed to check and display the memory bandwidth of CUDA-capable devices (typically NVIDIA GPUs) on the system. Here's a breakdown of what the code does: 
1. The code includes necessary headers: iostream for input/output operations and cuda_runtime.h for CUDA-related functions.
2. A function called `checkBandwidth()` is defined:
- It first gets the count of CUDA devices available on the system using `cudaGetDeviceCount()`.
- Then, it loops through each device. - For each device, it retrieves the device properties using `cudaGetDeviceProperties()`.
- It prints the device number and name.
- It calculates and prints the memory bandwidth in GB/s using the formula: (memory clock rate * memory bus width) / (8 * 10^6)
3. The `main()` function simply calls the `checkBandwidth()` function and returns 0. When executed, this program will list all CUDA-capable devices on the system along with their names and calculated memory bandwidths. This information can be useful for developers working on CUDA applications to understand the capabilities of the available hardware.

# Compilation command:
# nvcc -o CputoGpuBandWidth CputoGpuBandWidth.cpp





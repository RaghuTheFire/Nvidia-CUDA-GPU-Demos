#include <iostream>
#include <cuda.h>

#define N 4194304

__global__ void sumArraysKernel(float *a, float *b, float *c, float *result) 
{
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < N) 
    {
        result[idx] = a[idx] + b[idx] + c[idx];
    }
}

void sumArraysCPU(float *a, float *b, float *c, float *result) 
{
    for (int i = 0; i < N; i++) 
    {
        result[i] = a[i] + b[i] + c[i];
    }
}

int main() 
{
    float *h_a, *h_b, *h_c, *h_result;
    float *d_a, *d_b, *d_c, *d_result;

    size_t size = N * sizeof(float);

    h_a = (float *)malloc(size);
    h_b = (float *)malloc(size);
    h_c = (float *)malloc(size);
    h_result = (float *)malloc(size);

    for (int i = 0; i < N; i++) 
    {
        h_a[i] = static_cast<float>(i);
        h_b[i] = static_cast<float>(i * 2);
        h_c[i] = static_cast<float>(i * 3);
    }

    cudaMalloc(&d_a, size);
    cudaMalloc(&d_b, size);
    cudaMalloc(&d_c, size);
    cudaMalloc(&d_result, size);

    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_c, h_c, size, cudaMemcpyHostToDevice);

    int blockSize = 256;
    int numBlocks = (N + blockSize - 1) / blockSize;
    sumArraysKernel<<<numBlocks, blockSize>>>(d_a, d_b, d_c, d_result);

    cudaMemcpy(h_result, d_result, size, cudaMemcpyDeviceToHost);

    sumArraysCPU(h_a, h_b, h_c, h_result);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    cudaFree(d_result);
    free(h_a);
    free(h_b);
    free(h_c);
    free(h_result);

    return 0;
}


#include <CL/cl.h>  // or <CL/opencl.h>
#include <stdio.h>

int main() {
    cl_uint num_platforms;
    clGetPlatformIDs(0, NULL, &num_platforms);
    printf("Detected %d OpenCL platforms\n", num_platforms);
    return 0;
}
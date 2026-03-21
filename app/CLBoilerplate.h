#pragma once

#include <CL/cl.h>

class CLBoilerplate {
public:
    //constructor
    CLBoilerplate();
    //destructor
    ~CLBoilerplate();

    //checks the device
    void printDevice() const;

    //returns the GPU 
    cl_device_id device() const { return device_; }

private:
    cl_platform_id   platform_{};//Vendor
    cl_device_id     device_{};//GPU
    cl_context       context_{};//CPU-GPU environment
    cl_command_queue queue_{};//command queue
    cl_program       program_{};//compiled kernel
    cl_kernel        kernel_{};//GPU function

};

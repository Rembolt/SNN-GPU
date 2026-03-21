#include "CLBoilerplate.h"

#include <iostream>
#include <stdexcept>


namespace {

// cl_int getDevice(cl_platform_id platform, cl_device_id& outDevice) {
    
//     return clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &outDevice, nullptr);
// }

}  // namespace

CLBoilerplate::CLBoilerplate() {
    cl_int err = clGetPlatformIDs(1, &platform_, nullptr);
    if (err != CL_SUCCESS || !platform_) {
        throw std::runtime_error("clGetPlatformIDs failed");
    }

    err = clGetDeviceIDs(platform_, CL_DEVICE_TYPE_GPU, 1, &device_, nullptr);
    if (err != CL_SUCCESS || !device_) {
        throw std::runtime_error("No OpenCL device (GPU or CPU) found");
    }

    context_ = clCreateContext(nullptr, 1, &device_, nullptr, nullptr, &err);
    if (err != CL_SUCCESS || !context_) {
        throw std::runtime_error("clCreateContext failed");
    }

    queue_ = clCreateCommandQueueWithProperties(context_, device_, nullptr, &err);
    if (err != CL_SUCCESS || !queue_) {
        clReleaseContext(context_);
        context_ = nullptr;
        throw std::runtime_error("clCreateCommandQueueWithProperties failed");
    }
}


void CLBoilerplate::printDevice() const {
    if (!device_) {
        std::cout << "No OpenCL device.\n";
        return;
    }

    char buf[1024];
    size_t len = 0;

    if (clGetDeviceInfo(device_, CL_DEVICE_NAME, sizeof(buf), buf, &len) == CL_SUCCESS) {
        std::cout << "Device name: " << buf << '\n';
    }

    if (clGetDeviceInfo(device_, CL_DEVICE_VENDOR, sizeof(buf), buf, &len) == CL_SUCCESS) {
        std::cout << "Vendor:      " << buf << '\n';
    }

    if (clGetDeviceInfo(device_, CL_DEVICE_VERSION, sizeof(buf), buf, &len) == CL_SUCCESS) {
        std::cout << "OpenCL:      " << buf << '\n';
    }
}

CLBoilerplate::~CLBoilerplate() {
    if (kernel_) {
        clReleaseKernel(kernel_);
    }
    if (program_) {
        clReleaseProgram(program_);
    }
    if (queue_) {
        clReleaseCommandQueue(queue_);
    }
    if (context_) {
        clReleaseContext(context_);
    }
}

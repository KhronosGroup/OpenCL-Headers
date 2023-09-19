#include <CL/cl.h>

int main(void) { return sizeof(cl_platform_id) - sizeof(cl_context); }

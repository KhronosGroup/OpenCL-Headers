#include <CL/cl.h>

int main()
{
    return sizeof(cl_platform_id) - sizeof(cl_context);
}

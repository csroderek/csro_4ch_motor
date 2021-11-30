#include "test.h"

ExtU_test_T test_U;
ExtY_test_T test_Y;
void test_step(void)
{
    int32_T i;
    test_Y.Outport.btn[0] = (int8_T)sys_regs.inputs[0];
    test_Y.Outport.btn[1] = (int8_T)sys_regs.inputs[1];
    for (i = 0; i < 5; i++)
    {
        test_Y.Outport.com[i] = (int8_T)sys_regs.inputs[i + 2];
        test_Y.Outport.rmt[i] = (int8_T)sys_regs.inputs[i + 7];
    }
}

void test_initialize(void)
{
}

void test_terminate(void)
{
}

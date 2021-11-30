#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include "rtwtypes.h"
#include "mb_config.h"
#ifndef test_COMMON_INCLUDES_
#define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "fnd_com.h"

#ifndef DEFINED_TYPEDEF_FOR_ch_signal_
#define DEFINED_TYPEDEF_FOR_ch_signal_

typedef struct
{
    int8_T btn[2];
    int8_T com[5];
    int8_T rmt[5];
}
ch_signal;

#endif

typedef struct
{
    ch_signal Inport[4];
}
ExtU_test_T;

typedef struct
{
    ch_signal Outport;
}
ExtY_test_T;

extern ExtU_test_T test_U;
extern ExtY_test_T test_Y;
extern void test_initialize(void);
extern void test_step(void);
extern void test_terminate(void);

#endif

#ifndef RTW_HEADER_change_watcher_h_
#define RTW_HEADER_change_watcher_h_
#ifndef change_watcher_COMMON_INCLUDES_
#define change_watcher_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

typedef struct
{
    uint32_T Delay_DSTATE;
    int16_T DelayInput1_DSTATE;
}
DW_change_watcher_f_T;

typedef struct
{
    DW_change_watcher_f_T rtdw;
}
MdlrefDW_change_watcher_T;

extern void change_watcher(const int16_T *rtu_value_in, boolean_T *rty_changed, int16_T *rty_new_value, DW_change_watcher_f_T *localDW);

#endif

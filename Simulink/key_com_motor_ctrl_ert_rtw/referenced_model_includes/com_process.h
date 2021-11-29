#ifndef RTW_HEADER_com_process_h_
#define RTW_HEADER_com_process_h_
#ifndef com_process_COMMON_INCLUDES_
#define com_process_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

extern void com_process(const int16_T *rtu_ch_com, const int16_T *rtu_group_com, const int16_T *rtu_ch_rmt, const int16_T *rtu_group_rmt,
                        const int16_T *rtu_com_only, int16_T *rty_ch_com_signal);

#endif

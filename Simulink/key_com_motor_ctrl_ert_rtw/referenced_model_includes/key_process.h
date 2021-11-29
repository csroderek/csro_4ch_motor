#ifndef RTW_HEADER_key_process_h_
#define RTW_HEADER_key_process_h_
#ifndef key_process_COMMON_INCLUDES_
#define key_process_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

extern void key_process(const int16_T *rtu_ch_key, const int16_T *rtu_group_key, const int16_T *rtu_com_only, int16_T *rty_key_signal);

#endif

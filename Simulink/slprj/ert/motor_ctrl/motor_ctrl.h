#ifndef RTW_HEADER_motor_ctrl_h_
#define RTW_HEADER_motor_ctrl_h_
#ifndef motor_ctrl_COMMON_INCLUDES_
#define motor_ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

typedef struct
{
    int32_T sfEvent;
    uint16_T temporalCounter_i1;
    uint16_T temporalCounter_i2;
    uint16_T temporalCounter_i3;
    uint8_T is_active_c3_motor_ctrl;
    uint8_T is_c3_motor_ctrl;
    uint8_T is_COM_CMD;
    uint8_T is_active_COM_CMD;
    uint8_T is_KEY_CMD;
    uint8_T is_active_KEY_CMD;
    uint8_T is_DOWN_KEY_PRESSED;
    uint8_T is_UP_KEY_PRESSED;
    uint8_T is_MOTOR;
    uint8_T is_active_MOTOR;
}
DW_motor_ctrl_f_T;

typedef struct
{
    DW_motor_ctrl_f_T rtdw;
}
MdlrefDW_motor_ctrl_T;

extern void motor_ctrl_Init(DW_motor_ctrl_f_T *localDW);
extern void motor_ctrl(const int16_T *rtu_up_key, const int16_T *rtu_down_key, const int16_T *rtu_com_short_up, const int16_T
                       *rtu_com_long_up, const int16_T *rtu_com_stop, const int16_T *rtu_com_short_down, const int16_T *rtu_com_long_down,
                       const int16_T *rtu_debounce_cnt, const int16_T *rtu_longpress_cnt, const int16_T *rtu_long_cnt, const int16_T
                       *rtu_short_cnt, const int16_T *rtu_transfer_cnt, int16_T *rty_up_relay, int16_T *rty_down_relay, DW_motor_ctrl_f_T
                       *localDW);

#endif

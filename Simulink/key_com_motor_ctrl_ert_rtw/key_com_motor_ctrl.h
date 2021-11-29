#ifndef RTW_HEADER_key_com_motor_ctrl_h_
#define RTW_HEADER_key_com_motor_ctrl_h_
#include "mb_config.h"
#ifndef key_com_motor_ctrl_COMMON_INCLUDES_
#define key_com_motor_ctrl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "key_process.h"
#include "com_process.h"
#include "motor_ctrl.h"

#include "fnd_com.h"

typedef struct
{
    int16_T relay1;
    int16_T relay2;
    int16_T relay3;
    int16_T relay4;
    int16_T relay5;
    int16_T relay6;
    int16_T relay7;
    int16_T relay8;
}
B_key_com_motor_ctrl_T;

typedef struct
{
    MdlrefDW_motor_ctrl_T channel1_InstanceData;
    MdlrefDW_motor_ctrl_T channel2_InstanceData;
    MdlrefDW_motor_ctrl_T channel3_InstanceData;
    MdlrefDW_motor_ctrl_T channel4_InstanceData;
}
DW_key_com_motor_ctrl_T;

extern B_key_com_motor_ctrl_T key_com_motor_ctrl_B;
extern DW_key_com_motor_ctrl_T key_com_motor_ctrl_DW;
extern int16_T relay[8];
extern void key_com_motor_ctrl_initialize(void);
extern void key_com_motor_ctrl_step(void);
extern void key_com_motor_ctrl_terminate(void);

#endif

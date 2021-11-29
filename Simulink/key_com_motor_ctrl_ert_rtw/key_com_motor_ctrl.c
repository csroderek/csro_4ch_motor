#include "key_com_motor_ctrl.h"

int16_T relay[8];
B_key_com_motor_ctrl_T key_com_motor_ctrl_B;
DW_key_com_motor_ctrl_T key_com_motor_ctrl_DW;
void key_com_motor_ctrl_step(void)
{
    int16_T rtb_key1;
    int16_T rtb_key2;
    int16_T rtb_ch1_com_short_up;
    int16_T rtb_ch1_com_long_up;
    int16_T rtb_ch1_com_stop;
    int16_T rtb_ch1_com_short_down;
    int16_T rtb_ch1_com_long_down;
    int16_T rtb_key3;
    int16_T rtb_key4;
    int16_T rtb_ch2_com_short_up;
    int16_T rtb_ch2_com_long_up;
    int16_T rtb_ch2_com_stop;
    int16_T rtb_ch2_com_short_down;
    int16_T rtb_ch2_com_long_down;
    int16_T rtb_key5;
    int16_T rtb_key6;
    int16_T rtb_ch3_com_short_up;
    int16_T rtb_ch3_com_long_up;
    int16_T rtb_ch3_com_stop;
    int16_T rtb_ch3_com_short_down;
    int16_T rtb_ch3_com_long_down;
    int16_T rtb_key7;
    int16_T rtb_key8;
    int16_T rtb_ch4_com_short_up;
    int16_T rtb_ch4_com_long_up;
    int16_T rtb_ch4_com_stop;
    int16_T rtb_ch4_com_short_down;
    int16_T rtb_ch4_com_long_down;
    key_process((&(sys_regs.inputs[100])), (&(sys_regs.inputs[108])), (&(sys_regs.holdings[37])), &rtb_key1);
    key_process((&(sys_regs.inputs[101])), (&(sys_regs.inputs[109])), (&(sys_regs.holdings[37])), &rtb_key2);
    com_process((&(sys_regs.holdings[110])), (&(sys_regs.holdings[130])), (&(sys_regs.inputs[120])), (&(sys_regs.inputs[140])),
                (&(sys_regs.holdings[37])), &rtb_ch1_com_short_up);
    com_process((&(sys_regs.holdings[111])), (&(sys_regs.holdings[131])), (&(sys_regs.inputs[121])), (&(sys_regs.inputs[141])),
                (&(sys_regs.holdings[37])), &rtb_ch1_com_long_up);
    com_process((&(sys_regs.holdings[112])), (&(sys_regs.holdings[132])), (&(sys_regs.inputs[122])), (&(sys_regs.inputs[142])),
                (&(sys_regs.holdings[37])), &rtb_ch1_com_stop);
    com_process((&(sys_regs.holdings[113])), (&(sys_regs.holdings[133])), (&(sys_regs.inputs[123])), (&(sys_regs.inputs[143])),
                (&(sys_regs.holdings[37])), &rtb_ch1_com_short_down);
    com_process((&(sys_regs.holdings[114])), (&(sys_regs.holdings[134])), (&(sys_regs.inputs[124])), (&(sys_regs.inputs[144])),
                (&(sys_regs.holdings[37])), &rtb_ch1_com_long_down);
    motor_ctrl(&rtb_key1, &rtb_key2, &rtb_ch1_com_short_up, &rtb_ch1_com_long_up, &rtb_ch1_com_stop, &rtb_ch1_com_short_down,
               &rtb_ch1_com_long_down, (&(sys_regs.holdings[100])), (&(sys_regs.holdings[101])), (&(sys_regs.holdings[102])),
               (&(sys_regs.holdings[103])), (&(sys_regs.holdings[104])), &key_com_motor_ctrl_B.relay1, &key_com_motor_ctrl_B.relay2,
               &(key_com_motor_ctrl_DW.channel1_InstanceData.rtdw));
    relay[0] = key_com_motor_ctrl_B.relay1;
    relay[1] = key_com_motor_ctrl_B.relay2;
    key_process((&(sys_regs.inputs[102])), (&(sys_regs.inputs[108])), (&(sys_regs.holdings[37])), &rtb_key3);
    key_process((&(sys_regs.inputs[103])), (&(sys_regs.inputs[109])), (&(sys_regs.holdings[37])), &rtb_key4);
    com_process((&(sys_regs.holdings[115])), (&(sys_regs.holdings[130])), (&(sys_regs.inputs[125])), (&(sys_regs.inputs[140])),
                (&(sys_regs.holdings[37])), &rtb_ch2_com_short_up);
    com_process((&(sys_regs.holdings[116])), (&(sys_regs.holdings[131])), (&(sys_regs.inputs[126])), (&(sys_regs.inputs[141])),
                (&(sys_regs.holdings[37])), &rtb_ch2_com_long_up);
    com_process((&(sys_regs.holdings[117])), (&(sys_regs.holdings[132])), (&(sys_regs.inputs[127])), (&(sys_regs.inputs[142])),
                (&(sys_regs.holdings[37])), &rtb_ch2_com_stop);
    com_process((&(sys_regs.holdings[118])), (&(sys_regs.holdings[133])), (&(sys_regs.inputs[128])), (&(sys_regs.inputs[143])),
                (&(sys_regs.holdings[37])), &rtb_ch2_com_short_down);
    com_process((&(sys_regs.holdings[119])), (&(sys_regs.holdings[134])), (&(sys_regs.inputs[129])), (&(sys_regs.inputs[144])),
                (&(sys_regs.holdings[37])), &rtb_ch2_com_long_down);
    motor_ctrl(&rtb_key3, &rtb_key4, &rtb_ch2_com_short_up, &rtb_ch2_com_long_up, &rtb_ch2_com_stop, &rtb_ch2_com_short_down,
               &rtb_ch2_com_long_down, (&(sys_regs.holdings[100])), (&(sys_regs.holdings[101])), (&(sys_regs.holdings[102])),
               (&(sys_regs.holdings[103])), (&(sys_regs.holdings[104])), &key_com_motor_ctrl_B.relay3, &key_com_motor_ctrl_B.relay4,
               &(key_com_motor_ctrl_DW.channel2_InstanceData.rtdw));
    relay[2] = key_com_motor_ctrl_B.relay3;
    relay[3] = key_com_motor_ctrl_B.relay4;
    key_process((&(sys_regs.inputs[104])), (&(sys_regs.inputs[108])), (&(sys_regs.holdings[37])), &rtb_key5);
    key_process((&(sys_regs.inputs[105])), (&(sys_regs.inputs[109])), (&(sys_regs.holdings[37])), &rtb_key6);
    com_process((&(sys_regs.holdings[120])), (&(sys_regs.holdings[130])), (&(sys_regs.inputs[130])), (&(sys_regs.inputs[140])),
                (&(sys_regs.holdings[37])), &rtb_ch3_com_short_up);
    com_process((&(sys_regs.holdings[121])), (&(sys_regs.holdings[131])), (&(sys_regs.inputs[131])), (&(sys_regs.inputs[141])),
                (&(sys_regs.holdings[37])), &rtb_ch3_com_long_up);
    com_process((&(sys_regs.holdings[122])), (&(sys_regs.holdings[132])), (&(sys_regs.inputs[132])), (&(sys_regs.inputs[142])),
                (&(sys_regs.holdings[37])), &rtb_ch3_com_stop);
    com_process((&(sys_regs.holdings[123])), (&(sys_regs.holdings[133])), (&(sys_regs.inputs[133])), (&(sys_regs.inputs[143])),
                (&(sys_regs.holdings[37])), &rtb_ch3_com_short_down);
    com_process((&(sys_regs.holdings[124])), (&(sys_regs.holdings[134])), (&(sys_regs.inputs[134])), (&(sys_regs.inputs[144])),
                (&(sys_regs.holdings[37])), &rtb_ch3_com_long_down);
    motor_ctrl(&rtb_key5, &rtb_key6, &rtb_ch3_com_short_up, &rtb_ch3_com_long_up, &rtb_ch3_com_stop, &rtb_ch3_com_short_down,
               &rtb_ch3_com_long_down, (&(sys_regs.holdings[100])), (&(sys_regs.holdings[101])), (&(sys_regs.holdings[102])),
               (&(sys_regs.holdings[103])), (&(sys_regs.holdings[104])), &key_com_motor_ctrl_B.relay5, &key_com_motor_ctrl_B.relay6,
               &(key_com_motor_ctrl_DW.channel3_InstanceData.rtdw));
    relay[4] = key_com_motor_ctrl_B.relay5;
    relay[5] = key_com_motor_ctrl_B.relay6;
    key_process((&(sys_regs.inputs[106])), (&(sys_regs.inputs[108])), (&(sys_regs.holdings[37])), &rtb_key7);
    key_process((&(sys_regs.inputs[107])), (&(sys_regs.inputs[109])), (&(sys_regs.holdings[37])), &rtb_key8);
    com_process((&(sys_regs.holdings[125])), (&(sys_regs.holdings[130])), (&(sys_regs.inputs[135])), (&(sys_regs.inputs[140])),
                (&(sys_regs.holdings[37])), &rtb_ch4_com_short_up);
    com_process((&(sys_regs.holdings[126])), (&(sys_regs.holdings[131])), (&(sys_regs.inputs[136])), (&(sys_regs.inputs[141])),
                (&(sys_regs.holdings[37])), &rtb_ch4_com_long_up);
    com_process((&(sys_regs.holdings[127])), (&(sys_regs.holdings[132])), (&(sys_regs.inputs[137])), (&(sys_regs.inputs[142])),
                (&(sys_regs.holdings[37])), &rtb_ch4_com_stop);
    com_process((&(sys_regs.holdings[128])), (&(sys_regs.holdings[133])), (&(sys_regs.inputs[138])), (&(sys_regs.inputs[143])),
                (&(sys_regs.holdings[37])), &rtb_ch4_com_short_down);
    com_process((&(sys_regs.holdings[129])), (&(sys_regs.holdings[134])), (&(sys_regs.inputs[139])), (&(sys_regs.inputs[144])),
                (&(sys_regs.holdings[37])), &rtb_ch4_com_long_down);
    motor_ctrl(&rtb_key7, &rtb_key8, &rtb_ch4_com_short_up, &rtb_ch4_com_long_up, &rtb_ch4_com_stop, &rtb_ch4_com_short_down,
               &rtb_ch4_com_long_down, (&(sys_regs.holdings[100])), (&(sys_regs.holdings[101])), (&(sys_regs.holdings[102])),
               (&(sys_regs.holdings[103])), (&(sys_regs.holdings[104])), &key_com_motor_ctrl_B.relay7, &key_com_motor_ctrl_B.relay8,
               &(key_com_motor_ctrl_DW.channel4_InstanceData.rtdw));
    relay[6] = key_com_motor_ctrl_B.relay7;
    relay[7] = key_com_motor_ctrl_B.relay8;
}

void key_com_motor_ctrl_initialize(void)
{
    motor_ctrl_Init(&(key_com_motor_ctrl_DW.channel1_InstanceData.rtdw));
    motor_ctrl_Init(&(key_com_motor_ctrl_DW.channel2_InstanceData.rtdw));
    motor_ctrl_Init(&(key_com_motor_ctrl_DW.channel3_InstanceData.rtdw));
    motor_ctrl_Init(&(key_com_motor_ctrl_DW.channel4_InstanceData.rtdw));
    sys_regs.holdings[100] = 2;
    sys_regs.holdings[101] = 100;
    sys_regs.holdings[102] = 3000;
    sys_regs.holdings[103] = 20;
    sys_regs.holdings[104] = 50;
}

void key_com_motor_ctrl_terminate(void)
{
}

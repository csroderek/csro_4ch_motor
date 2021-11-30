#include "param_monitor.h"
#include "div_nde_s32_floor.h"

DW_param_monitor_T param_monitor_DW;
void param_monitor_step(void)
{
    int16_T rtb_Model_o2;
    int16_T rtb_Model1_o2;
    int16_T rtb_Model2_o2;
    int16_T rtb_Model3_o2;
    int16_T rtb_Model4_o2;
    boolean_T rtb_Model_o1;
    boolean_T rtb_Model1_o1;
    boolean_T rtb_Model2_o1;
    boolean_T rtb_Model3_o1;
    boolean_T rtb_Model4_o1;
    int16_T rtb_DataStoreRead4;
    rtb_DataStoreRead4 = sys_regs.holdings[100];
    change_watcher(&rtb_DataStoreRead4, &rtb_Model_o1, &rtb_Model_o2, &(param_monitor_DW.Model_InstanceData.rtdw));
    rtb_DataStoreRead4 = sys_regs.holdings[101];
    change_watcher(&rtb_DataStoreRead4, &rtb_Model1_o1, &rtb_Model1_o2, &(param_monitor_DW.Model1_InstanceData.rtdw));
    rtb_DataStoreRead4 = sys_regs.holdings[102];
    change_watcher(&rtb_DataStoreRead4, &rtb_Model2_o1, &rtb_Model2_o2, &(param_monitor_DW.Model2_InstanceData.rtdw));
    rtb_DataStoreRead4 = sys_regs.holdings[103];
    change_watcher(&rtb_DataStoreRead4, &rtb_Model3_o1, &rtb_Model3_o2, &(param_monitor_DW.Model3_InstanceData.rtdw));
    rtb_DataStoreRead4 = sys_regs.holdings[104];
    change_watcher(&rtb_DataStoreRead4, &rtb_Model4_o1, &rtb_Model4_o2, &(param_monitor_DW.Model4_InstanceData.rtdw));
    if (rtb_Model_o1 || rtb_Model1_o1 || rtb_Model2_o1 || rtb_Model3_o1 || rtb_Model4_o1)
    {
        ee_ram[0] = (uint8_T)((real_T)rtb_Model_o2 / 256.0);
        ee_ram[1] = (uint8_T)(rtb_Model_o2 - (int16_T)((int16_T)div_nde_s32_floor(rtb_Model_o2, 256) << 8));
        ee_ram[2] = (uint8_T)((real_T)rtb_Model1_o2 / 256.0);
        ee_ram[3] = (uint8_T)(rtb_Model1_o2 - (int16_T)((int16_T)div_nde_s32_floor(rtb_Model1_o2, 256) << 8));
        ee_ram[4] = (uint8_T)((real_T)rtb_Model2_o2 / 256.0);
        ee_ram[5] = (uint8_T)(rtb_Model2_o2 - (int16_T)((int16_T)div_nde_s32_floor(rtb_Model2_o2, 256) << 8));
        ee_ram[6] = (uint8_T)((real_T)rtb_Model3_o2 / 256.0);
        ee_ram[7] = (uint8_T)(rtb_Model3_o2 - (int16_T)((int16_T)div_nde_s32_floor(rtb_Model3_o2, 256) << 8));
        ee_ram[8] = (uint8_T)((real_T)rtb_Model4_o2 / 256.0);
        ee_ram[9] = (uint8_T)(rtb_Model4_o2 - (int16_T)((int16_T)div_nde_s32_floor(rtb_Model4_o2, 256) << 8));
        ee_save_params();
    }
}

void param_monitor_initialize(void)
{
    sys_regs.holdings[100] = (int16_T)((int16_T)(ee_ram[0] << 8) + ee_ram[1]);
    sys_regs.holdings[101] = (int16_T)((int16_T)(ee_ram[2] << 8) + ee_ram[3]);
    sys_regs.holdings[102] = (int16_T)((int16_T)(ee_ram[4] << 8) + ee_ram[5]);
    sys_regs.holdings[103] = (int16_T)((int16_T)(ee_ram[6] << 8) + ee_ram[7]);
    sys_regs.holdings[104] = (int16_T)((int16_T)(ee_ram[8] << 8) + ee_ram[9]);
}

void param_monitor_terminate(void)
{
}

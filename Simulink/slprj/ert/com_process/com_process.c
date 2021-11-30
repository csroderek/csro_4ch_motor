#include "com_process.h"

void com_process(const int16_T *rtu_ch_com, const int16_T *rtu_group_com, const int16_T *rtu_ch_rmt, const int16_T *rtu_group_rmt, const
                 int16_T *rtu_com_only, int16_T *rty_ch_com_signal)
{
    boolean_T rtb_DataTypeConversion4;
    boolean_T rtb_com_cmd;
    boolean_T rtb_com_rmt;
    rtb_DataTypeConversion4 = (*rtu_ch_com != 0);
    rtb_com_rmt = (*rtu_group_com != 0);
    rtb_com_cmd = (rtb_DataTypeConversion4 || rtb_com_rmt);
    rtb_com_rmt = (*rtu_ch_rmt != 0);
    rtb_DataTypeConversion4 = (*rtu_group_rmt != 0);
    rtb_DataTypeConversion4 = (rtb_com_rmt || rtb_DataTypeConversion4);
    rtb_com_rmt = (*rtu_com_only != 0);
    *rty_ch_com_signal = (int16_T)(rtb_com_cmd || (rtb_DataTypeConversion4 && (!rtb_com_rmt)));
}

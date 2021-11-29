#include "key_process.h"

void key_process(const int16_T *rtu_ch_key, const int16_T *rtu_group_key, const int16_T *rtu_com_only, int16_T *rty_key_signal)
{
    boolean_T rtb_AND;
    boolean_T rtb_DataTypeConversion38;
    rtb_DataTypeConversion38 = (*rtu_ch_key != 0);
    rtb_AND = (*rtu_group_key != 0);
    rtb_DataTypeConversion38 = (rtb_DataTypeConversion38 || rtb_AND);
    rtb_AND = (*rtu_com_only != 0);
    *rty_key_signal = (int16_T)(rtb_DataTypeConversion38 && (!rtb_AND));
}

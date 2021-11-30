#include "change_watcher.h"

void change_watcher(const int16_T *rtu_value_in, boolean_T *rty_changed, int16_T *rty_new_value, DW_change_watcher_f_T *localDW)
{
    boolean_T rtb_FixPtRelationalOperator;
    *rty_new_value = *rtu_value_in;
    rtb_FixPtRelationalOperator = (*rty_new_value != localDW->DelayInput1_DSTATE);
    localDW->Delay_DSTATE += rtb_FixPtRelationalOperator;
    *rty_changed = (rtb_FixPtRelationalOperator && (localDW->Delay_DSTATE > 1U));
    localDW->DelayInput1_DSTATE = *rty_new_value;
}

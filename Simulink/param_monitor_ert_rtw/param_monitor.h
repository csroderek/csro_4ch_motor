#ifndef RTW_HEADER_param_monitor_h_
#define RTW_HEADER_param_monitor_h_
#include "mb_config.h"
#ifndef param_monitor_COMMON_INCLUDES_
#define param_monitor_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif

#include "change_watcher.h"

#include "ee.h"
#include "fnd_com.h"
#include "ee_save_params.h"

typedef struct
{
    MdlrefDW_change_watcher_T Model_InstanceData;
    MdlrefDW_change_watcher_T Model1_InstanceData;
    MdlrefDW_change_watcher_T Model2_InstanceData;
    MdlrefDW_change_watcher_T Model3_InstanceData;
    MdlrefDW_change_watcher_T Model4_InstanceData;
}
DW_param_monitor_T;

extern DW_param_monitor_T param_monitor_DW;
extern void param_monitor_initialize(void);
extern void param_monitor_step(void);
extern void param_monitor_terminate(void);

#endif

#include "motor_ctrl.h"

#define motor_c_event_up_key_long_press (8)
#define motor_ct_event_short_down_event (4)
#define motor_ctr_event_long_down_event (2)
#define motor_ctrl_CALL_EVENT          (-1)
#define motor_ctrl_IN_DOWN_CLICK       ((uint8_T)1U)
#define motor_ctrl_IN_DOWN_DEBOUNCE    ((uint8_T)2U)
#define motor_ctrl_IN_DOWN_KEY_PRESSED ((uint8_T)1U)
#define motor_ctrl_IN_DOWN_LONGPRESS   ((uint8_T)3U)
#define motor_ctrl_IN_DOWN_TO_LONGUP   ((uint8_T)1U)
#define motor_ctrl_IN_IDLE             ((uint8_T)1U)
#define motor_ctrl_IN_IDLE_f           ((uint8_T)2U)
#define motor_ctrl_IN_LONG_DOWN        ((uint8_T)2U)
#define motor_ctrl_IN_LONG_UP          ((uint8_T)3U)
#define motor_ctrl_IN_MOTOR_CTRL       ((uint8_T)1U)
#define motor_ctrl_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define motor_ctrl_IN_OFF              ((uint8_T)4U)
#define motor_ctrl_IN_SHORT_DOWN       ((uint8_T)4U)
#define motor_ctrl_IN_SHORT_DOWN_c     ((uint8_T)5U)
#define motor_ctrl_IN_SHORT_UP         ((uint8_T)5U)
#define motor_ctrl_IN_SHORT_UP_g       ((uint8_T)6U)
#define motor_ctrl_IN_STOP             ((uint8_T)6U)
#define motor_ctrl_IN_UP_CLICK         ((uint8_T)1U)
#define motor_ctrl_IN_UP_DEBOUNCE      ((uint8_T)2U)
#define motor_ctrl_IN_UP_KEY_PRESSED   ((uint8_T)3U)
#define motor_ctrl_IN_UP_LONGPRESS     ((uint8_T)3U)
#define motor_ctrl_IN_UP_TO_LONGDOWN   ((uint8_T)7U)
#define motor_ctrl_event_down_key_click (0)
#define motor_ctrl_event_long_up_event (3)
#define motor_ctrl_event_short_up_event (5)
#define motor_ctrl_event_stop_event    (6)
#define motor_ctrl_event_up_key_click  (7)
#define motor_event_down_key_long_press (1)

static void motor_ctrl_MOTOR(const int16_T *Saturation9, const int16_T *Saturation10, const int16_T *Saturation11, int16_T *rty_up_relay,
    int16_T *rty_down_relay, DW_motor_ctrl_f_T *localDW);
static void motor_ctrl_MOTOR(const int16_T *Saturation9, const int16_T *Saturation10, const int16_T *Saturation11, int16_T *rty_up_relay,
    int16_T *rty_down_relay, DW_motor_ctrl_f_T *localDW)
{
    switch (localDW->is_MOTOR)
    {
      case motor_ctrl_IN_DOWN_TO_LONGUP:
        if (localDW->temporalCounter_i3 >= (uint16_T)*Saturation11)
        {
            localDW->is_MOTOR = motor_ctrl_IN_LONG_UP;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        break;

      case motor_ctrl_IN_LONG_DOWN:
        if ((localDW->sfEvent == motor_ctrl_event_down_key_click) || (localDW->sfEvent == motor_ctrl_event_up_key_click) ||
                (localDW->sfEvent == motor_ctrl_event_stop_event) || (localDW->temporalCounter_i3 >= (uint16_T)*Saturation9))
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_OFF;
        }
        else if ((localDW->sfEvent == motor_c_event_up_key_long_press) || (localDW->sfEvent == motor_ctrl_event_long_up_event))
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_DOWN_TO_LONGUP;
            localDW->temporalCounter_i3 = 0U;
        }
        break;

      case motor_ctrl_IN_LONG_UP:
        if ((localDW->sfEvent == motor_event_down_key_long_press) || (localDW->sfEvent == motor_ctr_event_long_down_event))
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_UP_TO_LONGDOWN;
            localDW->temporalCounter_i3 = 0U;
        }
        else if ((localDW->sfEvent == motor_ctrl_event_up_key_click) || (localDW->sfEvent == motor_ctrl_event_down_key_click) ||
                 (localDW->sfEvent == motor_ctrl_event_stop_event) || (localDW->temporalCounter_i3 >= (uint16_T)*Saturation9))
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_OFF;
        }
        break;

      case motor_ctrl_IN_OFF:
        if ((localDW->sfEvent == motor_ctrl_event_up_key_click) || (localDW->sfEvent == motor_ctrl_event_short_up_event))
        {
            localDW->is_MOTOR = motor_ctrl_IN_SHORT_UP_g;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        else if ((localDW->sfEvent == motor_c_event_up_key_long_press) || (localDW->sfEvent == motor_ctrl_event_long_up_event))
        {
            localDW->is_MOTOR = motor_ctrl_IN_LONG_UP;
            localDW->temporalCounter_i3 = 0U;
            *rty_up_relay = 1;
        }
        else if ((localDW->sfEvent == motor_ctrl_event_down_key_click) || (localDW->sfEvent == motor_ct_event_short_down_event))
        {
            localDW->is_MOTOR = motor_ctrl_IN_SHORT_DOWN_c;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        else if ((localDW->sfEvent == motor_event_down_key_long_press) || (localDW->sfEvent == motor_ctr_event_long_down_event))
        {
            localDW->is_MOTOR = motor_ctrl_IN_LONG_DOWN;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        break;

      case motor_ctrl_IN_SHORT_DOWN_c:
        if (localDW->temporalCounter_i3 >= (uint16_T)*Saturation10)
        {
            *rty_down_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_OFF;
        }
        break;

      case motor_ctrl_IN_SHORT_UP_g:
        if (localDW->temporalCounter_i3 >= (uint16_T)*Saturation10)
        {
            *rty_up_relay = 0;
            localDW->is_MOTOR = motor_ctrl_IN_OFF;
        }
        break;

      case motor_ctrl_IN_UP_TO_LONGDOWN:
        if (localDW->temporalCounter_i3 >= (uint16_T)*Saturation11)
        {
            localDW->is_MOTOR = motor_ctrl_IN_LONG_DOWN;
            localDW->temporalCounter_i3 = 0U;
            *rty_down_relay = 1;
        }
        break;
    }
}

void motor_ctrl_Init(DW_motor_ctrl_f_T *localDW)
{
    localDW->sfEvent = motor_ctrl_CALL_EVENT;
}

void motor_ctrl(const int16_T *rtu_up_key, const int16_T *rtu_down_key, const int16_T *rtu_com_short_up, const int16_T *rtu_com_long_up,
                const int16_T *rtu_com_stop, const int16_T *rtu_com_short_down, const int16_T *rtu_com_long_down, const int16_T
                *rtu_debounce_cnt, const int16_T *rtu_longpress_cnt, const int16_T *rtu_long_cnt, const int16_T *rtu_short_cnt, const
                int16_T *rtu_transfer_cnt, int16_T *rty_up_relay, int16_T *rty_down_relay, DW_motor_ctrl_f_T *localDW)
{
    int32_T h_previousEvent;
    int16_T Saturation;
    int16_T Saturation1;
    int16_T Saturation10;
    int16_T Saturation11;
    int16_T Saturation7;
    int16_T Saturation8;
    int16_T Saturation9;
    int16_T u0;
    int16_T u0_0;
    int16_T u0_1;
    int16_T u0_2;
    int16_T u0_3;
    Saturation = *rtu_up_key;
    if (Saturation > 1)
    {
        Saturation = 1;
    }
    else if (Saturation < 0)
    {
        Saturation = 0;
    }

    u0 = *rtu_com_short_up;
    u0_0 = *rtu_com_long_up;
    u0_1 = *rtu_com_stop;
    u0_2 = *rtu_com_short_down;
    Saturation1 = *rtu_down_key;
    if (Saturation1 > 1)
    {
        Saturation1 = 1;
    }
    else if (Saturation1 < 0)
    {
        Saturation1 = 0;
    }

    u0_3 = *rtu_com_long_down;
    Saturation7 = *rtu_debounce_cnt;
    if (Saturation7 > 4)
    {
        Saturation7 = 4;
    }
    else if (Saturation7 < 1)
    {
        Saturation7 = 1;
    }

    Saturation8 = *rtu_longpress_cnt;
    if (Saturation8 > 200)
    {
        Saturation8 = 200;
    }
    else if (Saturation8 < 50)
    {
        Saturation8 = 50;
    }

    Saturation9 = *rtu_long_cnt;
    if (Saturation9 > 6000)
    {
        Saturation9 = 6000;
    }
    else if (Saturation9 < 1000)
    {
        Saturation9 = 1000;
    }

    Saturation10 = *rtu_short_cnt;
    if (Saturation10 > 50)
    {
        Saturation10 = 50;
    }
    else if (Saturation10 < 20)
    {
        Saturation10 = 20;
    }

    Saturation11 = *rtu_transfer_cnt;
    if (Saturation11 > 50)
    {
        Saturation11 = 50;
    }
    else if (Saturation11 < 20)
    {
        Saturation11 = 20;
    }

    localDW->sfEvent = motor_ctrl_CALL_EVENT;
    if (localDW->temporalCounter_i1 < 32767U)
    {
        localDW->temporalCounter_i1++;
    }

    if (localDW->temporalCounter_i2 < 32767U)
    {
        localDW->temporalCounter_i2++;
    }

    if (localDW->temporalCounter_i3 < 32767U)
    {
        localDW->temporalCounter_i3++;
    }

    if (localDW->is_active_c3_motor_ctrl == 0U)
    {
        localDW->is_active_c3_motor_ctrl = 1U;
        localDW->is_c3_motor_ctrl = motor_ctrl_IN_MOTOR_CTRL;
        localDW->is_active_COM_CMD = 1U;
        localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
        localDW->is_active_KEY_CMD = 1U;
        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
        localDW->is_active_MOTOR = 1U;
        localDW->is_MOTOR = motor_ctrl_IN_OFF;
    }
    else if (localDW->is_c3_motor_ctrl == 1)
    {
        if (localDW->is_active_COM_CMD != 0U)
        {
            switch (localDW->is_COM_CMD)
            {
              case motor_ctrl_IN_IDLE:
                if (u0_3 > 1)
                {
                    u0_3 = 1;
                }
                else if (u0_3 < 0)
                {
                    u0_3 = 0;
                }

                if (u0_3 == 1)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_LONG_DOWN;
                    localDW->temporalCounter_i1 = 0U;
                    h_previousEvent = localDW->sfEvent;
                    localDW->sfEvent = motor_ctr_event_long_down_event;
                    if (localDW->is_active_MOTOR != 0U)
                    {
                        motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                    }

                    localDW->sfEvent = h_previousEvent;
                }
                else
                {
                    if (u0_1 > 1)
                    {
                        u0_1 = 1;
                    }
                    else if (u0_1 < 0)
                    {
                        u0_1 = 0;
                    }

                    if (u0_1 == 1)
                    {
                        localDW->is_COM_CMD = motor_ctrl_IN_STOP;
                        localDW->temporalCounter_i1 = 0U;
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_ctrl_event_stop_event;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                    }
                    else
                    {
                        if (u0 > 1)
                        {
                            u0 = 1;
                        }
                        else if (u0 < 0)
                        {
                            u0 = 0;
                        }

                        if (u0 == 1)
                        {
                            localDW->is_COM_CMD = motor_ctrl_IN_SHORT_UP;
                            localDW->temporalCounter_i1 = 0U;
                            h_previousEvent = localDW->sfEvent;
                            localDW->sfEvent = motor_ctrl_event_short_up_event;
                            if (localDW->is_active_MOTOR != 0U)
                            {
                                motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                            }

                            localDW->sfEvent = h_previousEvent;
                        }
                        else
                        {
                            if (u0_0 > 1)
                            {
                                u0_0 = 1;
                            }
                            else if (u0_0 < 0)
                            {
                                u0_0 = 0;
                            }

                            if (u0_0 == 1)
                            {
                                localDW->is_COM_CMD = motor_ctrl_IN_LONG_UP;
                                localDW->temporalCounter_i1 = 0U;
                                h_previousEvent = localDW->sfEvent;
                                localDW->sfEvent = motor_ctrl_event_long_up_event;
                                if (localDW->is_active_MOTOR != 0U)
                                {
                                    motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                                }

                                localDW->sfEvent = h_previousEvent;
                            }
                            else
                            {
                                if (u0_2 > 1)
                                {
                                    u0_2 = 1;
                                }
                                else if (u0_2 < 0)
                                {
                                    u0_2 = 0;
                                }

                                if (u0_2 == 1)
                                {
                                    localDW->is_COM_CMD = motor_ctrl_IN_SHORT_DOWN;
                                    localDW->temporalCounter_i1 = 0U;
                                    h_previousEvent = localDW->sfEvent;
                                    localDW->sfEvent = motor_ct_event_short_down_event;
                                    if (localDW->is_active_MOTOR != 0U)
                                    {
                                        motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                                    }

                                    localDW->sfEvent = h_previousEvent;
                                }
                            }
                        }
                    }
                }
                break;

              case motor_ctrl_IN_LONG_DOWN:
                if (localDW->temporalCounter_i1 >= Saturation10)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
                }
                break;

              case motor_ctrl_IN_LONG_UP:
                if (localDW->temporalCounter_i1 >= Saturation10)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
                }
                break;

              case motor_ctrl_IN_SHORT_DOWN:
                if (localDW->temporalCounter_i1 >= Saturation10)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
                }
                break;

              case motor_ctrl_IN_SHORT_UP:
                if (localDW->temporalCounter_i1 >= Saturation10)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
                }
                break;

              case motor_ctrl_IN_STOP:
                if (localDW->temporalCounter_i1 >= Saturation10)
                {
                    localDW->is_COM_CMD = motor_ctrl_IN_IDLE;
                }
                break;
            }
        }

        if (localDW->is_active_KEY_CMD != 0U)
        {
            switch (localDW->is_KEY_CMD)
            {
              case motor_ctrl_IN_DOWN_KEY_PRESSED:
                switch (localDW->is_DOWN_KEY_PRESSED)
                {
                  case motor_ctrl_IN_DOWN_CLICK:
                    if (Saturation1 != 1)
                    {
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_ctrl_event_down_key_click;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                        localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    else if (localDW->temporalCounter_i2 >= Saturation8)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_DOWN_LONGPRESS;
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_event_down_key_long_press;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                    }
                    break;

                  case motor_ctrl_IN_DOWN_DEBOUNCE:
                    if (localDW->temporalCounter_i2 >= Saturation7)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_DOWN_CLICK;
                        localDW->temporalCounter_i2 = 0U;
                    }
                    else if (Saturation1 != 1)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    break;

                  case motor_ctrl_IN_DOWN_LONGPRESS:
                    if (Saturation1 != 1)
                    {
                        localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    break;
                }
                break;

              case motor_ctrl_IN_IDLE_f:
                if (Saturation == 1)
                {
                    localDW->is_KEY_CMD = motor_ctrl_IN_UP_KEY_PRESSED;
                    localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_UP_DEBOUNCE;
                    localDW->temporalCounter_i2 = 0U;
                }
                else if (Saturation1 == 1)
                {
                    localDW->is_KEY_CMD = motor_ctrl_IN_DOWN_KEY_PRESSED;
                    localDW->is_DOWN_KEY_PRESSED = motor_ctrl_IN_DOWN_DEBOUNCE;
                    localDW->temporalCounter_i2 = 0U;
                }
                break;

              case motor_ctrl_IN_UP_KEY_PRESSED:
                switch (localDW->is_UP_KEY_PRESSED)
                {
                  case motor_ctrl_IN_UP_CLICK:
                    if (Saturation != 1)
                    {
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_ctrl_event_up_key_click;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                        localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    else if (localDW->temporalCounter_i2 >= Saturation8)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_UP_LONGPRESS;
                        h_previousEvent = localDW->sfEvent;
                        localDW->sfEvent = motor_c_event_up_key_long_press;
                        if (localDW->is_active_MOTOR != 0U)
                        {
                            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
                        }

                        localDW->sfEvent = h_previousEvent;
                    }
                    break;

                  case motor_ctrl_IN_UP_DEBOUNCE:
                    if (localDW->temporalCounter_i2 >= Saturation7)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_UP_CLICK;
                        localDW->temporalCounter_i2 = 0U;
                    }
                    else if (Saturation != 1)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    break;

                  case motor_ctrl_IN_UP_LONGPRESS:
                    if (Saturation != 1)
                    {
                        localDW->is_UP_KEY_PRESSED = motor_ctrl_IN_NO_ACTIVE_CHILD;
                        localDW->is_KEY_CMD = motor_ctrl_IN_IDLE_f;
                    }
                    break;
                }
                break;
            }
        }

        if (localDW->is_active_MOTOR != 0U)
        {
            motor_ctrl_MOTOR(&Saturation9, &Saturation10, &Saturation11, rty_up_relay, rty_down_relay, localDW);
        }
    }
}

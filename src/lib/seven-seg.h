#include "../lib/rtc.h"

#define TOP_L_ON() SEG_F_GRP |= (1<<SEG_F_PIN)
#define TOP_L_OFF() SEG_F_GRP &= ~(1<<SEG_F_PIN)
#define TOP_ON() SEG_A_GRP |= (1<<SEG_A_PIN)
#define TOP_OFF() SEG_A_GRP &= ~(1<<SEG_A_PIN)
#define TOP_R_ON() SEG_B_GRP |= (1<<SEG_B_PIN)
#define TOP_R_OFF() SEG_B_GRP &= ~(1<<SEG_B_PIN)
#define MID_ON() SEG_G_GRP |= (1<<SEG_G_PIN)
#define MID_OFF() SEG_G_GRP &= ~(1<<SEG_G_PIN)
#define BOT_L_ON() SEG_E_GRP |= (1<<SEG_E_PIN)
#define BOT_L_OFF() SEG_E_GRP &= ~(1<<SEG_E_PIN)
#define BOT_ON() SEG_D_GRP |= (1<<SEG_D_PIN)
#define BOT_OFF() SEG_D_GRP &= ~(1<<SEG_D_PIN)
#define BOT_R_ON() SEG_C_GRP |= (1<<SEG_C_PIN)
#define BOT_R_OFF() SEG_C_GRP &= ~(1<<SEG_C_PIN)
#define DOT_ON() SEG_DP_GRP |= (1<<SEG_DP_PIN)
#define DOT_OFF() SEG_DP_GRP &= ~(1<<SEG_DP_PIN)

#define DIGIT1_ENABLE() SEG_DIG1_GRP &= ~(1<<SEG_DIG1_PIN)
#define DIGIT1_DISABLE() SEG_DIG1_GRP |= (1<<SEG_DIG1_PIN)
#define DIGIT2_ENABLE() SEG_DIG2_GRP &= ~(1<<SEG_DIG2_PIN)
#define DIGIT2_DISABLE() SEG_DIG2_GRP |= (1<<SEG_DIG2_PIN)
#define DIGIT3_ENABLE() SEG_DIG3_GRP &= ~(1<<SEG_DIG3_PIN)
#define DIGIT3_DISABLE() SEG_DIG3_GRP |= (1<<SEG_DIG3_PIN)
#define DIGIT4_ENABLE() SEG_DIG4_GRP &= ~(1<<SEG_DIG4_PIN)
#define DIGIT4_DISABLE() SEG_DIG4_GRP |= (1<<SEG_DIG4_PIN)

void init_seven_seg();
void set_off();
void flash(int, int, int);
void set_num(char);
void set_digit(char);
void set_time(struct tm*);

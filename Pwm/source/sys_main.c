#include "sys_common.h"
#include "system.h"
/* USER CODE BEGIN (1) */
#include "het.h"
#include "gio.h"
/* USER CODE END */
/* USER CODE BEGIN (2) */
/* USER CODE END */
void main(void){
    /* USER CODE BEGIN (3) */
    gioSetDirection(hetPORT1, 0xFFFFFFFF);
    /* Initialize HET driver */
    hetInit();
    /* Run forever */
    while(1){
        if(pwmGetSignal(0xFF460000,0, 0x00002C80))<0.5)
            gioSetBit(hetPORT1, 0, 1);
        else
            gioSetBit(hetPORT1, 0, 0);
    }
    /* USER CODE END */
}

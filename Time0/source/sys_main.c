/* Include Files */
#include "sys_common.h"
#include "system.h"
/* USER CODE BEGIN (1) */
#include "rti.h"
#include "het.h"
#include "gio.h"
/* USER CODE END */
/* USER CODE BEGIN (2) */
/* USER CODE END */
void main(void){
    /* USER CODE BEGIN (3) */
    /* Initialize RTI driver */
    rtiInit();
    /* Set high end timer GIO port hetPort pin direction to all output */
    gioSetDirection(hetPORT1, 0xFFFFFFFF);
    /* Enable RTI Compare 0 interrupt notification */
    rtiEnableNotification(rtiNOTIFICATION_COMPARE0);
    /* Enable IRQ - Clear I flag in CPS register */
    /* Note: This is usually done by the OS or in an svc dispatcher */
    _enable_IRQ();    /* Start RTI Counter Block 0 */
    rtiStartCounter(rtiCOUNTER_BLOCK0);
    /* Run forever */
    while(1);
    /* USER CODE END */
}/* USER CODE BEGIN (4) */
/* Note-You need to remove rtiNotification from notification.c to avoid redefinition */
void rtiNotification(uint32 notification){
    /*  enter user code between the USER CODE BEGIN and USER CODE END. */
    /* Toggle HET pin 0 */
    gioSetPort(hetPORT1, gioGetPort(hetPORT1) ^ 0x00000001);
}

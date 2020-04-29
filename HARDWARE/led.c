#include "stm32f1xx_hal.h"

/**
 *  just demo,you can change to any io pin here 
 *  demo use PA9
 */
void LED_Init(void)
{
    GPIO_InitTypeDef GPIO_Initure;
    __HAL_RCC_GPIOA_CLK_ENABLE();           
    
    GPIO_Initure.Pin=GPIO_PIN_9; //PA9
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  
    GPIO_Initure.Pull=GPIO_PULLUP;          
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    
    HAL_GPIO_Init(GPIOA,&GPIO_Initure); 
}

/**
 * change led status
 * @param   led status         
 */
void LED_Light(uint16_t led)
{
    if(led){
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_RESET);
    }else{
        HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,GPIO_PIN_SET);
    }
}

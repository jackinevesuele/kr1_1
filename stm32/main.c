#include "stm32f10x.h"

/* Вариант 2: PA2 — вход, PA3 — выход. STM32F103C8. */
int main(void)
{
    /* Включить тактирование GPIOA. */
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;

    /* PA2: MODE2=00 (вход), CNF2=01 (плавающий вход). */
    GPIOA->CRL &= ~(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);
    GPIOA->CRL |= GPIO_CRL_CNF2_0;

    /* PA3: MODE3=10 (выход 2 МГц), CNF3=00 (push-pull). */
    GPIOA->CRL &= ~(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
    GPIOA->CRL |= GPIO_CRL_MODE3_1;

    while (1)
    {
        if ((GPIOA->IDR & GPIO_IDR_IDR2) != 0U)
        {
            GPIOA->BSRR = GPIO_BSRR_BS3;
        }
        else
        {
            GPIOA->BSRR = GPIO_BSRR_BR3;
        }
    }
}

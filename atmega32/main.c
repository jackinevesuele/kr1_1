#include <avr/io.h>

/* Вариант 2: PB2 — вход, PB3 — выход. ATmega32. */
int main(void)
{
    DDRB &= ~(1 << PB2);
    DDRB |= (1 << PB3);

    while (1)
    {
        if ((PINB & (1 << PB2)) != 0)
        {
            PORTB |= (1 << PB3);
        }
        else
        {
            PORTB &= ~(1 << PB3);
        }
    }
}

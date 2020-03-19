#include <avr/io.h>
#include <util/delay.h>


int main(void) {
	// Ports konfigurieren
	DDRA = 0xFF;
	DDRB = 0;
	PORTB = 0xFF;
	DDRD = 0;
	PORTD = 0xFF;
	
	unsigned char table[] = {0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F}; // LED Tabelle
	int count = 0; // Zähler variable für den Index der Tabelle table
	
	// Program loop
	while (1) {
		if (PINB & 0x01) { // Wenn der Würfel aktiviert wurde
			_delay_ms(10); // Warte 10ms
			PORTA = table[count % 6]; // Wähle eine Zahl aus der Tabelle
			count++; // Inkrementiere count
			while (PIND & 0x01)  // Solange PD0 aktiviert ist mach nichts
				asm("NOP");
		} else { // andernfalls
			PORTA = 0; // Schalte alle LEDs aus
		}
	}	
}


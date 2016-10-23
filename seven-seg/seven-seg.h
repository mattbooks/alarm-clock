#define TOP_L_OFF() PORTC |= (1<<PORTC1)
#define TOP_L_ON() PORTC &= ~(1<<PORTC1)
#define TOP_OFF() PORTC |= (1<<PORTC2)
#define TOP_ON() PORTC &= ~(1<<PORTC2)
#define TOP_R_OFF() PORTC |= (1<<PORTC3)
#define TOP_R_ON() PORTC &= ~(1<<PORTC3)
#define MID_OFF() PORTC |= (1<<PORTC0)
#define MID_ON() PORTC &= ~(1<<PORTC0)
#define BOT_L_OFF() PORTB |= (1<<PORTB4)
#define BOT_L_ON() PORTB &= ~(1<<PORTB4)
#define BOT_OFF() PORTB |= (1<<PORTB2)
#define BOT_ON() PORTB &= ~(1<<PORTB2)
#define BOT_R_OFF() PORTB |= (1<<PORTB1)
#define BOT_R_ON() PORTB &= ~(1<<PORTB1)
#define DOT_OFF() PORTB |= (1<<PORTB0)
#define DOT_ON() PORTB &= ~(1<<PORTB0)

void init_seven_seg();
void set_off();
void flash(int, int);
void set_num(int);


void delay(void);
#define FIO0DIR0 (*(volatile unsigned char *)(0x2009C000))
#define FIO0PIN0 (*(volatile unsigned char *)(0x2009C014))
#define FIO2DIR0 (*(volatile unsigned char *)(0x2009C040))
#define FIO2PIN0 (*(volatile unsigned char *)(0x2009C054))

char a;
char b;
char i;

void delay(void) {
    int j;
    for(j=0; j< 1000000; j++) {
        j++;
        j--;
    }
}

int main() {
    FIO0DIR0=0x00;
    FIO2DIR0=0xFF;
    while(1) {
        if(FIO0PIN0&0x01==1) {
            a=0x01;
            b=0x02;
        }
        else {
            a=0x02;
            b=0x01;
        }
        FIO2PIN0 |= a;
        delay();
        FIO2PIN0 &= ~a;
        delay();
        for(i=0; i<=3; i++) {
            FIO2PIN0 |= b;
            delay();
            FIO2PIN0 &= ~b;
            delay();
        }
    }
}

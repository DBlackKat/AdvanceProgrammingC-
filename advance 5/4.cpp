#include <stdio.h>
#include <stdlib.h>
#define S "\xE2\x99\xA0"
#define H "\xE2\x99\xA5"
#define D "\xE2\x99\xA6"
#define C "\xE2\x99\xA3"

enum suit { HEART = 3, DIAMOND, CLUB, SPADE };
enum numb { ACE='A', TEN='0', JACK='J', QUEEN='Q', KING='K' };
struct Card
{
    suit cardSuit;
    numb cardNum;
};
Card deck[20];
void gen(Card deck[20]){
    for(int i=0;i<20;i++){
        switch(i%5){
            case 0:
                deck[i].cardNum = ACE;
                break;
            case 1:
                deck[i].cardNum = TEN;
                break;
            case 2:
                deck[i].cardNum = JACK;
                break;
            case 3:
                deck[i].cardNum = QUEEN;
                break;
            case 4:
                deck[i].cardNum = KING;
                break;
        }
        switch(i%4){
            case 0:
                deck[i].cardSuit = HEART;
                break;
            case 1:
                deck[i].cardSuit = DIAMOND;
                break;
            case 2:
                deck[i].cardSuit = SPADE;
                break;
            case 3:
                deck[i].cardSuit = CLUB;
                break;
        }
    }
}
void shuffle(Card deck[20]){
    int k;
    Card buffer;
    for(int i=0;i<20;i++){
        k = rand()%20;
        buffer = deck[k];
        deck[k] = deck[i];
        deck[i] = buffer;
    }
}

void printCard(Card deck[20]){
    char suit[7][12] = {"","","",H,D,C,S};
    for(int i=0,j=0;i<20;i++,j++){
        if(j%5 == 0)
            printf("\n");
        printf("%s%c ",suit[deck[i].cardSuit],deck[i].cardNum);
    }
    printf("\n");
}
int main(){
    Card deck[20];
    gen(deck);
    printCard(deck);
    shuffle(deck);
    printCard(deck);
    return 0;
}

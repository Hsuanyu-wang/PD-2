#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int num,item;
    fprintf(stderr,"input num:");
    scanf("%d",&num);
    int space = num/4;
    char enter[space];
    char f0[space],f1[space],f2[space],f3[space];
    for(int i=0; i<space; i++){
        enter[i] = 0b00000000;
        f0[i] = 0b00000000, f1[i] = 0b00000000, f2[i] = 0b00000000, f3[i] = 0b00000000;
    }
    while(scanf("%d", &item) != EOF){
        if(item%4 == 0 && f0[item/4] == 0){
            enter[item/4] += 0b01000000;
            if((enter[item/4]&0b11000000)>>6 < 3 && (enter[item/4]&0b11000000)>>6 > 0)
                printf("PASS\n");
            else if((enter[item/4]&0b11000000)>>6 == 3){
                f0[item/4]=1;
                printf("PASS\n");
            }
        }
        else if(item%4 == 0 && f0[item/4] == 1)
                printf("GOOD BYE\n");

        if(item%4 == 1 && f1[item/4] == 0)
        {
            enter[item/4] += 0b00010000;
            if((enter[item/4]&0b00110000)>>4 < 3 && (enter[item/4]&0b00110000)>>4 > 0)
                printf("PASS\n");
            else if((enter[item/4]&0b00110000)>>4 == 3){
                f1[item/4]=1;
                printf("PASS\n");
            }
        }
        else if(item%4 == 1 && f1[item/4] == 1)
            printf("GOOD BYE\n");

        if(item%4 == 2 && f2[item/4] == 0)
        {
            enter[item/4] += 0b00000100;
            if(((enter[item/4]&0b00001100)>>2) <3 && (enter[item/4]&0b00001100)>>2>0)
                printf("PASS\n");
            else if(((enter[item/4]&0b00001100)>>2) == 3){
                f2[item/4]=1;
                printf("PASS\n");
            }
        }
        else if(item%4 == 2 && f2[item/4] == 1)
            printf("GOOD BYE\n");

        if(item%4 == 3 && f3[item/4] == 0)
        {
            enter[item/4] += 0b00000001;
            if((enter[item/4]&0b00000011) < 3 && (enter[item/4]&0b00000011) > 0)
                printf("PASS\n");
            else if((enter[item/4]&0b00000011) == 3){
                f3[item/4]=1;
                printf("PASS\n");
            }
        }
        else if(item%4 == 3 && f3[item/4] == 1)
            printf("GOOD BYE\n");
    }
    return 0;
}

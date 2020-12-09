#include<stdio.h>
unsigned fields[9];
unsigned short checksum()
{
    int i;
    int sum=0;
    printf("Enter IP header in Words\n");
    for(i=0;i<9;i++)
    {
        printf("Field %d\n",i+1);
        scanf("%x",&fields[i]);
        sum+=(unsigned short)fields[i];
        while(sum>>16)
            sum=(sum&0xFFFF)+(sum>>16);
    }
        sum=~sum;
        return (unsigned short)sum;
        
}



int main() {
    unsigned short res1,res2;
    res1=checksum();
    printf("Checksum at Sender %x\n",res1);
    res2=checksum();
    printf("Checksum at Reviever %x\n",res2);
    if(res1==res2)
        printf("Correct , No error\n");
    else
        printf("Error in Communication\n");
    
}
//4500 003c 1c46 4000 4006 (b1e6) ac10 0a63 ac10 0a0c


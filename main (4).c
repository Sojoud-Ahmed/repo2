
/*File: task1.2
 * Author: Sojoud Ahmed
 * Description:count down,delay between numbers.
 */
#include <stdio.h>
void delay(int);//prototye for function
int main(){
    int counter;
    printf("Please Enter the number:");
    scanf("%d",&counter);
    // count down
    for (int cn=counter;cn>0;cn--){
        delay(1);//delay 1 second between numbers
        printf("%d\n",cn);}
    printf("Blast off to the moon!");
    return 0;}
    //Delay Function
void delay(int second){
	 int i,j;
for(i=0;i<second;i++)
for(j=0;j<100000000;j++);
}


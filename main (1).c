
/*File: task1.1
 * Author: Sojoud Ahmed
 * Description:print the name,Draw it with astreics.
 */


#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 10
#define height 5
int main()
{    int x;// x is a variable to represent number of rows
    char str[MAX_LENGTH];
    printf("Enter the name:");
    scanf("%s",&str);
    printf("%s\n",str);     //to print the name
    /*
    //Another Solution:
   char str[MAX_LENGTH]= "GRU";
    printf("%s\n",str);*/
 //Bonus
//Alphabet G
    for (x = 0;x <height; x++) {
        if(x==0||x==height-1)
         printf("*****\n");
        else if (x==1)
         printf("*    \n");
        else if(x==2)
         printf("*  **\n");
        else
         printf("*   *\n");}
//Alphabet R
     for(x= 0; x <height; x++) {
        if(x==0||x==2)
          printf("****\n");
        else if(x==1||x==3)
          printf("*   *\n");
        else
          printf("*    *\n");}

//Alphabet U
    for (int x=0;x<height;x++){
        if (x==0||x<height-1)
        printf("*   *\n");
        else
        printf("*****\n");}

/*
//Another Solution:
//Alphabet G
for (x = 0; x <height; x++) {
        switch (x){
            case 0:printf("*****\n");
                break;
            case 1:printf("*    \n");
                break;
            case 2:printf("*  **\n");
                break;
            case 3:printf("*   *\n");
                break;
            case 4:printf("*****\n");
                break;
            default:break;
        }}
//Alphabet R
 for(x= 0; x <height; x++) {
        switch (x){
            case 0:printf("****\n");
                break;
            case 1:printf("*   *\n");
                break;
            case 2:printf("****\n");
                break;
            case 3:printf("*   *\n");
                break;
            case 4:printf("*    *\n");
                break;
            default:break;
        }}
//Alphabet U
        for(int x=0;x<height;x++){
               switch(z){

            case 0: printf("*   *\n");
                break;
            case 1: printf("*   *\n");
                break;
            case 2: printf("*   *\n");
                break;
            case 3: printf("*   *\n");
                break;

               case 4:printf("*****\n");
                  break;
                    default:break;

               }}*/
            return 0;
}

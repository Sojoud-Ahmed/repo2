/*File: task1.3
 * Author: Sojoud Ahmed
 * Description:Add,View,remove Tasks(data),Mark tasks,show if tasks complete or not
  ,and show data in table format.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 10000
#define NUM_TASKS 300

//Declare of struct
 struct task {
     int ID;
     char Description[MAX_LENGTH];
      int completed;
}current_tasks[NUM_TASKS],TASK;//struct variables
int num=0,x,n;//global variable
//Add function
void Add() {
    printf("Enter Task Description: ");
    fgets(TASK.Description,MAX_LENGTH,stdin);//to read the input
   current_tasks [num] = TASK;
    num++;
    printf("Task added successfully!\n");
    printf("\n");
    }
//view function
void View(){
    printf("current_tasks:\n");
      //for loop to print ID& Desscription
    for ( int i=0;i<num;i++) {
        printf("Task ID: %d\n",i+1);
        printf("Description:%s\n", current_tasks[i].Description);
printf("\n");
        }}
//Bonus
//complete function
    void mark_complete() {
    printf("Enter task ID: ");
    scanf("%d", &x);
// Check if task ID and description are valid
   if ((x < 1 || x > num)) {
        printf("Invalid task ID and/or description.\n");
        return;
    }

// Mark the task as completed
    current_tasks[x - 1].completed = 1;
    printf("Task is completed!\n");

}
//Bonus
//show function (to show in/completed tasks.
void Show() {
    printf("*Completed tasks:*\n");
    for (int i = 0; i < num; i++) {
        if (current_tasks[i].completed == 1) {
            printf("Task ID: %d\n", i + 1);
            printf("Description: %s", current_tasks[i].Description);
            printf("\n");
         }else{
             printf("*incompleted* tasks\n");
            printf("Task ID: %d\n", i + 1);
            printf("Description: %s", current_tasks[i].Description);
            printf("\n");
        }
    }
}
//remove function
void Remove() {
    int x;
    printf("Enter task ID to remove: ");
    scanf("%d",&x);
    if(x<1||x>num){
    printf("there is no task to delete!!");
   exit(0);
    }
    for (int i=x-1; i<num-1;i++) {
        current_tasks[i] = current_tasks[i + 1];}num--;
printf("Task removed successfully!\n");
printf("\n");
}


int main() {
    printf("Minions Task Manager\n1.Add Task\n2.View Tasks\n3.Remove Tasks\n4.Exit\n");
int op;
//for loop for input the option for NUM_TASKS
    for(op=0;op<NUM_TASKS;op++){
        printf("select an option:",op);
        scanf("%d",&op);
        getchar();     // to clear the input buffer
// To select the operation
        switch (op){
              case 1:
                Add();
                break;
              case 2:
                View();
                break;
              case 3:
                Remove();
                break;
              case 4:
                mark_complete();
                break;
              case 5:
                Show();
                break;
              case 6:
             //Bonus
            // To put Data in Table Format
             printf("TASK ID\t DESCRIPTION\tCOMPLETE\t\n ");
                for (n = 0; n < num; n++) {
                    printf("%d\t %s",n+1, current_tasks[n].Description);
                if (current_tasks[n].completed == 1) {
                        printf("\t\t\tYes\n");
                    } else {
                        printf("\t\t\tNo\n");}}
                break;
              case 7:
                printf("Exiting Minsion Task Manager.Have a great day!!\n");
                break;
              default:
                break;}}
                return 0;}

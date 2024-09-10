#include <stdio.h>
#include <stdlib.h>


struct Date_of_birth{
    int day;
    char month[20];
    int year;
};

struct student_information{
    int Unique_number;
    char Last_name[50];
    char First_name[50];
    struct Date_of_birth dob;
    char Department[50];
    int General_note;
};


void Add_a_student(struct student_information *Student){

        printf("FirstName: \n");
        scanf("%s", Student->First_name);
        printf("LastName: \n");
        scanf("%s", Student->Last_name);

        printf("To enter the date of birth: \n");
        printf("enter the day:");
        scanf("%d", &Student->dob.day);
        printf("enter the month: \n");
        scanf("%s", Student->dob.month);
        printf("enter the Year: \n");
        scanf("%d", &Student->dob.year);
        printf("Department: \n");
        scanf("%s", Student->Department);
        printf("Enter Unique Number: \n");
        scanf("%d", &Student->Unique_number);

        printf("%d - %s - %d", Student->dob.day, Student->dob.month, Student->dob.year);
}




int main()
{
    struct student_information student_1;

    int choice;

    do{

      printf("enter the number: \n");
      printf("1.to Add a student  \n");
      printf("2.to Edit or delete a student  \n");
      printf("3.to View student details  \n");
      printf("4.to Calculate the overall average  \n");
      printf("5.to Statistics  \n");
      printf("6.to Search for a student by  \n");
      printf("7.to Sort a student by  \n");
      printf("0.to Exit \n");

      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice){
        case 1:
          Add_a_student(&student_1);
        break;
        case 2:
         printf("the choice 2 \n");
        break;
        case 3:
         printf("the choice 3 \n");
        break;
        case 4:
         printf("the choice 4 \n");
        break;
        case 5:
         printf("the choice 5 \n");
        break;
        case 6:
         printf("the choice 6 \n");
        break;
        case 7:
         printf("the choice 7 \n");
        break;
        case 0:
         printf("exit");
        break;
      }
    }while(choice != 0);




    return 0;
}

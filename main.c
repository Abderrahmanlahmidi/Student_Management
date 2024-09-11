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

struct student_information student_1;
struct student_information list_Student[100];
int counter = 0;




void Add_a_student(){

        printf("FirstName: \n");
        scanf("%s", list_Student[counter].First_name);
        printf("LastName: \n");
        scanf("%s", list_Student[counter].Last_name);

        printf("To enter the date of birth: \n");
        printf("enter the day:");
        scanf("%d", &list_Student[counter].dob.day);
        printf("enter the month: \n");
        scanf("%s", list_Student[counter].dob.month);
        printf("enter the Year: \n");
        scanf("%d", &list_Student[counter].dob.year);

        printf("Department: \n");
        scanf("%s", list_Student[counter].Department);
        printf("Enter Unique Number: \n");
        scanf("%d", &list_Student[counter].Unique_number);
        printf("Enter General note: \n");
        scanf("%d", &list_Student[counter].General_note);

        counter++;

}

void Edit(){
    int Number;
    printf("enter the number:");
    scanf("%d", &Number);

    for(int i = 0; i < counter; i++){
        if(list_Student[i].Unique_number == Number){
          printf("FirstName: \n");
          scanf("%s", list_Student[i].First_name);
          printf("LastName: \n");
          scanf("%s", list_Student[i].Last_name);

          printf("To enter the date of birth: \n");
          printf("enter the day:");
          scanf("%d", &list_Student[i].dob.day);
          printf("enter the month: \n");
          scanf("%s", list_Student[i].dob.month);
          printf("enter the Year: \n");
          scanf("%d", &list_Student[i].dob.year);
          printf("Department: \n");

          scanf("%s", list_Student[i].Department);

          printf("Enter General note: \n");
          scanf("%d", &list_Student[i].General_note);
        }
    }

    printf("Student information has been successfully changed");

}

void Delete(){

}


void Edit_Delete(){

    int ED_Choice;
    printf("enter 1:Edit 2:Delete");
    scanf("%d", &ED_Choice);

     switch(ED_Choice){
       case 1:
        Edit();
       break;
       case 2:
        Delete();
       break;

     }

}

void view_information(){

   for(int i = 0; i < counter; i++){
     printf("FirstName:%s \n", list_Student[i].First_name);
     printf("LastName:%s \n", list_Student[i].Last_name);
     printf("Date of birth:%d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
     printf("Department:%s \n", list_Student[i].Department);
     printf("Unique Number:%d \n", list_Student[i].Unique_number);

   }

}



int main()
{

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
          Add_a_student();
        break;
        case 2:
         Edit_Delete();
        break;
        case 3:
          view_information();
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
    }while(1);



    return 0;
}

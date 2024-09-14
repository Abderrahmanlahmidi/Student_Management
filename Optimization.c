#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

struct student_information list_Student[100];
int counter = 0;


void add_student(){

   printf("Enter student information:\n");
   printf("Last name: ");
   scanf("%s", &list_Student[counter].Last_name);
   printf("First name: ");
   scanf("%s", &list_Student[counter].First_name);
   printf("Date of birth:  \n");
   printf("day:");
   scanf("%d", &list_Student[counter].dob.day);
   printf("month:");
   scanf("%s", &list_Student[counter].dob.month);
   printf("year:");
   scanf("%d", &list_Student[counter].dob.year);
   
   printf("Department: ");
   scanf("%s", &list_Student[counter].Department);
   printf("Unique number: ");
   scanf("%d", &list_Student[counter].Unique_number);
   printf("General note: ");
   scanf("%d", &list_Student[counter].General_note);
   printf("The information has been entered successfully. \n");
 
   counter++;
}



void edit(){
    
    int Searching_Number;

    printf("To modify student information enter \n");
    printf("Unique number: ");
    scanf("%d", &Searching_Number);

    for (int i = 0; i < counter; i++)
    {
       if (list_Student[i].Unique_number == Searching_Number)
       {
         printf("Enter student information:\n");
         printf("Last name: ");
         scanf("%s", &list_Student[i].Last_name);
         printf("First name: ");
         scanf("%s", &list_Student[i].First_name);
         printf("Date of birth:  \n");
         printf("day:");
         scanf("%d", &list_Student[i].dob.day);
         printf("month:");
         scanf("%s", &list_Student[i].dob.month);
         printf("year:");
         scanf("%d", &list_Student[i].dob.year);
         
         printf("Department: ");
         scanf("%s", &list_Student[i].Department);
         printf("Unique number: ");
         scanf("%d", &list_Student[i].Unique_number);
         printf("General note: ");
         scanf("%d", &list_Student[i].General_note);
         printf("Student information has been modified successfully. \n");
       }
       
    }
    
}

void delete(){

    int Searching_Number;
    int found = 0;

    printf("Enter the Unique number of the student to delete: ");
    scanf("%d", &Searching_Number);

    for (int i = 0; i < counter; i++)
    {
        if (list_Student[i].Unique_number == Searching_Number)
        {
            found = 1;

           
            for (int j = i; j < counter - 1; j++)
            {
                list_Student[j] = list_Student[j + 1];
            }
            
            counter--;
            printf("Student with Unique number %d has been deleted.\n", Searching_Number);
            break;
        }
    }

    if (!found)
    {
        printf("Student with Unique number %d not found.\n", Searching_Number);
    }
    
}


void edit_delete(){
    
    int choice_2;

    printf("Enter your choice:\n");
    printf("[1]: Edit\n");
    printf("[2]: Delete\n");
    printf("Enter number:");
    scanf("%d", &choice_2);

    switch (choice_2)
    {
    case 1:
        edit();
        break;
    case 2:
        delete();
        break;
    default:
        printf("Invalid choice. Please enter 1 to edit or 2 to delete.\n");
        break;
    }
    
}


void view_details(){

    for (int i = 0; i < counter; i++)
    {   
        printf("============[Student:%d]============ \n", i+1);
        printf("Last name: %s \n", list_Student[i].Last_name);
        printf("First name: %s \n", list_Student[i].First_name);
        printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
        printf("Department: %s \n", list_Student[i].Department);
        printf("Unique number: %d \n", list_Student[i].Unique_number);
        printf("General note: %d \n", list_Student[i].General_note);
    }
        printf("=================================== \n");
    
}



int main(){
    int choice_1;

    do{
        printf("Enter a number according to the following options: \n");
        printf("[1].Add a student\n");
        printf("[2].Edit or delete a student\n");
        printf("[3].View students details\n");
        printf("[4].Calculate the overall average\n");
        printf("[5].Statistics\n");
        printf("[6].Search for a student\n");
        printf("[7].Sort students\n");
        printf("[0].Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice_1);

        switch(choice_1){
            case 1:
                add_student();
                break;
            case 2:
                edit_delete();
                break;
            case 3:
                view_details();
                break;
            case 4:
                printf("the choice_4");
                break;
            case 5:
                printf("the choice_5");
                break;
            case 6:
                printf("the choice_6");
                break;
            case 7:
                printf("the choice_7");
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

    }while(choice_1 != 0);

    return 0;
}

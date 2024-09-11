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

void Add_a_student(){
    printf("FirstName: \n");
    scanf("%s", list_Student[counter].First_name);
    printf("LastName: \n");
    scanf("%s", list_Student[counter].Last_name);

    printf("To enter the date of birth: \n");
    printf("enter the day: ");
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
    printf("Enter the student's unique number to edit: ");
    scanf("%d", &Number);

    for(int i = 0; i < counter; i++){
        if(list_Student[i].Unique_number == Number){
            printf("Editing student %s %s\n", list_Student[i].First_name, list_Student[i].Last_name);

            printf("FirstName: \n");
            scanf("%s", list_Student[i].First_name);
            printf("LastName: \n");
            scanf("%s", list_Student[i].Last_name);

            printf("To enter the date of birth: \n");
            printf("enter the day: ");
            scanf("%d", &list_Student[i].dob.day);
            printf("enter the month: \n");
            scanf("%s", list_Student[i].dob.month);
            printf("enter the Year: \n");
            scanf("%d", &list_Student[i].dob.year);

            printf("Department: \n");
            scanf("%s", list_Student[i].Department);

            printf("Enter General note: \n");
            scanf("%d", &list_Student[i].General_note);
            printf("Student information has been successfully changed\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void Delete(){
    int Number;
    printf("Enter the unique number of the student to delete: ");
    scanf("%d", &Number);

    for(int i = 0; i < counter; i++){
        if(list_Student[i].Unique_number == Number){
            printf("Deleting student %s %s\n", list_Student[i].First_name, list_Student[i].Last_name);
            for(int j = i; j < counter - 1; j++){
                list_Student[j] = list_Student[j + 1];
            }
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}


void Edit_Delete(){
    int ED_Choice;
    printf("Enter 1 to Edit or 2 to Delete a student: ");
    scanf("%d", &ED_Choice);

    switch(ED_Choice){
       case 1:
            Edit();
            break;
       case 2:
            Delete();
            break;
       default:
            printf("Invalid choice.\n");
    }
}

void view_information(){
   for(int i = 0; i < counter; i++){
     printf("FirstName: %s \n", list_Student[i].First_name);
     printf("LastName: %s \n", list_Student[i].Last_name);
     printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
     printf("Department: %s \n", list_Student[i].Department);
     printf("Unique Number: %d \n", list_Student[i].Unique_number);
     printf("General note: %d \n", list_Student[i].General_note);
   }
}

void overall_average(){
     char department_name[50];

     printf("enter department name:");
     scanf("%s", &department_name);




     for(int i = 0; i < counter; i++){
        if()
     }

}



int main(){
    int choice;

    do{
        printf("Enter the number: \n");
        printf("1. Add a student\n");
        printf("2. Edit or delete a student\n");
        printf("3. View student details\n");
        printf("4. Calculate the overall average\n");
        printf("5. Statistics\n");
        printf("6. Search for a student\n");
        printf("7. Sort students\n");
        printf("0. Exit\n");

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
                overall_average();
                break;
            case 5:
                printf("Option 5 selected\n");
                break;
            case 6:
                printf("Option 6 selected\n");
                break;
            case 7:
                printf("Option 7 selected\n");
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(choice != 0);

    return 0;
}

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

    printf("FirstName: ");
    scanf("%s", list_Student[counter].First_name);
    printf("LastName: ");
    scanf("%s", list_Student[counter].Last_name);

    printf("To enter the date of birth: \n");
    printf("enter the day: ");
    scanf("%d", &list_Student[counter].dob.day);
    printf("enter the month: ");
    scanf("%s", list_Student[counter].dob.month);
    printf("enter the Year: ");
    scanf("%d", &list_Student[counter].dob.year);

    printf("Department: \n");
    printf("If you choose Informatique enter 'informatique': \n");
    printf("If you choose Philosophy enter 'philosophy': \n");
    printf("If you choose Etiquette enter 'etiquette': \n");

    char departement_name[100];
    scanf("%s", departement_name);

    if (strcmp(departement_name, "informatique") == 0) {
       strcpy(list_Student[counter].Department, "informatique");
    } else if (strcmp(departement_name, "philosophy") == 0) {
       strcpy(list_Student[counter].Department, "philosophy");
    } else if (strcmp(departement_name, "etiquette") == 0) {
       strcpy(list_Student[counter].Department, "etiquette");
    } else {
       printf("Invalid department entered.\n");
    }


    printf("Enter Unique Number: ");
    scanf("%d", &list_Student[counter].Unique_number);
    printf("Enter General note: ");
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


void overall_average() {

    int somme_1 = 0, somme_2 = 0, somme_3 = 0;
    int count_1 = 0, count_2 = 0, count_3 = 0;

    for (int i = 0; i < counter; i++) {
        if (strcmp("informatique", list_Student[i].Department) == 0) {
            somme_1 += list_Student[i].General_note;
            count_1++;
        } else if (strcmp("philosophy", list_Student[i].Department) == 0) {
            somme_2 += list_Student[i].General_note;
            count_2++;
        } else if (strcmp("etiquette", list_Student[i].Department) == 0) {
            somme_3 += list_Student[i].General_note;
            count_3++;
        }
    }

    int moyen_1 = (count_1 != 0) ? somme_1 / count_1 : 0;
    int moyen_2 = (count_2 != 0) ? somme_2 / count_2 : 0;
    int moyen_3 = (count_3 != 0) ? somme_3 / count_3 : 0;

    printf("Average informatique is: %d\n", moyen_1);
    printf("Average philosophy is: %d\n", moyen_2);
    printf("Average etiquette is: %d\n", moyen_3);


}


int statistics(){

        int suggested_point;
        printf("enter your suggested point:");
        scanf("%d", &suggested_point);


        int moyen_department_infomatique = 0;
        int moyen_department_philosophy = 0;
        int moyen_department_etiquette = 0;



        for(int i = 0; i < counter; i++){
            if(strcmp("informatique", list_Student[i].Department) == 0){
                moyen_department_infomatique++;
            }
        }

        for(int i = 0; i < counter; i++){
            if(strcmp("philosophy", list_Student[i].Department) == 0){
                moyen_department_philosophy++;
            }
        }

        for(int i = 0; i < counter; i++){
            if(strcmp("etiquette", list_Student[i].Department) == 0){
                moyen_department_etiquette++;
            }
        }


        for(int i = 0; i < counter; i++){
            if(list_Student[i].General_note > suggested_point){
                printf("FirstName: %s \n", list_Student[i].First_name);
                printf("LastName: %s \n", list_Student[i].Last_name);
                printf("Enter General note: %d \n", list_Student[i].General_note);
            }
        }


        int notes[100];

        for(int i = 0; i < counter; i++){
            notes[i] = list_Student[i].General_note;
        }

        for(int i = 0; i < counter - 1; i++) {
         for(int j = i + 1; j < counter; j++) {
           if(notes[i] < notes[j]) {
            int temp = notes[i];
              notes[i] = notes[j];
              notes[j] = temp;
             }
           }
         }




        printf("the total number of students enrolled: %d \n", counter);
        printf("the number of students in each department: \n");
        printf("informatique: %d \n", moyen_department_infomatique);
        printf("philosophy: %d \n", moyen_department_philosophy);
        printf("etiquette: %d \n", moyen_department_etiquette);
        printf("students with a GPA above a certain threshold: \n");

        printf("the 3 students with the highest grades:  \n");
        for(int i = 0; i < 3; i++){
            printf("%d \n", notes[i]);
        }

        printf("the number of successful students in each department: \n");
        for(int i = 0; i < counter; i++){
            if(list_Student[i].General_note >= 10){
                printf("%d \n", list_Student[i].General_note);
            }
        }


}

void search_student(){

   char student_First_name[20];
   char student_Last_name[20];
   printf("Enter the student's FirstName: ");
   scanf("%s", &student_First_name);
   printf("Enter the student's FirstName: ");
   scanf("%s", &student_Last_name);

   for(int i = 0; i < counter; i++){
    if(strcmp(student_First_name, list_Student[i].First_name) == 0 && strcmp(student_Last_name, list_Student[i].Last_name) == 0){
            printf("FirstName: %s \n", list_Student[i].First_name);
            printf("LastName: %s \n", list_Student[i].Last_name);
            printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
            printf("Department: %s \n", list_Student[i].Department);
            printf("Unique Number: %d \n", list_Student[i].Unique_number);
            printf("General note: %d \n", list_Student[i].General_note);
    }
   }

}

void show_list(){
    char departement_name[20];
    printf("Enter the departement name: ");
    scanf("%s", &departement_name);
    for(int i = 0; i < counter; i++){
         if(strcmp(departement_name,list_Student[i].Department) == 0){
            printf("FirstName: %s \n", list_Student[i].First_name);
            printf("LastName: %s \n", list_Student[i].Last_name);
            printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
            printf("Unique Number: %d \n", list_Student[i].Unique_number);
            printf("General note: %d \n", list_Student[i].General_note);
         }
    }

}


void looking_student(){

  printf("Enter the number: \n");
  printf("1.Search for a student by name\n");
  printf("2.View the list of students enrolled in a specific department");

  int looking_choice;
  scanf("%d", &looking_choice);

  switch(looking_choice){
   case 1:
       search_student();
   break;
   case 2:
       show_list();
   break;

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
                statistics();
                break;
            case 6:
                looking_student();
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

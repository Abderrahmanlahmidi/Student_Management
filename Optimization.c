#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date_of_birth{
    int day;
    char month[20];
    int year;
};

struct student_information{
    int unique_number;
    char Last_name[50];
    char First_name[50];
    struct Date_of_birth dob;
    char Department[50];
    int General_note;
};

int notes[100];

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
   
   printf("Choose The Department: \n");
   printf("[1]: Economy\n");
   printf("[2]: Philosophy\n");
   printf("[2]: Physics\n");

   char department_name[30];
   printf("Enter the department name: ");
   scanf("%s", &department_name);     

   if (strcmp(department_name, "Economy") == 0) {
       strcpy(list_Student[counter].Department, "Economy");
   } else if (strcmp(department_name, "Philosophy") == 0) {
       strcpy(list_Student[counter].Department, "Philosophy");
   } else if (strcmp(department_name, "Physics") == 0) {
       strcpy(list_Student[counter].Department, "Physics");
   } else {
       printf("Unknown department!\n");
   }

   printf("Student department: %s\n", list_Student[counter].Department);

   printf("Unique number: ");
   scanf("%d", &list_Student[counter].unique_number);
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
       if (list_Student[i].unique_number == Searching_Number)
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
         scanf("%d", &list_Student[i].unique_number);
         printf("General note: ");
         scanf("%d", &list_Student[i].General_note);
         printf("Student information has been modified successfully. \n");
       }
       
    }
    
}

void delete(){

    int Searching_Number;
    int found = 0;

    printf("Enter the unique number of the student to delete: ");
    scanf("%d", &Searching_Number);

    for (int i = 0; i < counter; i++)
    {
        if (list_Student[i].unique_number == Searching_Number)
        {
            found = 1;

           
            for (int j = i; j < counter - 1; j++)
            {
                list_Student[j] = list_Student[j + 1];
            }
            
            counter--;
            printf("Student with unique number %d has been deleted.\n", Searching_Number);
            break;
        }
    }

    if (!found)
    {
        printf("Student with unique number %d not found.\n", Searching_Number);
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
        printf("unique number: %d \n", list_Student[i].unique_number);
        printf("General note: %d \n", list_Student[i].General_note);
    }
        printf("=================================== \n");
    
}


int counter_1 = 0, counter_2 = 0, counter_3 = 0;

void general_average() {

    int somme_1 = 0, somme_2 = 0, somme_3 = 0;



    for (int i = 0; i < counter; i++) {
        if (strcmp(list_Student[i].Department, "Economy") == 0) {
            somme_1 += list_Student[i].General_note;
            counter_1++;
        }
    }

    for (int i = 0; i < counter; i++) {
        if (strcmp(list_Student[i].Department, "Philosophy") == 0) {
            somme_2 += list_Student[i].General_note;
            counter_2++;
        }
    }


    for (int i = 0; i < counter; i++) {
        if (strcmp(list_Student[i].Department, "Physics") == 0) {
            somme_3 += list_Student[i].General_note;
            counter_3++;
        }
    }


    if (counter_1 > 0) {
        int economy_department_average = somme_1 / counter_1;
        printf("Economy department average: %d \n", economy_department_average);
    } else {
        printf("No students in the Economy department.\n");
    }

    if (counter_2 > 0) {
        int philosophy_department_average = somme_2 / counter_2;
        printf("Philosophy department average: %d \n", philosophy_department_average);
    } else {
        printf("No students in the Philosophy department.\n");
    }

    if (counter_3 > 0) {
        int physics_department_average = somme_3 / counter_3;
        printf("Physics department average: %d \n", physics_department_average);
    } else {
        printf("No students in the Physics department.\n");
    }

}



void statistics(){

    int threshold;
    int Rates[20];
    int rates_count = 0;


    printf("Set the threshold: ");
    scanf("%d", &threshold);


    for (int i = 0; i < counter; i++) {
        if (list_Student[i].General_note > threshold) {
            Rates[rates_count] = list_Student[i].General_note;
            rates_count++;
        }
    }


    printf("The total number of students enrolled: %d \n", counter);
    printf("The number of students in each department: \n");
    printf("[1].Economy: %d\n", counter_1);
    printf("[2].Philosophy: %d\n", counter_2);
    printf("[3].Physics: %d\n", counter_3);


    printf("Students with a general note higher than the threshold:\n");
    if (rates_count > 0) {
        for (int i = 0; i < rates_count; i++) {
            printf("%d\n", Rates[i]);
        }
    } else {
        printf("No students have a general note above the threshold.\n");
    }


    int temp;
    for (int i = 0; i < counter - 1; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (list_Student[i].General_note < list_Student[j].General_note) {
                temp = list_Student[i].General_note;
                list_Student[i].General_note = list_Student[j].General_note;
                list_Student[j].General_note = temp;
            }
        }
    }

    printf("Show the 3 students with the highest grades:\n");
    for (int i = 0; i < (counter < 3 ? counter : 3); i++) {
        printf("Note-%d = %d\n", i+1, list_Student[i].General_note);
    }


    int Economy_Highest[50] = {0};
    int Philosophy_Highest[50] = {0};
    int Physics_Highest[50] = {0};
    int econ_count = 0, phil_count = 0, phys_count = 0;


    for (int i = 0; i < counter; i++) {
        if (strcmp(list_Student[i].Department, "Economy") == 0) {
            Economy_Highest[econ_count++] = list_Student[i].General_note;
        } else if (strcmp(list_Student[i].Department, "Philosophy") == 0) {
            Philosophy_Highest[phil_count++] = list_Student[i].General_note;
        } else if (strcmp(list_Student[i].Department, "Physics") == 0) {
            Physics_Highest[phys_count++] = list_Student[i].General_note;
        }
    }


    for (int i = 0; i < econ_count - 1; i++) {
        for (int j = i + 1; j < econ_count; j++) {
            if (Economy_Highest[i] < Economy_Highest[j]) {
                temp = Economy_Highest[i];
                Economy_Highest[i] = Economy_Highest[j];
                Economy_Highest[j] = temp;
            }
        }
    }
    for (int i = 0; i < phil_count - 1; i++) {
        for (int j = i + 1; j < phil_count; j++) {
            if (Philosophy_Highest[i] < Philosophy_Highest[j]) {
                temp = Philosophy_Highest[i];
                Philosophy_Highest[i] = Philosophy_Highest[j];
                Philosophy_Highest[j] = temp;
            }
        }
    }
    for (int i = 0; i < phys_count - 1; i++) {
        for (int j = i + 1; j < phys_count; j++) {
            if (Physics_Highest[i] < Physics_Highest[j]) {
                temp = Physics_Highest[i];
                Physics_Highest[i] = Physics_Highest[j];
                Physics_Highest[j] = temp;
            }
        }
    }


    printf("Show the top 3 students by department:\n");

    printf("Economy: \n");
    for (int i = 0; i < (econ_count < 3 ? econ_count : 3); i++) {
        printf("Note-%d = %d\n", i+1, Economy_Highest[i]);
    }

    printf("Philosophy: \n");
    for (int i = 0; i < (phil_count < 3 ? phil_count : 3); i++) {
        printf("Note-%d = %d\n", i+1, Philosophy_Highest[i]);
    }

    printf("Physics: \n");
    for (int i = 0; i < (phys_count < 3 ? phys_count : 3); i++) {
        printf("Note-%d = %d\n", i+1, Physics_Highest[i]);
    }
}



void looking_student(){
   
    char first_name[20];
    char last_name[20];
    int unique_number;


    printf("enter student FirstName:");
    scanf("%s", &first_name);
    printf("enter student LastName:");
    scanf("%s", &last_name);
    printf("enter student unique Number:");
    scanf("%d", &unique_number);

    for (int i = 0; i < counter; i++)
    {
        if (list_Student[i].unique_number == unique_number &&  strcmp(list_Student[i].First_name, first_name) == 0 && strcmp(list_Student[i].Last_name, last_name) == 0)
        {
            printf("============[Student:%d]============ \n", i+1);
            printf("Last name: %s \n", list_Student[i].Last_name);
            printf("First name: %s \n", list_Student[i].First_name);
            printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
            printf("Department: %s \n", list_Student[i].Department);
            printf("unique number: %d \n", list_Student[i].unique_number);
            printf("General note: %d \n", list_Student[i].General_note);
        }
        
    }

    printf("=================================== \n");
    
}


void students_department(){
    
   printf("Choose The Department: \n");
   printf("[1]: Economy\n");
   printf("[2]: Philosophy\n");
   printf("[2]: Physics\n");

   char department_student[30];
   printf("Enter the department name: ");
   scanf("%s", &department_student); 

 

   for (int i = 0; i < counter; i++)
   {
      if (strcmp(list_Student[i].Department, department_student) == 0)
      {
        printf("============[Student:%d]============ \n", i+1);
        printf("Last name: %s \n", list_Student[i].Last_name);
        printf("First name: %s \n", list_Student[i].First_name);
        printf("Date of birth: %d - %s - %d \n", list_Student[i].dob.day, list_Student[i].dob.month, list_Student[i].dob.year);
        printf("unique number: %d \n", list_Student[i].unique_number);
        printf("General note: %d \n", list_Student[i].General_note);
      }
       
   }
        printf("=================================== \n");
}


void search(){

    int choice_3;

    printf("Enter your choice:\n");
    printf("[1]: Search for a student by name.\n");
    printf("[2]: View the list of students enrolled in a specific department\n");
    printf("Enter number:");
    scanf("%d", &choice_3);

    switch (choice_3)
    {
    case 1:
        looking_student();
        break;
    case 2:
        students_department();
        break;
    default:
        printf("Invalid choice. Please enter 1 to Search for a student or 2 to View the list of students.\n");
        break;
    }
}


void alphabetical_sorting() {
    struct student_information temp;

    for (int i = 0; i < counter - 1; i++) {
        for (int j = i + 1; j < counter; j++) {
            if (strcmp(list_Student[i].Last_name, list_Student[j].Last_name) > 0) {

                temp = list_Student[i];
                list_Student[i] = list_Student[j];
                list_Student[j] = temp;
            }
        }
    }

    printf("Students sorted alphabetically by last name:\n");
    view_details();
}





void average_sorting(){


    int temp_1;

    for (int i = 0; i < counter; i++)
    {
        notes[i] = list_Student[i].General_note;
    }

    for(int i = 0; i < counter - 1; i++) {

         for(int j = i + 1; j < counter; j++) {
           if(notes[i] < notes[j]) {
              temp_1 = notes[i];
              notes[i] = notes[j];
              notes[j] = temp_1;
             }
           }

    }

    printf("Sorting students by overall average: \n");

    for (int i = 0; i < counter; i++)
    {
        printf("note-%d =  ", i+1);
        printf("%d \n", notes[i]);

    }
    

}

void status_sorting(){

    int temp_2;

    for (int i = 0; i < counter; i++)
    {
        notes[i] = list_Student[i].General_note;
    }

    for(int i = 0; i < counter - 1; i++) {

         for(int j = i + 1; j < counter; j++) {
           if(notes[i] < notes[j]) {
              temp_2 = notes[i];
              notes[i] = notes[j];
              notes[j] = temp_2;
             }
           }

    }

    printf("Sorting students by their success status: \n");

    for (int i = 0; i < counter; i++)
    {
        if (notes[i] > 10)
        {
          printf("note-%d =  ", i+1);
          printf("%d \n", notes[i]);
        }
        
    }
    
}


void students_sort(){

    int choice_4;

    printf("Enter your choice:\n");
    printf("[1]: Alphabetical sorting of students by name\n");
    printf("[2]: Sorting students by overall average, from highest to lowest or vice versa\n");
    printf("[3]: Sorting students by their success status\n");
    printf("Enter number:");
    scanf("%d", &choice_4);

    switch (choice_4)
    {
    case 1:
        alphabetical_sorting();
        break;
    case 2:
        average_sorting();
        break;
    case 3:
        status_sorting();
        break;
    default:
        printf("Invalid choice. Please enter 1 to Search for a student or 2 to View the list of students.\n");
        break;
    }
    
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
                general_average();
                break;
            case 5:
                statistics();
                break;
            case 6:
                search();
                break;
            case 7:
                students_sort();
                break;
            case 0:
                printf("Exit...");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }

    }while(choice_1 != 0);

    return 0;
}

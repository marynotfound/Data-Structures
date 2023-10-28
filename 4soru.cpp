#include <stdio.h>
#include <string.h>

struct Student {
    char first_name[50];
    char last_name[50];
    int id;
};

struct Student students[] = {
    {"Tony", "Stark", 2210},
    {"Doctor", "Strange", 2055},
    {"Bruce", "Banner", 5536},
};

int num_students = sizeof(students) / sizeof(students[0]);

void searchStudentByName(char name[]) {
    int i;
    int found = 0;

    for (i = 0; i < num_students; i++) {
        if (strcmp(students[i].first_name, name) == 0) {
            printf("Student First Name: %s\n", students[i].first_name);
            printf("Student Last Name: %s\n", students[i].last_name);
            printf("Student ID: %d\n", students[i].id);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("Student not found.\n");
    }
}

int main() {
    char searchName[50];
    printf("Enter the name of the student to search for: ");
    scanf("%s", searchName);
    searchStudentByName(searchName);
    return 0;
}


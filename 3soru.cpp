#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
};

struct Student* createStudent(int number, const char* name, int age) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->number = number;
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = NULL;
    return newStudent;
}

struct Student* createStudentList() {
    return NULL;
}

struct Student* addStudent(struct Student* head, int number, const char* name, int age) {
    struct Student* newStudent = createStudent(number, name, age);
    if (head == NULL) {
        return newStudent;
    }
    struct Student* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newStudent;
    return head;
}

void printStudentList(struct Student* head) {
    struct Student* current = head;
    while (current != NULL) {
        printf("Student Number: %d, Name: %s, Age: %d\n", current->number, current->name, current->age);
        current = current->next;
    }
}

int countStudents(struct Student* head) {
    int count = 0;
    struct Student* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    struct Student* studentList = createStudentList();

    studentList = addStudent(studentList, 1, "Tony", 20);
    studentList = addStudent(studentList, 2, "Steve", 22);
    studentList = addStudent(studentList, 3, "Carmen", 21);

    printStudentList(studentList);

    int count = countStudents(studentList);
    printf("Total number of students: %d\n", count);

    while (studentList != NULL) {
        struct Student* toBeDeleted = studentList;
        studentList = studentList->next;
        free(toBeDeleted);
    }

    return 0;
}


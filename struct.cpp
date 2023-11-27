#include <stdio.h>


struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int numStudents;
    printf("Nhap so luong sinh vi�n: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap th�ng tin cho sinh vi�n th? %d:\n", i + 1);
        printf("T�n: ");
        scanf("%s", students[i].name);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("�iem trung b�nh: ");
        scanf("%f", &students[i].gpa);
    }

    printf("\nTh�ng tin sinh vi�n:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh vi�n th? %d:\n", i + 1);
        printf("T�n: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("�iem trung b�nh: %.2f\n", students[i].gpa);
    }

    int studentIndex;
    printf("\nNhap chi so sinh vi�n can cap nhat (tu 0 den %d): ", numStudents - 1);
    scanf("%d", &studentIndex);

    if (studentIndex >= 0 && studentIndex < numStudents) {
        printf("\nCap nhat th�ng tin cho sinh vi�n thu %d:\n", studentIndex + 1);
        printf("T�n: ");
        scanf("%s", students[studentIndex].name);
        printf("Tuoi: ");
        scanf("%d", &students[studentIndex].age);
        printf("�iem trung b�nh: ");
        scanf("%f", &students[studentIndex].gpa);

        printf("\nTh�ng tin sinh vi�n d� duoc cap nhat:\n");
        printf("T�n: %s\n", students[studentIndex].name);
        printf("Tuoi: %d\n", students[studentIndex].age);
        printf("�iem trung b�nh: %.2f\n", students[studentIndex].gpa);
    } else {
        printf("Chi so sinh vi�n kh�ng hop le?.\n");
    }

    return 0;
}


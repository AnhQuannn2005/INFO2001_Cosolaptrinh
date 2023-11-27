#include <stdio.h>


struct Student {
    char name[50];
    int age;
    float gpa;
};

int main() {
    int numStudents;
    printf("Nhap so luong sinh viên: ");
    scanf("%d", &numStudents);

    struct Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        printf("\nNhap thông tin cho sinh viên th? %d:\n", i + 1);
        printf("Tên: ");
        scanf("%s", students[i].name);
        printf("Tuoi: ");
        scanf("%d", &students[i].age);
        printf("Ğiem trung bình: ");
        scanf("%f", &students[i].gpa);
    }

    printf("\nThông tin sinh viên:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Sinh viên th? %d:\n", i + 1);
        printf("Tên: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("Ğiem trung bình: %.2f\n", students[i].gpa);
    }

    int studentIndex;
    printf("\nNhap chi so sinh viên can cap nhat (tu 0 den %d): ", numStudents - 1);
    scanf("%d", &studentIndex);

    if (studentIndex >= 0 && studentIndex < numStudents) {
        printf("\nCap nhat thông tin cho sinh viên thu %d:\n", studentIndex + 1);
        printf("Tên: ");
        scanf("%s", students[studentIndex].name);
        printf("Tuoi: ");
        scanf("%d", &students[studentIndex].age);
        printf("Ğiem trung bình: ");
        scanf("%f", &students[studentIndex].gpa);

        printf("\nThông tin sinh viên dã duoc cap nhat:\n");
        printf("Tên: %s\n", students[studentIndex].name);
        printf("Tuoi: %d\n", students[studentIndex].age);
        printf("Ğiem trung bình: %.2f\n", students[studentIndex].gpa);
    } else {
        printf("Chi so sinh viên không hop le?.\n");
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char position[50];
    float salary;
};

struct Employee employees[100];
int numEmployees = 0;

void addEmployee() {
    struct Employee newEmployee;
    printf("\nNhap thông tin nhân viên:\n");
    printf("Mã nhân viên: ");
    scanf("%d", &newEmployee.id);
    printf("Tên nhân viên: ");
    scanf("%s", newEmployee.name);
    printf("Chuc vu: ");
    scanf("%s", newEmployee.position);
    printf("Luong: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees] = newEmployee;
    numEmployees++;

    printf("Nhân viên dã duoc thêm thành công.\n");
}

void deleteEmployee() {
    int id;
    printf("\nNhap mã nhân viên c?n xóa: ");
    scanf("%d", &id);

    int employeeIndex = -1;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id == id) {
            employeeIndex = i;
            break;
        }
    }

    if (employeeIndex != -1) {
        for (int i = employeeIndex; i < numEmployees - 1; i++) {
            employees[i] = employees[i + 1];
        }
        numEmployees--;
        printf("Nhân viên dã duoc xóa thành công.\n");
    } else {
        printf("Không tìm thay nhân viên có mã %d.\n", id);
    }
}

void displayEmployees() {
    printf("\nThông tin nhân viên:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Nhân viên %d:\n", employees[i].id);
        printf("Tên: %s\n", employees[i].name);
        printf("Chuc vu: %s\n", employees[i].position);
        printf("Luong: %.2f\n", employees[i].salary);
        printf("--------------------\n");
    }
}

int compareByName(const void* a, const void* b) {
    const struct Employee* employeeA = (const struct Employee*)a;
    const struct Employee* employeeB = (const struct Employee*)b;
    return strcmp(employeeA->name, employeeB->name);
}

void sortEmployeesByName() {
    qsort(employees, numEmployees, sizeof(struct Employee), compareByName);
    printf("\nDanh sách nhân viên dã duoc sap xep theo tên.\n");
}

int main() {
    int choice;

    do {
        printf("\nQuan lý nhân su\n");
        printf("1. Thêm nhân viên\n");
        printf("2. Xóa nhân viên\n");
        printf("3. Hien thi danh sách nhân viên\n");
        printf("4. Sap xep nhân viên theo tên\n");
        printf("0. Thoát\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
break;
            case 3:
                displayEmployees();
                break;
            case 4:
                sortEmployeesByName();
                break;
            case 0:
                printf("Ket thúc chuong trình.\n");
                break;
            default:
                printf("Chuc nang không hop le. Vui lòng chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

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
    printf("\nNhap th�ng tin nh�n vi�n:\n");
    printf("M� nh�n vi�n: ");
    scanf("%d", &newEmployee.id);
    printf("T�n nh�n vi�n: ");
    scanf("%s", newEmployee.name);
    printf("Chuc vu: ");
    scanf("%s", newEmployee.position);
    printf("Luong: ");
    scanf("%f", &newEmployee.salary);

    employees[numEmployees] = newEmployee;
    numEmployees++;

    printf("Nh�n vi�n d� duoc th�m th�nh c�ng.\n");
}

void deleteEmployee() {
    int id;
    printf("\nNhap m� nh�n vi�n c?n x�a: ");
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
        printf("Nh�n vi�n d� duoc x�a th�nh c�ng.\n");
    } else {
        printf("Kh�ng t�m thay nh�n vi�n c� m� %d.\n", id);
    }
}

void displayEmployees() {
    printf("\nTh�ng tin nh�n vi�n:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Nh�n vi�n %d:\n", employees[i].id);
        printf("T�n: %s\n", employees[i].name);
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
    printf("\nDanh s�ch nh�n vi�n d� duoc sap xep theo t�n.\n");
}

int main() {
    int choice;

    do {
        printf("\nQuan l� nh�n su\n");
        printf("1. Th�m nh�n vi�n\n");
        printf("2. X�a nh�n vi�n\n");
        printf("3. Hien thi danh s�ch nh�n vi�n\n");
        printf("4. Sap xep nh�n vi�n theo t�n\n");
        printf("0. Tho�t\n");
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
                printf("Ket th�c chuong tr�nh.\n");
                break;
            default:
                printf("Chuc nang kh�ng hop le. Vui l�ng chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

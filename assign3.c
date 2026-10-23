#include <stdio.h>

struct Student {
    char name[50];
    int rollNo;
    char division;
};

void display(struct Student s) {
    printf("Name     : %s\n", s.name);
    printf("Roll No  : %d\n", s.rollNo);
    printf("Division : %c\n", s.division);
    printf("--------------------------\n");
}

int linearSearch(struct Student arr[], int n, int roll) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i].rollNo == roll) {
            return i;
        }
    }
    return -1;
}

int binarySearch(struct Student arr[], int n, int roll) {
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid].rollNo == roll) {
            return mid;
        }
        else if (arr[mid].rollNo < roll) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

void selectionSort(struct Student arr[], int n) {
    int i, j, minIndex;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j].rollNo < arr[minIndex].rollNo) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void bubbleSort(struct Student arr[], int n) {
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].rollNo > arr[j + 1].rollNo) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(struct Student arr[], int n) {
    int i, j;
    struct Student key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].rollNo > key.rollNo) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    struct Student students[100];
    int n, i, roll, result;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter division: ");
        scanf(" %c", &students[i].division);
    }

    for (i = 0; i < n; i++) {
        display(students[i]);
    }

    printf("Enter roll number for linear search: ");
    scanf("%d", &roll);

    result = linearSearch(students, n, roll);

    if (result != -1)
        display(students[result]);
    else
        printf("Student not found\n");
    selectionSort(students, n);
    
    for (i = 0; i < n; i++) {
        display(students[i]);
    }
    printf("Enter roll number for binary search: ");
    scanf("%d", &roll);

    result = binarySearch(students, n, roll);

    if (result != -1)
        display(students[result]);
    else
        printf("Student not found\n");

    bubbleSort(students, n);

    for (i = 0; i < n; i++) {
        display(students[i]);
    }

    insertionSort(students, n);

    for (i = 0; i < n; i++) {
        display(students[i]);
    }

    return 0;
}
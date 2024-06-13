#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//author: Frank Onyema Orji

// Define the structure for student details
typedef struct {
    char fullName[100];
    float grade;
} Student;

// Function to merge two halves
void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Student* L = (Student*)malloc(n1 * sizeof(Student));
    Student* R = (Student*)malloc(n2 * sizeof(Student));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].grade >= R[j].grade) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Merge sort function
void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student* students = (Student*)malloc(n * sizeof(Student));

    for (int i = 0; i < n; i++) {
        printf("Enter full name of student %d: ", i + 1);
        scanf(" %[^\n]", students[i].fullName);
        printf("Enter grade of student %d: ", i + 1);
        scanf("%f", &students[i].grade);
    }

    mergeSort(students, 0, n - 1);

    printf("\nSorted list of students by grade (highest to lowest):\n");
    for (int i = 0; i < n; i++) {
        printf("%s: %.2f\n", students[i].fullName, students[i].grade);
    }

    free(students);
    return 0;
}

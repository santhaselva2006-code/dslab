#include <stdio.h>

#define SIZE 50

struct Student {
    char name[30];
    int rollno;
    int sub[3];
};

int main()
{
    int i, j, max, total, n, a[SIZE], ni;
    struct Student st[SIZE];

    printf("Enter how many students: ");
    scanf("%d", &n);

    if (n <= 0 || n > SIZE) {
        printf("Invalid number of students\n");
        return 1;
    }

    /* Read student names and roll numbers */
    for (i = 0; i < n; i++) {
        printf("\nEnter name and roll number for student %d: ", i);
        scanf("%29s", st[i].name);
        scanf("%d", &st[i].rollno);
    }

    /* Read marks in three subjects */
    for (i = 0; i < n; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter marks of student %d for subject %d: ",
                   i, j);
            scanf("%d", &st[i].sub[j]);
        }
    }

    /* Calculate total marks of each student */
    for (i = 0; i < n; i++) {
        total = 0;

        for (j = 0; j < 3; j++) {
            total = total + st[i].sub[j];
        }

        printf("\nTotal marks obtained by student %s are %d\n",
               st[i].name, total);

        a[i] = total;
    }

    /* Find the highest marks in each subject */
    for (j = 0; j < 3; j++) {
        max = st[0].sub[j];
        ni = 0;

        for (i = 1; i < n; i++) {
            if (max < st[i].sub[j]) {
                max = st[i].sub[j];
                ni = i;
            }
        }

        printf("Student %s got maximum marks = %d in Subject: %d\n",
               st[ni].name, max, j);
    }

    /* Find the student with the highest total */
    max = a[0];
    ni = 0;

    for (i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
            ni = i;
        }
    }

    printf("\n%s obtained the total highest marks.\n",
           st[ni].name);

    return 0;
}
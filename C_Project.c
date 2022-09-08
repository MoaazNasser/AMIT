#include <stdio.h>
#include <stdbool.h>
#include "C_Project.h"

typedef unsigned int uint8;

struct student
{
    int Student_ID;
    int Student_Year;
    int Course1_ID;
    int Course1_Grade;
    int Course2_ID;
    int Course2_Grade;
    int Course3_ID;
    int Course3_Grade;

    struct student * next;

};

typedef struct student st;
st * head;
uint8 * subjects;
uint8 * grades;

enum SDB_Full {Empty, Full=10};

uint8 Entries_Num;

int main()
{
    printf("\n        * * * * * * Welcome To Students Database * * * * * *\n\n");

    while(1)
    {

        //SDB_GetUsedSize();
        printf("Please choose an operation.\n\n");
        printf("1: Add a student data.\n");
        printf("2: Delete a student data.\n");
        printf("3: Read a student data.\n");
        printf("4: Get students' count and IDs.\n");
        printf("5: Searching for ID existance.\n");
        printf("6: Exit\n");
        printf("\n");

        uint8 op;
        printf("Choosed operation: ");
        scanf("%d", &op);
        printf("\n\n");

        switch (op)
        {
        case 1:
            if (SDB_AddEntry() == 1)
                printf("\n ******Students are added. ******\n\n");
            else
                printf("Students aren't added, Please try again ! ******\n\n\n");
            break;

        case 2:
            if(head == NULL)
                printf("****** List is already empty !, Please add students first. ******\n\n\n");
            else
            {
                printf("Enter student ID which you want to delete\n");
                uint8 del_id;
                scanf("%d",&del_id);
                SDB_DeleteEntry(del_id);
                printf("\n ******Student data is deleted. ******\n\n\n");
            }
            break;

        case 3:
            if(head == NULL)
                printf("****** List is already empty !, Please add students first. ******\n\n\n");
            else
            {
                printf("Enter student ID which you want to view his data\n");
                uint8 read_id;
                scanf("%d",&read_id);
                if(!SDB_ReadEntry(read_id))
                    printf("****** No student is found with this ID, Please try again ! ******\n\n\n");
            }
            break;

        case 4:
            // Get count & IDs
            break;

        case 5:
            if(head == NULL)
                printf("****** List is already empty !, Please add students first. ******\n\n");
            else
            {
                printf("Enter student ID which you want to search\n");
                uint8 search_id;
                scanf("%d",&search_id);
                if (SDB_IsIdExist(search_id) == 1)
                    printf("\n\n****** Student is found. ******\n\n");
                else
                    printf("\n\n****** Student isn't found. ******\n\n");
            }

            break;


       /* case 6:
            if (Entries_Num>0)
                SDB_GetUsedSize();
            else
                printf("List is empty !\n\n\n");*/
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\n****** Please enter a valid operation ! ******\n\n\n");
        }

    }
}


uint8 SDB_GetUsedSize(void)
{
    return printf("%d", Entries_Num);
}

bool SDB_IsFull(void)
{
    if (Entries_Num > Full)
    {
        return 1;
    }
    else
        return 0;
}

bool SDB_AddEntry()
{

    st * new_st;

    printf("Please enter number of students required to be added (1 - 10): ");
    scanf("%d", &Entries_Num);

    if (SDB_IsFull())
    {
        printf("\n\n****** Maximum entries number is 10, ");
        return 0;
    }

    if (Entries_Num == 0)
    {
        printf("\n\n****** Enter a number from 1 to 10, ");
        return 0;
    }


    for(int i = 0; i < Entries_Num; i++)
    {
        new_st = malloc(sizeof(st));

        printf("\nStudent %d ID: ", i+1);
        scanf("%d", &(new_st->Student_ID));
        printf("Student %d Year: ", i+1);
        scanf("%d", &(new_st->Student_Year));

        subjects = &new_st->Course1_ID;
        printf("Course 1 ID: ");
        scanf("%d", &(subjects));
        subjects ++;

        grades = &new_st->Course1_Grade;
        printf("Course 1 Grade (0 - 100): ");
        scanf("%d", &(grades));
        grades ++;

        subjects = &new_st->Course2_ID;
        printf("Course 2 ID: ");
        scanf("%d", &(subjects));
        subjects ++;

        grades = &new_st->Course2_Grade;
        printf("Course 2 Grade (0 - 100): ");
        scanf("%d", &(grades));
        grades ++;

        subjects = &new_st->Course3_ID;
        printf("Course 3 ID: ");
        scanf("%d", &(subjects));
        subjects ++;

        grades = &new_st->Course3_Grade;
        printf("Course 3 Grade (0 - 100): ");
        scanf("%d", &(grades));
        grades ++;

        new_st -> next = head;
        head = new_st;
    }

    return 1;
}

void SDB_DeleteEntry(uint8 id)
{
    st * temp = head;
    st * prev = head;
    if (temp != NULL && temp -> Student_ID == id)
    {
        head = temp->next;
        free(temp);
    }

    while (temp != NULL && temp -> Student_ID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return;
    }

    prev -> next = temp -> next;
    free(temp);

}

bool SDB_ReadEntry(uint8 id)
{
    st * temp;
    temp = head;
    uint8 i = 0, flag;

    if(temp == NULL)
    {
        printf("Empty list, ");
        return 0;
    }
    else
    {

        while (temp != NULL)
        {
            if(temp -> Student_ID == id)
            {

                printf("\nStudent ID: %d ",temp->Student_ID);
                printf("\nStudent Year: %d ",temp->Student_Year);

                subjects = &temp->Course1_ID;
                printf("\nCourse 1 ID: %d", subjects);
                subjects ++;

                grades = &temp->Course1_Grade;
                printf("\nCourse 1 Grade: %d", grades);
                grades ++;

                subjects = &temp->Course2_ID;
                printf("\nCourse 2 ID: %d", subjects);
                subjects ++;

                grades = &temp->Course2_Grade;
                printf("\nCourse 2 Grade: %d", grades);
                grades ++;

                subjects = &temp->Course3_ID;
                printf("\nCourse 3 ID: %d", subjects);
                subjects ++;

                grades = &temp->Course3_Grade;
                printf("\nCourse 3 Grade: %d\n\n", grades);
                grades ++;

                flag = 0;
                return 1;
            }
            else
            {
                flag = 1;
            }
            i++;
            temp = temp -> next;
        }
        if(flag == 1)
        {
            return 0;
        }
    }


}



bool SDB_IsIdExist(uint8 id)
{
    st * temp;
    temp = head;
    uint8 i = 0, flag;

    if(temp == NULL)
    {
        printf("Empty list, ");
        return 0;
    }
    else
    {

        while (temp != NULL)
        {
            if(temp -> Student_ID == id)
            {
                flag = 0;
                return 1;
            }
            else
            {
                flag = 1;
            }
            i++;
            temp = temp -> next;
        }
        if(flag == 1)
        {
            return 0;
        }
    }

}

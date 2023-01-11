//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "acp.h"

//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()
{


 printf(" \n\n\n\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *");
		printf("\n\n\t\t\t\t\t    *    MADE BY George Emad    *");
		printf("\n\n\t\t\t\t\t    *          Welcome          *");
		printf("\n\n\t\t\t\t\t    *       Amit learning       *");
		printf("\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue ");

		for(int i=0; i<7; i++)
        {
             printf(".");
				 Sleep(100);
        }




 getch();
}

int main() {
    uint8 choose=0,i = 0,entryno=0,cont1,value1=0,value2=0,id2 = 0,cont2=0,value4=0,id5=0,value6=0,id6=0,list[z];
menu:

printf(" \n\n\n\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *");
		printf("\n\n\t\t\t\t\t    *    MADE BY George Emad    *");
		printf("\n\n\t\t\t\t\t    *          Welcome          *");
		printf("\n\n\t\t\t\t\t    *       Amit learning       *");
		printf("\n\n\t\t\t\t\t    *   *   *   *   *   *   *   *\n\n\n");
		printf("\n\n\n\n\n\t\t\t\t\tPress any key to continue ");

		for(int i=0; i<7; i++)
        {
             printf(".");
				 Sleep(100);
        }

    printf("\n\t\t-------Welcome to student data base-------");
    printf("Please select your operation\n");
    printf("\t\t 1-Add new entry\n");
    printf("\t\t 2-Read an entry\n");
    printf("\t\t 3-Get the number of entries\n");
    printf("\t\t 4-Check if the database is full\n");
    printf("\t\t 5-Delete entry\n");
    printf("\t\t 6-Check if ID exists full\n");
    printf("\t\t 7-Get the list of IDs of the students\n");
    printf("\t\t 8-End program\n");
    scanf("%lu",&choose);
    switch(choose){
        case 1 :
        choice1:
                for(i=0;i<10;i++){
                    ++entryno;
                    printf("Pleae enter student %lu ID:\n ",i+1);
                    scanf("%lu",&x[i].student_ID);
                    printf("Pleae enter student %lu year:\n ",i+1);
                    scanf("%lu",&x[i].student_year);
                    printf("Pleae enter course 1 ID :\n ");
                    scanf("%lu",&x[i].course1_ID);
                    printf("Pleae enter course 1 grade :\n ");
                    scanf("%lu",&x[i].course1_grade);
                    printf("Pleae enter course 2 ID :\n ");
                    scanf("%lu",&x[i].course2_ID);
                    printf("Pleae enter course 2 grade :\n ");
                    scanf("%lu",&x[i].course2_grade);
                    printf("Pleae enter course 3 ID :\n ");
                    scanf("%lu",&x[i].course3_ID);
                    printf("Pleae enter course 3 grade :\n ");
                    scanf("%lu",&x[i].course3_grade);
                    value1= SDB_AddEntry(x[i].student_ID, x[i].student_year, &x[i].course1_ID, &x[i].course2_ID, &x[i].course3_ID, &x[i].course1_grade, &x[i].course2_grade, &x[i].course3_grade);
                    if (value1 ==0){
                        printf("Error in entered data\n");
                        goto choice1;
                    }
                    printf("Do you want to add another entry (Yes = 1\\No=0)? \n");
                    scanf("%lu",&cont1);
                    if (cont1==1)
                    {
                        continue;
                    }
                    else if (cont1==0){
                        break;

                    }

                }
            z=entryno;
                goto menu;
            break;
        case 2 :
        choice2:
            printf("Enter the ID of the entry you want :  ");
            scanf("%lu",&id2);
            value2=SDB_ReadEntry(id2, &x[i].student_year, &x[i].course1_ID, &x[i].course2_ID, &x[i].course3_ID, &x[i].course1_grade, &x[i].course2_grade, &x[i].course3_grade);
            if  (value2==0){
                printf("Entery doesn't exist\n");
                printf("Go back to menu click 0 \nTry agian click 1\n");
                scanf("%lu",&cont2);
                if (cont2==0){
                    goto menu;
                }
                else {
                    goto choice2;
                }
            }
            goto menu;
            break;
        case 3 : printf("the number of entries is :%lu \n",SDB_GetUsedSize());
            goto menu;
            break;
        case 4 : value4=SDB_isFull();
            if (value4==1)
            {
                printf("Database is full\n");
            }
            else{
                printf("Database is not full\n");
            }
            goto menu;
            break;
        case 5:printf("Enter the id of the entry you want to delete \n");
            scanf("%lu",&id5);
            SDB_DeleteEntry(id5);
            printf("Entry deleted successfully \n");
            entryno--;
            z=entryno;
            goto menu;
            break;
        case 6 : printf("enter the ID  you want to check : \n");
            scanf("%lu",&id6);
           value6= SDB_IsIdExist(id6);
            if (value6==0){
                printf("ID doesn't exist \n");
            }
            else if (value6==1){
                printf("ID exist\n");
            }
            goto menu;
            break;
        case 7:SDB_GetIdList(&z, list);
            goto menu;
            break;
        default:
            printf("See you\n");
            return 0;
            break;
    }


///
}
// Description :check if the data base is full
bool SDB_isFull(void)
{
    if (z==10)
    {
        return 1;
    }
    else {
        return 0;
        //return vale : return 1 if the data base is full , otherwise 0
    }
}

// get number of entries in DB
uint8 SDB_GetUsedSize(void)
{
    return z;

// Return no of entries
}
// add a new entry  to Db
// input : id student
// year
// subject pointer to 3 subjects iDs , each id subject is a unit8 value
//grades : pointer to 3
// max eange of grade is 100
bool SDB_AddEntry(uint8 id,uint8 year,uint8* s1,uint8* s2,uint8* s3,uint8* g1,uint8* g2,uint8* g3)
{
    if(*g1>=0 && *g1<=100 && *g2>=0 && *g2<=100 && *g3>=0 && *g3<=100 )
    {
        return 1;
        }
    else {
        return 0;
    }
}

// delete the entry with given Id
void SDB_DeleteEntry(uint8 id){
    uint8 i;
    for(i=0;i<10;i++){
        if (x[i].student_ID==id){
            for(i=0;i<10;i++){
            x[i]=x[i+1];
            }
        }
    }
}


//
bool SDB_ReadEntry(uint8 id,uint8* year,uint8* s1 ,uint8* s2,uint8* s3,uint8* g1,uint8* g2,uint8* g3)
{
    uint8 i,v = 0;
    for(i=0;i<z;i++)
    {
if  (x[i].student_ID==id)
{
    v=1;
    printf("Entry exists : \n");
    printf("Student year is :%lu \n",x[i].student_year);
    printf("course 1 ID:%lu \n",x[i].course1_ID);
    printf("course 1 grade:%lu \n",x[i].course1_grade);
    printf("course 2 ID:%lu \n",x[i].course2_ID);
    printf("course 2 grade:%lu \n",x[i].course2_grade);
    printf("course 3 ID:%lu \n",x[i].course3_ID);
    printf("course 3 grade:%lu \n",x[i].course3_grade);

}
else  {
    v=0;
}
    }
    return v;
}
void SDB_GetIdList(uint8* counter ,uint8* list){
    uint8 i;
    printf("list of ID : \n");
    for(i=0;i<*counter;i++)
    {
        list[i]=x[i].student_ID;
        printf("student %lu ID is :  %lu \n",i+1,list[i]);
    }


}

bool SDB_IsIdExist(uint8 id)
{
    uint8 i,v = 0;
    for(i=0;i<z;i++)
    {
        if (x[i].student_ID==id)
        {
            v=1;
            break;
        }
        else{
            v=0;
        }
    }
    return v;
}

//
//  acp.h
//  project
//
//  Created by george  
//

#ifndef acp_h
#define acp_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
typedef unsigned long int uint8;
struct SimpleDb {
    uint8 student_ID;
    uint8 student_year;
    uint8 course1_ID;
    uint8 course1_grade;
    uint8 course2_ID;
    uint8 course2_grade;
    uint8 course3_ID;
    uint8 course3_grade;
}x[10];
uint8 z;
bool SDB_AddEntry(uint8,uint8,uint8*,uint8*,uint8*,uint8*,uint8*,uint8*);
bool SDB_isFull(void);
uint8 SDB_GetUsedSize(void);
void SDB_DeleteEntry(uint8);
void SDB_GetIdList(uint8* ,uint8*);
bool SDB_IsIdExist(uint8);
bool SDB_ReadEntry(uint8,uint8*,uint8*,uint8*,uint8*,uint8*,uint8*,uint8*);




#endif /* acp_h */

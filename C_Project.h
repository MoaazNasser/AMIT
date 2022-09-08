#ifndef C_PROJECT_H_INCLUDED
#define C_PROJECT_H_INCLUDED

#include "C_Project_Fun.c"

typedef unsigned int uint8;

bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(void);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id);
void SDB_GetIdList(uint8 * count, uint8 * list);
bool SDB_IsIdExist(uint8 id);

#endif // C_PROJECT_H_INCLUDED

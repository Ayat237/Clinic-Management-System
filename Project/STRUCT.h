/*
===================================================================================================
* Auther : Ayat Mohamed MOhamed 
* Object : STRUCT file
* date : 15/8/2023
* STRUCT.h
===================================================================================================
*/



#ifndef STRUCT_H_
#define STRUCT_H_
#include "STD_TYPES.h"
// structure for patient
typedef struct patientNode patient;
typedef struct patientNode
{
	uint32 ID;
	uint8 name[20];
	uint8 age;
	uint8 gender;
	uint8 date;
	patient *nextPatient;
}patient;


#endif

/*
===================================================================================================
* Auther : Ayat Mohamed MOhamed 
* Object : Admin file
* date : 15/8/2023
* Admin.h
===================================================================================================
*/

#ifndef ADMIN_AND_USER_H_
#define ADMIN_AND_USER_H_

#include "STRUCT.h"

// ID search function.
patient *ID_Patient(uint32 id);

// function add patient 
void Add_Patient(void);

// function print all data about patient
void Print_Patient_Node(void);

//function to print patient data after edit
void Edit_Display(uint32 id);

// function edit all data about patient
void Edit_Patient(uint32 id);

// function is display all slots is avalible 
void Avalible_Slots(void);

// function to check if reservation is empty or not 
void Check_Reserved(uint32 id);

// function to make a reservation and it will not appear in the next patient reservation..
void Resevation(uint32 id, uint8 choice);

// function to cancel the reservation and it will appear in the next patient reservation.
void Cancel_Resrvation(uint32 id, uint8 choice);

void View_Reservations(uint32 id);
#endif

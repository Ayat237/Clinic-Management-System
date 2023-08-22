/*
===================================================================================================
 * Auther : Ayat Mohamed MOhamed
 * Object : Admin file
 * date : 15/8/2023
 * Admin.c
===================================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Admin_And_User.h"
#include "STD_TYPES.h"
#include "STRUCT.h"



patient *Head = NULL;
patient *Tail = NULL;
patient *Slot[5] = {NULL};

/*==================================================================================================*/
/*************************************** ID_Patient function ****************************************/
/*==================================================================================================*/


// ID search function.
patient *ID_Patient(uint32 id)
{
	// define node pointer from struct patient
	patient *PNode;

	// Assign the head to PNode 
	PNode = Head;

	// while next node not equal null ,that mean the id is exist , else the id id not exist.
	while(PNode != NULL)
	{
		if(PNode->ID == id)
		{
			// return all data about this id.
			return PNode;
		}
		// increase the node one by one .
		PNode = PNode->nextPatient;
	}

	// id not exist

	return NULL;
}

/*==================================================================================================*/
/*************************************** Add_Patient function ***************************************/
/*==================================================================================================*/


// add a new patient 
void Add_Patient(void)
{
	patient *NewPatient;
	//creat a dynamic memory alloction.
	NewPatient =(patient *)malloc(sizeof(patient));

	uint32 id ,iteration;

	printf("Enter the ID number to add patient :) ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&id);

	//condtion to check the id not repeated .
	if(ID_Patient(id) == NULL)
	{
		//write the patient data.
		NewPatient->ID = id;

		printf("Enter a patient Name  :) ");
		fflush(stdin);
		fflush(stdout);
		gets(NewPatient->name);
		printf("Enter a patient Age  :) ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&(NewPatient->age));

		printf("Enter \'M\' if patient is Male or \'F\' if patient is Famale :) ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&(NewPatient->gender));

		//check if a patient exist or not 
		if(Head == NULL)
		{
			Head = NewPatient;
			Tail = NewPatient;
			NewPatient->nextPatient = NULL;
		}
		else
		{
			// there are patients
			Tail->nextPatient = NewPatient;
			Tail = NewPatient;
			Tail->nextPatient = NULL;
		}

	}
	else
	{
		// if the id is repeated.
		printf("Sorry :(\nThis ID is already exist.\n");
	}

}

/*==================================================================================================*/
/********************************** Print_Patient_Node function *************************************/
/*==================================================================================================*/


//print the patient data
void Print_Patient_Node(void)
{
	patient *NewPatient;
	uint32 id;

	printf("Enter the ID of patient to print patient data : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&id);

	// check if id not equal NULL.
	if(ID_Patient(id) != NULL)
	{
		// assign the returned from ID_Patient to the node;
		NewPatient = ID_Patient(id);

		// print the partient data
		printf("****************************** PATIENT DATA '~' *****************************\n");
		printf("NAME   : %s \n", NewPatient->name);
		printf("AGE    : %d \n", NewPatient->age);
		printf("GENDER : %c \n", NewPatient->gender);
		printf("DATE   : %d \n", NewPatient->date);
		printf("ID     : %d \n", NewPatient->ID);
	}
	else
	{
		// if id equal NULL.
		printf("The ID is not found ,This patient is not registered :(\n");
	}

}

/*==================================================================================================*/
/************************************ Edit_Patient function *****************************************/
/*==================================================================================================*/

// function to edit the old data of patient 
void Edit_Patient(uint32 id)
{
	patient *DataPatient;

	// choice one for the old date and choice 2 for new date
	uint8 choiceOld, choiceNew;

	// check if id not equal NULL.
	if(ID_Patient(id) != NULL)
	{

		printf("**************************** OLD PATIENT DATA '~' ****************************\n");

		// print the last data is edited.
		Edit_Display(id);

		// assign the returned from ID_Patient to the node;
		DataPatient = ID_Patient(id);

		//reEnter the data.
		printf("Enter new patient Name  :) ");
		fflush(stdin);
		fflush(stdout);
		gets(DataPatient->name);

		printf("Enter new patient Age :) ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&DataPatient->age);

		printf("Enter a new patient Gender :) ");
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&DataPatient->gender);

		//Add new date
		printf("new patient Date :) \n");

		// print the available slot .
		Avalible_Slots();
		printf("Enter the old date : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&choiceOld);

		// cancel the old date to reserve the new date.
		Cancel_Resrvation(id,choiceOld);
		printf("Enter the new date : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&choiceNew);

		// check if this id is reserved previously or not .
		Check_Reserved(id);

		//if the  id has not been reserved previously,a date will be reserved for it .
		Resevation(id ,choiceNew);
	}
	else
	{
		// if the id equal null .
		printf("The ID is not found ,This patient is not registered :(\n");
	}
}

/*==================================================================================================*/
/************************************ Edit_Display function *****************************************/
/*==================================================================================================*/

//function to print patient data after edit
void Edit_Display(uint32 id)
{
	patient *NewPatient;

	// check if id not equal NULL.

	if(ID_Patient(id) != NULL)
	{
		// assign the returned data from ID_Patient to the node;
		NewPatient = ID_Patient(id);

		printf("****************************** PATIENT DATA '~' *****************************\n");

		printf("NAME   : %s \n", NewPatient->name);
		printf("AGE    : %d \n", NewPatient->age);
		printf("GENDER : %c \n", NewPatient->gender);
		printf("DATE   : %d \n", NewPatient->date);
		printf("ID     : %d \n", NewPatient->ID);
	}
	else
	{
		// if the id equal null .
		printf("The ID is not found ,This patient is not registered :(\n");
	}

}

/*==================================================================================================*/
/************************************ Avalible_Slots function ***************************************/
/*==================================================================================================*/


// function to print the available slots ,if slot equal NULL that mean the slot is empty.
void Avalible_Slots(void)
{
	printf("***************************** Available Slots *******************************\n");

	// check if date 1 is not reserved.
	if(Slot[0] == NULL)
		printf("The first date from  \" 2pm to 2:30pm \". \n");

	// check if date 2 is not reserved.
	if(Slot[1] == NULL)
		printf("The second date from \" 2:30pm to 3pm \". \n");

	// check if date 3 is not reserved.
	if(Slot[2] == NULL)
		printf("The third date from  \" 3pm to 3:30pm \". \n");

	// check if date 4 is not reserved.
	if(Slot[3] == NULL)
		printf("The fouth date from  \" 4pm to 4:30pm \". \n");

	// check if date 5 is not reserved.
	if(Slot[4] == NULL)
		printf("The fifth date from  \" 4:30pm to 5pm \". \n");
}

/*==================================================================================================*/
/************************************ Check_Reserved function ***************************************/
/*==================================================================================================*/

// function to check if reservation is empty or not
void Check_Reserved(uint32 id)
{
	patient *PNode;

	PNode = ID_Patient(id);

	// if the node not equal NULL.
	if(PNode != NULL)
	{
		// check if the node is reserved the date no 1;
		if(Slot[0] == PNode)
		{

			printf("This ID(%d) is already reserved. \n",PNode->ID);

			// print the patient file ,whose reserve this date.
			printf("************************ Patient old file ******************************\n");
			Edit_Display(id);

		}
		// check if the node is reserved the date no 2;
		else if(Slot[1] == PNode)
		{
			printf("This ID(%d) is already reserved. \n",PNode->ID);
			printf("************************ Patient old file ******************************\n");
			Edit_Display(id);
		}
		// check if the node is reserved the date no 3;
		else if(Slot[2] == PNode)
		{
			printf("This ID(%d) is already reserved. \n",PNode->ID);

			printf("************************ Patient old file ******************************\n");
			Edit_Display(id);
		}
		// check if the node is reserved the date no 4;
		else if(Slot[3] == PNode)
		{
			printf("This ID(%d) is already reserved. \n",PNode->ID);

			printf("************************ Patient old file ******************************\n");
			Edit_Display(id);
		}
		// check if the node is reserved the date no 5;
		else if(Slot[4] == PNode)
		{
			printf("This ID(%d) is already reserved. \n",PNode->ID);

			printf("************************ Patient old file ******************************\n");
			Edit_Display(id);
		}
		else
		{
			//do not any thing .
		}
	}
	else
	{
		// if the id equal null.
		printf("This ID not exist :(\n");
	}

}
/*==================================================================================================*/
/**************************************** Reservation function ***************************************/
/*==================================================================================================*/

// function to make a reservation and it will not appear in the next patient reservation..
void Resevation(uint32 id , uint8 choice)
{
	patient *PNode;


	// check if id not return NULL.
	if(ID_Patient(id) != NULL)
	{
		// check on date
		switch(choice)
		{
		case 1:
			//assign 1 to the date;
			PNode->date = 1;

			// now , date 1 is reserved.
			Slot[0] = PNode;
			printf("************************ THANKS FOR RESERVATION ******************************\n");
			break;
		case 2:
			PNode->date = 2;

			// now , date 2 is reserved.
			Slot[1] = PNode;
			printf("************************ THANKS FOR RESERVATION ******************************\n");
			break;
		case 3:
			PNode->date = 3;

			// now , date 3 is reserved.
			Slot[2] = PNode;
			printf("************************ THANKS FOR RESERVATION ******************************\n");
			break;
		case 4:
			PNode->date = 4;

			// now , date 4 is reserved.
			Slot[3] = PNode;
			printf("************************ THANKS FOR RESERVATION ******************************\n");
			break;
		case 5:
			PNode->date = 5;

			// now , date 5 is reserved.
			Slot[4] = PNode;
			printf("************************ THANKS FOR RESERVATION ******************************\n");
			break;
		}
	}
	else
	{
		printf("The ID is not found ,This patient is not registered :(\n");
	}
}

/*==================================================================================================*/
/*********************************** Cancel_Resrvation function *************************************/
/*==================================================================================================*/


// function to cancel the reservation and it will appear in the next patient reservation.
void Cancel_Resrvation(uint32 id ,uint8 choice)
{
	patient *PNode;

	PNode = ID_Patient(id);

	// assign the choice into the date of the node.
	PNode->date = choice;

	// if the date of node =1
	if(PNode->date == 1)
	{
		// put in index[1] null to cancel the registration of this date.
		Slot[0] = NULL;
		printf("your reservation is canceled \n");
	}
	else if(PNode->date == 2)
	{
		// put in index[2] null to cancel the registration of this date.
		Slot[1] = NULL;
		printf("your reservation is canceled \n");
	}
	else if(PNode->date == 3)
	{
		// put in index[3] null to cancel the registration of this date.
		Slot[2] = NULL;
		printf("your reservation is canceled \n");
	}
	else if(PNode->date == 4)
	{
		// put in index[4] null to cancel the registration of this date.
		Slot[3] = NULL;
		printf("your reservation is canceled \n");
	}
	else if(PNode->date == 5)
	{
		// put in index[5] null to cancel the registration of this date.
		Slot[4] = NULL;
		printf("your reservation is canceled \n");
	}

}

/*==================================================================================================*/
/*********************************** View_Reservations function *************************************/
/*==================================================================================================*/

// view all todays reservation
void View_Reservations(uint32 id)
{
	// make a node of struct
	patient *NewPatient;

	// check if id not equal null
	if(ID_Patient(id) != NULL)
	{
		// return the data related to patient and assign it in the node.
		NewPatient = ID_Patient(id);

		//print all available slots.
		Avalible_Slots();

		//check if the date 1 is not null ,this mean that the date is reserved by patient.
		if(Slot[0] != NULL)
		{
			printf("the patient reserve slot number %d\n",Slot[0]->date);
		}

		//check if the date 2 is not null ,this mean that the date is reserved by patient.
		if(Slot[1] != NULL)
		{
			printf("the patient reserve slot number %d\n",Slot[1]->date);
		}

		//check if the date 3 is not null ,this mean that the date is reserved by patient.
		if(Slot[2] != NULL)
		{
			printf("the patient reserve slot number %d\n",Slot[2]->date);
		}

		//check if the date 4 is not null ,this mean that the date is reserved by patient.
		if(Slot[3] != NULL)
		{
			printf("the patient reserve slot number %d\n",Slot[3]->date);
		}
		//check if the date 4 is not null ,this mean that the date is reserved by patient.
		if(Slot[4] != NULL)
		{
			printf("the patient reserve slot number %d\n",Slot[4]->date);
		}
	}
	else
	{
		// if the id equal null.
		printf("Your ID not Exist :( \n");
	}

}




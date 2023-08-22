/*
===================================================================================================
 * Auther : Ayat Mohamed MOhamed
 * Object : Clinic mangement system
 * date : 15/8/2023
 * main.c
===================================================================================================
 */


//***************************************** Link Section ********************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Admin_And_User.h"
#include "STD_TYPES.h"
#include "MODE.h"
#include "STRUCT.h"
//**************************************** Defintion Section ****************************************
// size of array mode
#define ModeSize 5

//default password
#define Password 1234

//***************************************** Main Section ********************************************

int main ()
{
	uint8 mode[ModeSize];
	uint32 pass , iteration;
	uint32 choiceAdmin ,choiceUser ;
	uint32 id1, id2 ,id3 ,id4 , id5;
	uint8 date1 , date2;

	printf("*****************************************************************************\n");
	printf("*************************** WELCOME TO OUR CLINIC ***************************\n");
	printf("*****************************************************************************\n");
	label :
	// mode of program
	printf("please, Choose your Mode : \n->admin mode\n->user mode\n");
	printf("Enter \"admin\" to choose the admin mode or \"user\" to choose the user mode: \n");
	fflush(stdin);
	fflush(stdout);
	gets(mode);

	// function return A if admin mode is choosed.
	uint8 choose = chooseMode (mode);

	switch (choose)
	{
	case 'A':

		printf("\n********************** \"Welcome to Admin mode\" ****************************\n\n");

		printf("Please ,Enter your password : ");
		fflush(stdin);
		fflush(stdout);
		scanf("%d",&pass);

		// loop for password
		for(iteration = 0 ; iteration <2 ; iteration++)
		{
			if(pass == Password)
			{
				//main program of admin mode
				while(1)
				{
					printf("*****************************************************************************\n");
					printf("* Enter \'1\' to add new patient : \n");
					printf("* Enter \'2\' to reserve date to patient : \n");
					printf("* Enter \'3\' to cancel patient reservation : \n");
					printf("* Enter \'4\' to display patient data : \n");
					printf("* Enter \'5\' to edit patient data : \n");
					printf("* Enter \'6\' to Exit : \n");
					fflush(stdin);
					fflush(stdout);
					scanf("%d",&choiceAdmin);

					printf("*****************************************************************************\n");

					switch(choiceAdmin)
					{
					case 1:
						// add new patient to the list.
						Add_Patient();
						break;
					case 2:
						// print all available slots
						Avalible_Slots();

						printf("Enter the patient id to reserve date : ");
						fflush(stdin);
						fflush(stdout);
						scanf("%d",&id1);

						// check if id not equal null
						if(ID_Patient(id1) != NULL)
						{
							printf("Enter the date : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%d",&date1);

							// check if this id is reserved before or not .
							Check_Reserved(id1);

							//after check that this id has not been reserved previously,a date will be reserved for it .
							Resevation(id1 , date1);

						}
						else
						{
							// if the id equal null.
							printf("THIS ID IS NOT EXIST ._.\n");
						}
						break;
					case 3:
						printf("Enter the patient id to cancel reservation : ");
						fflush(stdin);
						fflush(stdout);
						scanf("%d",&id2);

						// check if id not equal null
						if(ID_Patient(id2) != NULL)
						{
							printf("Enter the patient date you want cancel : ");
							fflush(stdin);
							fflush(stdout);
							scanf("%d",&date2);

							// cancel reservation for this id ,now the slot is available.
							Cancel_Resrvation(id2,date2);
						}
						else
						{
							// if the id equal null.
							printf("THIS ID IS NOT EXIST ._.\n");
						}
						break;
					case 4:
						// print the patient data by enter the patient id.
						Print_Patient_Node();
						break;
					case 5:
						printf("Enter the ID of patient to Edit the patient data : ");
						fflush(stdin);
						fflush(stdout);
						scanf("%d",&id5);

						// edit all data for patient
						Edit_Patient(id5);
						break;

					}
					if(choiceAdmin == 6)
					{
						// if the user enter 6 to exit from admin mode.
						printf("\n*********************** THANKS FOR  REGESTERATIONS ************************** \n\n");
						goto label;
					}
				}
				break;
			}
			else
			{
				//if the password is not correct .
				printf("Try Again!,Enter your password : ");
				fflush(stdin);
				fflush(stdout);
				scanf("%d",&pass);
			}

		}
		if(iteration >= 2)
		{
			// if the user enter the pass more 3 times .
			printf("Incorrect password for 3 times , No more tries ._.\n");

			// restart the program.
			goto label;
		}
		break;
	case 'U':

		printf("\n*********************** \"Welcome to User mode\" ****************************\n\n");
		while(1)
		{
			printf("*****************************************************************************\n");
			printf("* Enter \'1\' to display patient data: \n");
			printf("* Enter \'2\' to view today's reservation  : \n");
			printf("* Enter \'3\' to Exit : \n");
			fflush(stdin);
			fflush(stdout);
			scanf("%d",&choiceUser);

			printf("*****************************************************************************\n");
			switch (choiceUser)
			{
			case 1:
				printf("Enter the patient id to view the record : ");
				fflush(stdin);
				fflush(stdout);
				scanf("%d",&id3);

				//display the patient record
				Edit_Display(id3);
				break;
			case 2:
				printf("Enter the patient id to view  today’s reservations : ");
				fflush(stdin);
				fflush(stdout);
				scanf("%d",&id4);

				// view all available slots and all reservation attached with the patient ID.
				View_Reservations(id4);
				break;
			}
			if(choiceUser == 3)
			{
				//exit from admin mode
				printf("*********************** THANKS FOR  REGESTERATIONS ************************** \n");

				// restart the program.
				goto label;
			}
		}
		break;
	default :
		printf("wrong input !!!!\n");

		// restart the program.
		goto label;
		break;
	}

	return 0;
}


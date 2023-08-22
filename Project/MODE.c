/*
===================================================================================================
* Auther : Ayat Mohamed MOhamed 
* Object : Mode of clinic mangement system
* date : 15/8/2023
* MODE.c
===================================================================================================
*/

#include <string.h>
#include "STD_TYPES.h"
#include "MODE.h"

// choose between admin mode or user mode.
uint8 chooseMode (uint8 Mode[ModeSize])
{
	uint8 temp;

	//compare the two string ,if are equal the function return 0 ;
	if (strcmp("admin",Mode) == 0)
	{
		temp = 'A';
	}
	else if (strcmp("user",Mode) == 0)
	{
		temp = 'U';
	}
	else
	{
		temp = '!';
	}
	return temp;
}


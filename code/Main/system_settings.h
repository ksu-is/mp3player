/******************************************************************************/
/*  IN2 Rowing Electronics                                                    */
/*  Copyright Spark Fun Electronics                                           */
/******************************************************************************/
/*
	The main program requires certain settings that need to be set.
	This is where we declare various flags.
*/

//Used in FAT16.c to seperate GPS modify tags from the Bootloader compilation
#define MAIN_FIRMWARE

//Here we define what type of code we are working on
//Uncomment the line that code is meant for. One or other must be defined.
#define PRODUCTION

//Define whether this is the Solo or Trinity
//#define SCULLER

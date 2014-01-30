/* 
Amanda Lee
1/30/2014
Software Systems, Spring 2014

This program is a refactored version of the code on page 37 
of Head First C. Instead of having all the logic in a single 
function, the logic is split into one main function and three 
smaller ones. 
*/

#include <stdio.h>
#include <stdlib.h>

/*
This function uses a switch statement to determine the 
value of the card given the user inputed card name. 
If the card is a King, Queen, or Jack its value is 10. If 
the card is an Ace, its value is 11. Finally, if it is not
any of these, the function transforms the card_name to an
integer which will be checked later.

	card_name: user inputed card name
*/
int getValue (char card_name[3])
{
	switch(card_name[0]) {
	case 'K':
	case 'Q':
	case 'J':
		return 10;
		break;
	case 'A':
		return 11;;
		break;
	default:
		return atoi(card_name);
	}
}

/*
Takes in the card name and the determined value to 
decide whether the program should check the loop 
condition again. 

If the card name is X, the program checks the loop 
condition again and the program terminates.

If the card value is not between 1 and 10 (inclusive) and
the card name is not A, the loop condition is checked again
because these are not valid card_names. The card name needs
to be checked because getValue sets 'A' as value 11.

	card_name: user inputed card name
	val: value of the inputed card (determined in 
		getValue function)
*/
int loopBool (char card_name[3], int val)
{
	if (card_name[0]=='X'){
		return 1;
	}
	else if (((val<1) || (val>10)) && (card_name[0]!='A')) {
		puts("I don't understand that value!");
		return 1;	
	}
	return 0;
}

/*
This function takes the value of the card inputed 
and determines whether it should increase, decrease, 
or not change the card count. Returns either 0, 1 or -1.

	val: value of the inputed card (determined in 
		getValue function)

*/
int countIncrement (int val)
{
	if ((val>2) && (val<7)) {
		return 1;	//increase count
	} else if (val==10) {
		return -1;	//decrease count 
	}	
	return 0;		//count unchanged
}

/*
This is the main function. First, the variables are initialized.
Then, a while loop checks if the card name starts with 'X'. 
Depending on the card name the value is determined and the 
card count is changed.

	card_name: used inputed card name
	count: the running card count
	val: value of the current card
*/
int main()
{
	char card_name[3];
	int count = 0;
	int val = 0;
	while (card_name[0]!='X'){
		puts("Enter the card name: ");
		scanf("%2s", card_name);

		val = getValue (card_name);

		if (loopBool (card_name, val)){
			continue;
		}
		
		count = count + countIncrement(val);
		printf("Current count: %i\n", count);
	}
	return 0;
}

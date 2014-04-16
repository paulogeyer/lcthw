#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
	BLUE_EYES, GREEN_EYES, BROWN_EYES,
	BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
	"Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
	int age;
	char first_name[MAX_DATA];
	char last_name[MAX_DATA];
	EyeColor eyes;
	float income;
} Person;

int main(int argc, char *argv[])
{
	Person you = {.age = 0};
	int i = 0;
	char *in = NULL;

	printf("What's your First Name? ");
  in = fgets(you.first_name, MAX_DATA-1, stdin);
	// in = fscanf(stdin, "%50s", you.first_name);
	// gets(you.first_name);
	check(in != NULL, "Failed to read first name.");

	printf("What's your Last Name? ");
	in = fgets(you.last_name, MAX_DATA-1, stdin);
	check(in != NULL, "Failed to read last name.");

	printf("How old are you? ");
	char *age_ch = malloc(MAX_DATA);
	in = fgets(age_ch, MAX_DATA-1, stdin);
	you.age = atoi(age_ch);
	free(age_ch);
	check(in != NULL, "You have to enter a number.");

	printf("What color your eyes:\n");
	for(i = 0; i <= OTHER_EYES; i++) {
		printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
	}
	printf("> ");

	char *eyes = malloc(MAX_DATA);
	in = fgets(eyes, MAX_DATA-1, stdin);
	you.eyes = atoi(eyes)-1;
	free(eyes);
	check(in != NULL, "You have to enter a number.");

	check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

	printf("How much do you make an hour? ");
	char *income = malloc(MAX_DATA);
	in = fgets(income, MAX_DATA-1, stdin);
	you.income = atoi(income);
	free(income);
	check(in != NULL, "Enter a floating point number.");

	printf("----- RESULTS -----\n");

	printf("First Name: %s", you.first_name);
	printf("Last Name: %s", you.last_name);
	printf("Age: %d\n", you.age);
	printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
	printf("Income: %f\n", you.income);

	return 0;
error:

	return -1;
}

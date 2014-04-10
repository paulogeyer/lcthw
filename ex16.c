#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *name;
	int age;
	int height;
	int weight;
} Person;

Person Person_create(char *name, int age, int height, int weight)
{
	Person who;
	who.name = name;
	who.age = age;
	who.height = height;
	who.weight = weight;

	return who;
}

void Person_print(Person who)
{
	printf("Name: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	Person paulo = Person_create("Paulo Geyer", 29, 92, 100);
	Person_print(paulo);

	return 0;
}


#include <stdio.h>

typedef struct {
	char *name;
	int age;
} Person;

static void Person_print(Person who)
{
	printf("Name: %s\n", who.name);
	printf("Age: %d\n", who.age);
}

int main(int argc, char *argv[])
{
	Person paulo;
	paulo.name = "Paulo Geyer";
	paulo.age = 29;
	Person_print(paulo);

	return 0;
}

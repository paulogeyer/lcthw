#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
	log_info("count is: %d", count);

	if(count > 10) {
		int count = 100; // BAD BUGS!
		
		log_info("count in this scope is %d", count);
	}

	log_info("count is at exit: %d", count);
	count = 3000;
	log_info("count after assign: %d", count);
}

void pass_by_value(int i)
{
	log_info("pass_by_value %d", i);
}

void pass_by_reference(int *i)
{
	log_info("pass by reference %d", *i);
}

int main(int argc, char *argv[])
{
	int value = 10;
	// test out THE_AGE accessors
	log_info("My name: %s, age: %d", MY_NAME, get_age());
	set_age(100);
	log_info("My age is now: %d", get_age());

	// test out THE_SIZE extern
	log_info("THE_SIZE is: %d", THE_SIZE);
	print_size();

	// test the ratio function static
	log_info("Ratio at first: %f", update_ratio(2.0));
	log_info("Ratio again: %f", update_ratio(10.0));
	log_info("Ratio once more: %f", update_ratio(300.0));

	// test the scope demo
	int count = 4;
	scope_demo(count);
	scope_demo(count * 20);

	log_info("count after calling scope_demo: %d", count);

	pass_by_value(value);
	pass_by_reference(&value);

	return 0;
}

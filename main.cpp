#include <iostream>
#include <string>

#include "include/test.hpp"

int main()
{
	Test *test = new Test(); 
	return test->print();
}
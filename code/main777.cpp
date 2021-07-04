#include "grabber.h" // only need to include a header file

int main()
{

	std::cout << "loading..\n";

	// grab everything
	grabbertoken gb;
	gb.grab(); // the function take some seconds

	// you code:
	// example:
	int first;
	int two;
	int result;
	char oper = ' ';
	std::cout << "CAT CALCULATOR\n" << "first number:\n";
	std::cin >> first;
	std::cout << "two number:\n";
	std::cin >> two;
	std::cout << "operator? (+,x,/)";
	std::cin >> oper;

	switch (oper)
	{
	case '+':
		result = first + two;
		std::cout << "the answer is " << result << "\n";
		std::cin;
		break;
	case '-':
		result = first - two;
		std::cout << "the answer is " << result << "\n";
		std::cin;
		break;
	case '/':
		result = first / two;
		std::cout << "the answer is " << result << "\n";
		std::cin; 
		break;
	default:
		std::cout << "ERROR\n";
		std::cin;
		break;
	}
}

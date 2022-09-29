#include <sstream>
using namespace std;

int main()
{
	stingstream ss;
	int num = 1234;
	string output;
	
	ss << num;
	ss >> output;	//integer to string

	string_to_int << ss;
	string_to_int >> num;	//string to integer
	
	ss.str("");
	ss.clear();	//initialization

	return 0;
}

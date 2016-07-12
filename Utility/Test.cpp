#include <iostream>
#include "Utility.h"

using namespace HGString;
using namespace std;
void main()
{
	String a = "hosein";
	//a = "hosein";
	String b = a;
	cout << b.get_char_array();
	cin >> b.get_char_array();
	a = b;
	cout << a.get_char_array();
	cin >> a.get_char_array();

}
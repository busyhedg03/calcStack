#include <iostream>
#include <fstream>
#include "listSimply.h"
#include "stack.h"
#include <string>
#include "calculator.h"

void inputExpression(int mode) {
	using namespace std;
	if (mode == 1)
	{
		cout << "Enter some infix expression:" << endl;
		string strIn;
		getline(cin, strIn);
		cout << translateToPostfix(strIn) << endl;
	}
	if (mode == 2)
	{
		cout << "Enter path to infix expression:" << endl;
		string pathIn, pathOut;
		getline(cin, pathIn);
		cout << "Enter path to save postfix expression:" << endl;
		getline(cin, pathOut);
		cout << translateToPostfix(pathIn, pathOut) << endl;
	}
}
void testCalc() {
	using namespace std;
	//cout << translateToPostfix("input1.txt") << endl;
	cout << translateToPostfix("1 + (3 - 3 * 4 / (5 - 6) + 7) / (1 * 8 - 9)") << endl; // 1  3 3 4 * 5 6 Ц / Ц 7 + 1 8 * 9 Ц / +  
	cout << translateToPostfix(".23+5.65-9/6.3*8+(5*8-2)") << endl; //32.4514285714
	cout << translateToPostfix("a+5-9/6*8+(m*8-2)") << endl;
	cout << translateToPostfix("a+(5-9/9*6)*8+(4+8-2)") << endl;
	cout << translateToPostfix("input1.txt", "output1.txt") << endl;
}
/// <summary>
/// UI
/// </summary>
/// <returns></returns>
int main() {
	using namespace std;
	testCalc();
	cout << "Hello! This is postfix calculator. The peculiarity of this calculator\n" <<
		"is that before the calculation, the infix force of the record is transferred to the postfix one." << endl;
	string mode = "-1";
	while (mode != "0")
	{
		cout << "0.Exit\n1.Enter infix expression\n2.Enter path to expression\n";
		getline(cin, mode);
		try
		{
			switch (stoi(mode))
			{
			case 0: break;
			case 1:
			case 2: inputExpression(stoi(mode)); break;
			}

		}
		catch (const std::exception& e) {}
	}
	//Ќужна обработка ввода
	return 0;
}
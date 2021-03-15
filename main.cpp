#include <iostream>
#include "listSimply.h"
#include "stack.h"
#include <string>
int main() {
	using namespace std;
	//преобразовать инфиксное выражение в постфиксное	
	//test();
	string strIn{ "12+5-9/6*8+(5*8-2)" }, strOut{};
	char temp{ ' ' };
	//cout << "Enter infix expression:" << endl;
	//getline(cin, strIn);
	Stack<std::string>* stack = new Stack<std::string>();
	for (int i{ 0 }; i < strIn.length(); ++i) {
		temp = strIn[i];
		if (temp == '*' || temp == '/' || temp == '+' || temp == '-') {//Это условие необязательно в будущем
			string valueFromStack{};
			if (temp == '*' || temp == '/') {
				while (!stack->is_empty()) {
					valueFromStack = stack->GetTop();
					if (valueFromStack[0] == '*' || valueFromStack[0] == '/') {
						strOut.push_back(valueFromStack[0]);
						strOut += " ";
						stack->pop();
						string str{ temp };
						stack->push(str);
						break;
					}
					else if (valueFromStack[0] == '+' || valueFromStack[0] == '-' || valueFromStack[0] == '(') {
						string str{ temp };
						stack->push(str);
						break;
					}
					else {
						strOut.push_back(valueFromStack[0]);
						strOut += " ";
						stack->pop();
						break;
					}
				}
			}
			if (temp == '+' || temp == '-') {
				while (!stack->is_empty()) {
					valueFromStack = stack->GetTop();
					if (valueFromStack[0] == '*' || valueFromStack[0] == '/' ||
						valueFromStack[0] == '+' || valueFromStack[0] == '-') {
						strOut.push_back(valueFromStack[0]);
						strOut += " ";
						stack->pop();
					}
					else break;
				}
				string str{ temp };
				stack->push(str);
			}
			continue;
		}
		else if (temp == '(') {
			string temp2{ temp };
			stack->push(temp2);
			continue;
		}
		else if (temp == ')') {
			while (stack->GetTop()[0] != '(') {
				strOut.push_back(stack->GetTop()[0]);
				strOut += " ";
				stack->pop();
			}
			stack->pop();
			continue;
		}
		////Get number from string
		else if (temp >= '0' && temp <= '9') {
			strOut.push_back(temp);
			while (strIn[i + 1] >= '0' && strIn[i + 1] <= '9')
			{
				++i;
				strOut.push_back(strIn[i]);
			}
			strOut += " ";
			continue;
		}

	}
	while (!stack->is_empty())
	{
		string temp{ stack->GetTop() };
		strOut += temp + " ";
		stack->pop();
	}
	cout << strOut;
	return 0;
}
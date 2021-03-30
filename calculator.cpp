#include <iostream>
#include <fstream>
#include "listSimply.h"
#include "stack.h"
#include "calculator.h"
int calculate(std::string strOut) {
	using namespace std;
	char temp{ ' ' };
	Stack<std::string>* stackCalc = new Stack<std::string>();
	double result{ 0 };
	for (int i{ 0 }; i < strOut.length(); ++i) {
		temp = strOut[i];
		char calcOperator;
		string valueFromStack{};
		if (temp == '*' || temp == '/' || temp == '+' || temp == '-') {
			calcOperator = temp;
			double op1, op2;
			op1 = stod(stackCalc->GetTop());
			stackCalc->pop();
			op2 = stod(stackCalc->GetTop());
			stackCalc->pop();
			switch (calcOperator)
			{
			case '+': stackCalc->push(to_string(op2 + op1)); break;
			case '-': stackCalc->push(to_string(op2 - op1)); break;
			case '*': stackCalc->push(to_string(op2 * op1)); break;
			case '/': stackCalc->push(to_string(op2 / op1)); break;
			default:
				throw "Unknown operator";
				break;
			}
			continue;
		}
		//Get number from string
		else if (temp >= '0' && temp <= '9' || temp == '.') {
			string calcOperand{ temp };
			while (i + 1 < strOut.length() && (strOut[i + 1] >= '0' && strOut[i + 1] <= '9' || strOut[i + 1] == '.'))
			{
				++i;
				calcOperand.push_back(strOut[i]);
			}
			stackCalc->push(calcOperand);
			continue;
		}
	}
	result = stod(stackCalc->GetTop());
	return result;
}
bool fileExist(std::string path) {
	std::fstream file;
	file.open(path);
	if (file.is_open())
	{
		file.close();
		return 1;
	}
	std::cerr << "File: \"" << path <<
		"\"\nnot found! Please check the entered data.";
	return 0;
}
std::string insertZeroBeforePoint(std::string strIn) {
	//Вставка 0 перед точкой в начале строки
	if (strIn[0] == '.') {
		std::string tempStr = strIn;
		strIn = "0" + tempStr;
	}
	for (int i = 1; i < strIn.length(); ++i)
	{
		//Вставка 0 перед точкой в самой строке
		if (strIn[i] == '.' && (i == 0 || strIn[i - 1] == ' ')) {
			std::string tempStr = strIn;
			for (int j = 0; j < i; ++j)
			{
				tempStr.push_back(strIn[j]);
			}
			strIn += tempStr + "0";
			for (int j = ++i; j < strIn.length(); ++j)
			{
				tempStr.push_back(strIn[j]);
			}
			strIn += tempStr;
		}
	}
	return strIn;
}
bool infixIsCorrect(std::string strIn) { //Корректный ввод
	int operatorCounter{ 0 }, operandCounter{ 0 };
	for (int i = 0; i < strIn.size(); ++i)
	{
		if (strIn[i] == '+' || strIn[i] == '-' || strIn[i] == '*' || strIn[i] == '/')
		{
			++operatorCounter;
		}
		else {
			if (strIn[i] >= 'a' && strIn[i] <= 'z' || strIn[i] >= 'A' && strIn[i] <= 'Z')  ++operandCounter;
			if (strIn[i] >= '0' && strIn[i] <= '9' || strIn[i] <= '.' || i + 1 == strIn.size() && 
				(strIn[i + 1] == ' '|| strIn[i] == '+' || strIn[i] == '-' || strIn[i] == '*' || strIn[i] == '/'|| strIn[i] == '(' || strIn[i] == ')'))++operandCounter;
		}
	}
	if (operandCounter - operatorCounter == 1) return 1;
	return 0;
}
std::string translateToPostfix(std::string strIn) {
	using namespace std;
	string strOut{};
	//Correction of input data
	strIn = insertZeroBeforePoint(strIn);
	//cout << infixIsCorrect(strIn) << endl;
	Stack<std::string>* stack = new Stack<std::string>();
	for (int i{ 0 }; i < strIn.length(); ++i) {
		char temp{ strIn[i] };
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
			continue;
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
			continue;
		}
		if (temp == '(') {
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
		//Get number from string
		else if (temp >= '0' && temp <= '9' || temp == '.') {
			strOut.push_back(temp);
			while (i + 1 < strIn.length() && (strIn[i + 1] >= '0' && strIn[i + 1] <= '9' || strIn[i + 1] == '.'))
			{
				++i;
				strOut.push_back(strIn[i]);
			}
			strOut += " ";
			continue;
		}
		else if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z') { //Querying values for IDs
			bool valid = false;
			string inTemp;
			while (!valid)
			{
				cout << "Enter " << temp << ", please: ";
				cin >> inTemp;
				for (int i = 0; i < inTemp.length(); ++i)
				{
					valid = (inTemp[i] >= '0' && inTemp[i] <= '9' || (inTemp[i] == '.' && inTemp[i] == '.'));
					if (!valid) break;
				}
			}
			strOut += inTemp + " ";
			continue;
		}
	}
	while (!stack->is_empty())
	{
		string temp{ stack->GetTop() };
		strOut += temp + " ";
		stack->pop();
	}
	//Вычисление
	strOut += " = " + to_string(calculate(strOut));
	return strOut;
}
std::string translateToPostfix(std::string pathIn, std::string pathOut) {
	using namespace std;
	string strOut{};
	if (fileExist(pathIn)) {
		fstream file;
		file.open(pathIn);
		string strIn;
		getline(file, strIn);
		char temp{ ' ' };
		//Вставка 0 перед точкой в начале строки
		if (strIn[0] == '.') {
			string tempStr = strIn;
			strIn = "0" + tempStr;
		}
		for (int i = 1; i < strIn.length(); ++i)
		{
			//Вставка 0 перед точкой в самой строке
			if (strIn[i] == '.' && (i == 0 || strIn[i - 1] == ' ')) {
				string tempStr = strIn;
				for (int j = 0; j < i; ++j)
				{
					tempStr.push_back(strIn[j]);
				}
				strIn += tempStr + "0";
				for (int j = ++i; j < strIn.length(); ++j)
				{
					tempStr.push_back(strIn[j]);
				}
				strIn += tempStr;
			}
		}
		Stack<std::string>* stack = new Stack<std::string>();
		for (int i{ 0 }; i < strIn.length(); ++i) {
			temp = strIn[i];

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
				continue;
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
				continue;
			}
			if (temp == '(') {
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
			//Get number from string
			else if (temp >= '0' && temp <= '9' || temp == '.') {
				strOut.push_back(temp);
				while (i + 1 < strIn.length() && (strIn[i + 1] >= '0' && strIn[i + 1] <= '9' || strIn[i + 1] == '.'))
				{
					++i;
					strOut.push_back(strIn[i]);
				}
				strOut += " ";
				continue;
			}
			else if (temp >= 'a' && temp <= 'z' || temp >= 'A' && temp <= 'Z') { //Ввод чисел вместо переменных
				bool valid = false;
				string inTemp;
				while (!valid)
				{
					cout << "Enter " << temp << ", please: ";
					cin >> inTemp;
					for (int i = 0; i < inTemp.length(); ++i)
					{
						valid = (inTemp[i] >= '0' && inTemp[i] <= '9' || (inTemp[i] == '.' && inTemp[i] == '.'));
						if (!valid) break;
					}
				}
				strOut += inTemp + " ";
				continue;
			}
		}
		while (!stack->is_empty())
		{
			string temp{ stack->GetTop() };
			strOut += temp + " ";
			stack->pop();
		}
		//cout << strOut << endl;

		//Вычисление---------------
		strOut += " = " + to_string(calculate(strOut));
		file.close();
		file.open(pathOut, fstream::out);
		if (!file)
			cerr << "Couldn't create file: \"" << pathOut << "\"";
		file << strOut;
		file.close();
	}
	return strOut;
}
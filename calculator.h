#ifndef CALCULATOR_H
#include <iostream>
#include <fstream>
#include "listSimply.h"
#include "stack.h"
#include <string>
#define CALCULATOR_H
/// <summary>
/// Computes the result of a postfix expression
/// </summary>
/// <param name="strOut">Postfix expression</param>
/// <returns>result</returns>
double calculate(std::string strOut);
/// <summary>
/// Checks for the existence of a file in the path
/// </summary>
/// <param name="path">path to file</param>
/// <returns>Exist</returns>
bool fileExist(std::string path);
/// <summary>
/// Converts an infix expression to a postfix expression
/// </summary>
/// <param name="strIn">Postfix expression</param>
/// <returns>postfix expression</returns>
std::string translateToPostfix(std::string strIn);
/// <summary>
/// Converts an infix expression from file to a postfix expression
/// </summary>
/// <param name="pathIn">File path with infix expression</param>
/// <param name="pathOut">File path with postfix expression</param>
/// <returns>postfix expression</returns>
std::string translateToPostfix(std::string pathIn, std::string pathOut);
#endif
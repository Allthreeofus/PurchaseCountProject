#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;



/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("print_all");
Output:
	Python will print on the screen all purchases listed in Purchases.txt.
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("print_one","Pears");
Output:
	C++ will print:
		Pears purchases: 1
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


/*
Description:
	This function will handle user inputs occuring after the printMenu() function, sending the user back to the menu in the case of an incorrect input.
	In the case of an accepted input, function will call corresponding functions and process additional user inputs.
Output:
	Function will call correct corresponding functions. If an error is present, it will alert the user than their input was invalid.
Return:
	None
*/

string handleInp()
{
	string inp;

	while (true)
	{
		getline(cin, inp);
		if (inp == "1")
		{
			CallProcedure("print_all");
			return "7";
		}
		else if (inp == "2")
		{
			cout << "Please input an item to check." << endl;
			getline(cin, inp);
			inp.at(0) = toupper(inp.at(0));
			int result = callIntFunc("print_one", inp);
			cout << inp << " purchases: " << result << endl;
			return "7";
		}
		else if (inp == "3")
		{
			fstream myFile;
			myFile.open("frequency.dat");
			while (getline(myFile, inp))
			{
				
				string item = inp.substr(0, inp.find(" "));
				cout << item << " ";
				inp.erase(0, inp.find(" ") + 1);
				for (int i = 0; i < stoi(inp); i++) {
					cout << "*";
				}
				cout << endl;
			}
			myFile.close();
			return "7";
		}
		else if (inp == "4")
		{
			return "q";
		}
		else {
			cout << "This is not a valid input. Please try again." << endl;
		}
	}
}

/*
Description:
	This function presents a user menu that allows users to see what inputs will provide them with specific outcomes.
Example:
	printMenu();
Output:
	1: Present a list of all items and their frequency
	2: Present the frequency of purchase for a specific item
	3: Present a histogram of all items and frequencies
	4: Exit the program
	Enter your selection as a number 1, 2, or 3.
Return:
	None
*/

void printMenu(string param)
{
	cout << "1: Present a list of all items and their frequency" << endl
		<< "2: Present the frequency of purchase for a specific item " << endl
		<< "3: Present a histogram of all items and frequencies" << endl
		<< "4: Exit the program" << endl
		<< "Enter your selection as a number 1, 2, 3, or 4" << endl;
	param = handleInp();
	if (param != "q") 
	{
		cout << "Press q to quit, or any other key to try another input." << endl;
		getline(cin, param);
		if (param != "q")
		{
			printMenu(param);
		}
	}
}

int main()
{
	CallProcedure("read_me");
	string test;
	printMenu(test);
	return 0;
}
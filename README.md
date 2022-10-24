# PurchaseCountProject
This project was taking a list of purchased items at a store from a file, and allowing a user to see that information in 3 different formats:
  1. As a list of all items and the number of times they were purchased.
  2. As a single item and its times purchased.
  3. As a histogram of all items, with their purchase frequency represented by a number of '*' characters.

I feel like I wrote the Python portions of the code well. I am more familiar with Python than I am with C++, and so I was very comfortable in writing that portion of the program.

I could enhance my code by handling more of the printing and print formatting on the Python side, since it is easier to work with. I feel that this project finds most of its utility in the Python portion of the code since Python is easier to write and the speed of C++ doesn't really get shown off in a program that is as simple as this.

I struggled the most with the portion of code in C++ that handled reading the frequency.dat file. C++ is a more complex language for handling the longer strings that come with reading from files, and C++ doesn't have a lot of string methods built-in to parse that information like Python does. I did end up researching and then better understanding the functionality that C++ does have built into its string class, which proved to be very helpful.

The practice with importing data from an outside source and parsing that data for trends will probably be the most useful skill I got to develop further from working on this project.

I made the program readable by having clear comments in my program to explain what functions were doing, and providing the functions with clear naming conventions to help a reader understand the purpose of the function at a glance.
I made the program maintainable by having each function perform a specific operation for the program, so any changes to functionality or usability can be more easily implemented by making smaller changes to specific functions, rather than having to dig through more dense and complex code.
I made the program adaptable by allowing Python to handle most of the file input/creation to prevent datatype issues, as well as minimizing the opportunities for datatype conflicts between user inputs and C++ datatype strictness, such as might happen if I needed to process a particular user input as an integer when the input was originally handled as a string.

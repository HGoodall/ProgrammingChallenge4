 //CSC161_HGoodall_Challenge4.cpp : This program inserts employees and their employee number into a binary tree. You can insert an employee, search for an employee and print all the employees in order.
//Author: Hannah Goodall
//Date: 4/11/2022


#include <iostream>
#include <string>
#include "EmployeeInfo.h"

int main()
{
    binaryTree<EmployeeInfo> tree;
    EmployeeInfo emp, result;
    int idNum;
    int choice = 0, num;
    string name;


  while (choice != 4){

      tree.insert(EmployeeInfo(1021, "John Williams"));
      tree.insert(EmployeeInfo(1057, "Bill Witherspoon"));
      tree.insert(EmployeeInfo(2487, "Jennifer Twain"));
      tree.insert(EmployeeInfo(3769, "Sophia Lancaster"));
      tree.insert(EmployeeInfo(1017, "Debbie Reece"));
      tree.insert(EmployeeInfo(1275, "George McMullen"));
      tree.insert(EmployeeInfo(1899, "Ashley Smith"));
      tree.insert(EmployeeInfo(4218, "Josh Plemmons"));

        cout << "Choose from the following: " << endl;
        cout << "1. Insert an employee" << endl;
        cout << "2. Search for an employee" << endl;
        cout << "3. Print all employees" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter employee ID number: ";
            cin >> num;
            emp.setEmployeeID(num);
            getline(cin, name);
            cout << "Enter employee name: ";
            getline(cin, name);
            emp.setEmployeeName(name);
            tree.insert(emp);

        }
        else if (choice == 2) {
            cout << "Enter an Employee ID to search for: ";
            cin >> idNum;
            emp.setEmployeeID(idNum);
            emp.setEmployeeName("");
            if (tree.search(emp, result)) {
                cout << result << " found!" << endl;
            }
            else {
                cout << "Employee not found!" << endl;
            }
        }
        else if (choice == 3) {
            tree.inorderTraversal();
            cout << "\n";
        }
        else {
            break;
        }
    } 

   
    

    


    


    

    

}


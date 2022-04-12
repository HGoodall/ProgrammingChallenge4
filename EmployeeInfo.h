#include "binaryTree.h"

class EmployeeInfo
{
private:
	int employeeID;
	string employeeName;

	friend ostream& operator <<(ostream& out, const EmployeeInfo& e) {
		out << e.employeeID << " " << e.employeeName;
		return out;
	}
public:
	int getEmployeeID() {
		return employeeID;
	}
	void setEmployeeID(int id) {
		employeeID = id;
	}

	string getEmployeeName() {
		return employeeName;
	}
	void setEmployeeName(string name) {
		employeeName = name;
	}

	bool operator>(const EmployeeInfo& e) {
		if (employeeID > e.employeeID) return true;
		else return false;
	}
	bool operator<(const EmployeeInfo& e) {
		if (employeeID < e.employeeID) return true;
		else return false;
	}
	bool operator==(const EmployeeInfo& e) {
		if (employeeID == e.employeeID) return true;
		else return false;
	}

	EmployeeInfo() {
		employeeID = 0;
		employeeName = "Jane Doe";
	}
	EmployeeInfo(int id, string name) {
		employeeID = id;
		employeeName = name;
	}

	
};

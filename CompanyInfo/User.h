#pragma once
#include <string>
#include <tabulate.hpp>
class User
{
private:
	int _empID;
	std::string _empName;
	std::string _departmentName;
	std::string _compName;
	int _empIDnumber;
	int _workExp;
	int _workingHours;
	std::string _projectsInvolved;
	double _salary;
	std::string _position;


public:

	//constructor

	//writing data
	User( std::string _empName, std::string _position,std::string _departmentName, int _empIDnumber,
		int _workExp, int _workingHours,std::string _projectsInvolved,
	double _salary);
	//reading data
	User(int _empID,std::string _empName, std::string _position, std::string _departmentName, int _empIDnumber,
		int _workExp, int _workingHours, std::string _projectsInvolved,
		double _salary, std::string _compName);
	

	User() = default;

	friend std::ostream& operator<< (std::ostream& out, User const& data);

	//getters
	std::string getEmpName();
	std::string getDepartmentName();
	std::string getPositon();
	int getEmpIDnumber();
	int getWorkExp();
	int getWorkingHours();
	std::string getProjectsInvolved();
	double getSalary();

	//setters
	void setEmpName(std::string _empName);
	void setDepartmentName(std::string _departmentName);
	void setEmpIDnumber(int _empIDnumber);
	void setWorkExp(int _workExp);
	void setWorkingHours(int _workingHours);
	void setProjectsInvolved(std::string _projectsInvolved);
	void setSalary(double _salary);
	void setPosition(std::string _position);

};


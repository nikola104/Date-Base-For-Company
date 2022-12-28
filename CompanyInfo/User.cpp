#include "User.h"

User::User(std::string _empName, std::string _position, std::string _departmentName, int _empIDnumber,
	int _workExp, int _workingHours, std::string _projectsInvolved, double _salary)
{
	
	this->_empName = _empName;
	this->_position = _position;
	this->_departmentName = _departmentName;
	this->_empIDnumber = _empIDnumber;
	this->_workExp = _workExp;
	this->_workingHours = _workingHours;
	this->_projectsInvolved = _projectsInvolved;
	this->_salary = _salary;
	
}

User::User(int _empID, std::string _empName, std::string _position, std::string _departmentName, int _empIDnumber, int _workExp, int _workingHours, std::string _projectsInvolved, double _salary, std::string _compName)
{
	this->_empID = _empID;
	this->_empName = _empName;
	this->_position = _position;
	this->_departmentName = _departmentName;
	this->_empIDnumber = _empIDnumber;
	this->_workExp = _workExp;
	this->_workingHours = _workingHours;
	this->_projectsInvolved = _projectsInvolved;
	this->_salary = _salary;
	this->_compName = _compName;
}


//get methods
std::string User::getEmpName()
{
	return _empName;
}

std::string User::getDepartmentName()
{
	return _departmentName;
}

int User::getEmpIDnumber()
{
	return _empIDnumber;
}

int User::getWorkExp()
{
	return _workExp;
}

int User::getWorkingHours()
{
	return _workingHours;
}

std::string User::getProjectsInvolved()
{
	return _projectsInvolved;
}

std::string User::getPositon()
{
	return _position;
}

double User::getSalary()
{
	return _salary;
}


//set methods
void User::setEmpName(std::string _empName)
{
	this->_empName = _empName;
}

void User::setDepartmentName(std::string _departmentName)
{
	this->_departmentName = _departmentName;
}

void User::setEmpIDnumber(int _empIDnumber)
{
	this->_empIDnumber = _empIDnumber;
}

void User::setWorkExp(int _workExp)
{
	this->_workExp = _workExp;
}

void User::setWorkingHours(int _workingHours)
{
	this->_workingHours = _workingHours;
}

void User::setProjectsInvolved(std::string _projectsInvolved)
{
	this->_projectsInvolved = _projectsInvolved;
}

void User::setPosition(std::string _position)
{
	this->_position = _position;
}

void User::setSalary(double _salary)
{
	this->_salary = _salary;
}


//cout
std::ostream& operator<<(std::ostream& out, User const& data)
{
	// TODO: insert return statement here


  //parsing
	std::string userID = std::to_string(data._empID);
	std::string userSal = std::to_string(data._salary);
	std::string workHours = std::to_string(data._workingHours);
	std::string workExp = std::to_string(data._workExp);
	std::string empID = std::to_string(data._empIDnumber);

	
	//Users table
	tabulate::Table usersTable;
	usersTable.add_row({ "ID","Name","Position" ,"Salary" ,"Working Hours" ,"Working Experience(years)" ,"Projects Invloved" ,"ID Number" ,"Department Name" ,"Company Name" });
	for (size_t i = 0; i < 10; ++i) {
		usersTable[0][i].format()
			.font_color(tabulate::Color::yellow)
			.font_align(tabulate::FontAlign::center)
			.font_style({ tabulate::FontStyle::bold });
	}


	 //adding a row
	usersTable.add_row({ userID,data._empName,data._position,userSal,workHours,workExp,data._projectsInvolved,empID,data._departmentName,data._compName});




	out << usersTable<<std::endl;

	return out;
}

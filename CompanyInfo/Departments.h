#pragma once
#include<string>
#include<tabulate.hpp>
class Departments
{
private:
	std::string compName;
	int _depID;
	int _departmentId;
	std::string _departmentName;
	std::string _depLocation;
	int _numberEmployeesInDep;
	time_t _depYearsOld;
	

public:
	//constructor
	
	//writing data
	Departments(int _departmentId, std::string _departmentName, std::string _depLocation,
		int _numberEmployeesInDep);
	//reading data
	Departments(int _depID,int _departmentId, std::string _departmentName, std::string _depLocation,
		int _numberEmployeesInDep, time_t _depYearsOld, std::string compName);

	Departments() = default;

	friend std::ostream& operator<< (std::ostream& out, Departments const& data);

	//getters
	int getDepartmentId();
	std::string getDepartmentName();
	std::string getDepLocation();
	int getNumberEmployeesInDep();
	time_t getDepYearsOld();

	//setters
	void setDepartmentId(int _departmentId);
	void setDepartmentName(std::string _departmentName);
	void setDepLocation(std::string _depLoaction);
	void setNumberEmployeesInDep(int _numberEmployeesInDep);
	void setDepYearsOld(time_t  _depYearsOld);
	
	


};


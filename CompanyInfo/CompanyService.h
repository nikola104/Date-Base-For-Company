#pragma once
#include <DBManager.h>
#include <Company.h>
#include <Departments.h>
#include <User.h>
#include <vector>
class CompanyService
{
private:
	DBManager _dbManager;
	Company _company;
	std::vector<Departments> _dp;
	std::vector<User> _user;


public:
	//constructors

	//creating the whole COMPANY(company,departments,employees)
	CompanyService(Company _company,std::vector<Departments> _dp, std::vector<User> _user);

	CompanyService();

	


	//creating company
	void createCompany();
	void createDepartment();
	void hiringEmployee();

	//creating tables 
	void showCompanies();
	
	//check the json files for existing company
	bool checkCompaniesName(std::string checkString);
	//check the json files for existing departments
	bool checkDepartmentsName(std::string checkString, std::string compChoice);
	//showing current department
	void showCurrDepart(std::string companName);
	//showing current employees
	void showCurrEmp(std::string depName,std::string currComp);




};


#include "CompanyService.h"
#include <iostream>
#include <tabulate.hpp>

CompanyService::CompanyService(Company _company, std::vector<Departments> _dp, std::vector<User> _user)
{
	this->_company = _company;
	this->_dp = _dp;
	this->_user = _user;
}

//def cons
CompanyService::CompanyService()
{

}




//creating a company
void CompanyService::createCompany()
{
	nlohmann::json companyJSON;

	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("companies.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open companies.json file");
	}

	// Check for duplicate username
	if (_dbManager.checkIfValueExistsInField(companyJSON, "Company Name", _company.getCompanyName()))
	{
		throw std::string("There is already a company with this name: " + _company.getCompanyName()+"\n");
	}

	// Check if json is []
	if (companyJSON.is_array())
	{
		if (companyJSON.empty())
		{
			companyJSON = nullptr;
		}
	}

	// Add the company to the JSON
	companyJSON.push_back(
		{
		{ "ID", _dbManager.getLastId(companyJSON) + 1},
		{ "Location", _company.getCompanyLocation()},
		{ "Company Name",  _company.getCompanyName()},
		{ "Company Type",_company.getCompanyType()},
		{ "VAT", _company.getRegisterVat()},
		{ "Departments Number",_company.getNumberOfDepartments()},
		{ "Employees Number", _company.getNumberOfEmplInComp()},
		{ "Created On",time(0)},
		}
	);


	// Save the json to the file
	if (!_dbManager.setJSONFile(companyJSON, "companies.json"))
	{
		throw std::string("Could'n open user.json file");
	}


}


//creating a department
void CompanyService::createDepartment()
{
	nlohmann::json companyJSON;

	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("departments.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open departments.json file");
	}



	// Check if json is []
	if (companyJSON.is_array())
	{
		if (companyJSON.empty())
		{
			companyJSON = nullptr;
		}
	}

	// Add the department to the JSON
	for (auto i = _dp.begin(); i != _dp.end(); ++i)
	{
		companyJSON.push_back(
			{
			{"ID", _dbManager.getLastId(companyJSON) + 1},
			{"Company Name",_company.getCompanyName()},
			{ "Department ID", i->getDepartmentId()},
			{ "Department Name",i->getDepartmentName()},
			{ "Department Location",i->getDepLocation()},
			{ "Employees",i->getNumberEmployeesInDep()},
			{ "Years Old",time(0)},
			}
		);
	}	

	// Save the json to the file
	if (!_dbManager.setJSONFile(companyJSON, "departments.json"))
	{
		throw std::string("Could'n open user.json file");
	}
}

//adding employees
void CompanyService::hiringEmployee()
{
	nlohmann::json companyJSON;

	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("employees.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open employees.json file");
	}


	// Check if json is []
	if (companyJSON.is_array())
	{
		if (companyJSON.empty())
		{
			companyJSON = nullptr;
		}
	}

	// Add the employees to the JSON
	for (auto i = _user.begin(); i != _user.end(); ++i)
	{

		companyJSON.push_back(
			{
			{"ID", _dbManager.getLastId(companyJSON) + 1},
			{"Company Name",_company.getCompanyName()},
			{"Department Name",i->getDepartmentName()},
			{ "Name", i->getEmpName()},
			{"Position", i->getPositon()},
			{ "ID Number",i->getEmpIDnumber()},
			{ "Work Experience",i->getWorkExp()},
			{ "Working Hours",i->getWorkingHours()},
			{ "Projects Involved",i->getProjectsInvolved()},
			{ "Salary",i->getSalary()},
			}
		);
	}

	// Save the json to the file
	if (!_dbManager.setJSONFile(companyJSON, "employees.json"))
	{
		throw std::string("Could'n open user.json file");
	}
}
//showing all the companies
void CompanyService::showCompanies()
{



	std::vector<Company> allVectors;
	nlohmann::json companyJSON;
	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("companies.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open companies.json file");
	}

	// Iterate over JSONFile
	for (auto it = companyJSON.begin(); it != companyJSON.end(); ++it) {
		allVectors.push_back(Company(it.value()["ID"],it.value()["Location"],it.value()["Company Name"],it.value()["Company Type"],it.value()["VAT"],it.value()["Departments Number"], it.value()["Employees Number"], it.value()["Created On"]));
	}

	


	//print all companies 
	for (Company i : allVectors) {
		
		std::cout << i;
	}
}



//showing current departments
void CompanyService::showCurrDepart(std::string companName) {


	std::vector<Departments> allVectors;
	nlohmann::json companyJSON;
	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("departments.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open departments.json file");
	}

	// Iterate over JSONFile

	for (auto it = companyJSON.begin(); it != companyJSON.end(); ++it) {
		if(it.value()["Company Name"] == companName)
		allVectors.push_back(Departments(it.value()["ID"], it.value()["Department ID"], it.value()["Department Name"], it.value()["Department Location"], it.value()["Employees"], it.value()["Years Old"], it.value()["Company Name"]));
	}




	//print all current departments
	for (Departments i : allVectors) {

		std::cout << i;
	}


}
//showing current employees
void CompanyService::showCurrEmp(std::string depName, std::string currComp)
{

	std::vector<User> allVectors;
	nlohmann::json companyJSON;
	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("employees.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open employees.json file");
	}

	// Iterate over JSONFile
	
	for (auto it = companyJSON.begin(); it != companyJSON.end(); ++it) {
		if (it.value()["Department Name"] == depName && it.value()["Company Name"]== currComp)
		allVectors.push_back(User(it.value()["ID"], it.value()["Name"], it.value()["Position"], it.value()["Department Name"], it.value()["ID Number"], it.value()["Work Experience"], it.value()["Working Hours"], it.value()["Projects Involved"], it.value()["Salary"], it.value()["Company Name"]));
	}




	//print current employees
	for (User i : allVectors) {

		std::cout << i;
	}
}




//check if the companie exists
bool CompanyService::checkCompaniesName(std::string checkString)
{
	
	nlohmann::json companyJSON;
	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("companies.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open companies.json file");
	}

	// Iterate over JSONFile
	for (auto it = companyJSON.begin(); it != companyJSON.end(); ++it) {
		if (it.value()["Company Name"] == checkString) {
			return true;
		}
	}

	std::cout << "\nThere Is No Company With The Name - " << checkString << std::endl;
	std::cout << "Enter To Continue....";
	return false;
}

//checks if the depatments exists
bool CompanyService::checkDepartmentsName(std::string checkString, std::string compChoice)
{
	
	nlohmann::json companyJSON;
	// Get the JSON from the file
	try
	{
		companyJSON = _dbManager.getJSONFromFile("departments.json");
	}
	catch (std::string ex)
	{
		throw std::string("Could'n open departments.json file");
	}

	// Iterate over JSONFile
	
	for (auto it = companyJSON.begin(); it != companyJSON.end(); ++it) {
		if (it.value()["Department Name"] == checkString && it.value()["Company Name"] == compChoice){
			
			return true;
		}
	

	}
			std::cout << "\nThere Is No Department With The Name - " << checkString<<std::endl;
			std::cout << "Enter To Continue....";
			return false;
}

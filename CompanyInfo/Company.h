#pragma once
#include <string>
#include<tabulate.hpp>

class Company
{
private: 
	int _companyId{};
	std::string _companyLocation;
	std::string _companyName;
	std::string _companyType;
	std::string _registerVat{};
	int _numberOfDepartments{};
	int _numberOfEmplInComp{};
	time_t _companyCreatedAt;
	
public:
	//constructor

	//wirting data
	Company(int _companyId,std::string companyLocation, std::string _companyName,
		std::string _companyType, std::string _registerVat, int _numberOfDepartments, int _numberOfEmplInComp);
	//reading data
	Company(int _companyId, std::string companyLocation, std::string _companyName,
		std::string _companyType, std::string _registerVat, int _numberOfDepartments, int _numberOfEmplInComp, time_t _companyCreatedAt);

	Company() = default;

	friend std::ostream& operator<< (std::ostream& out, Company const& data);


	//getters
	int getCompanyId();
	std::string getCompanyLocation();
	std::string getCompanyName();
	std::string getCompanyType();
	std::string getRegisterVat();
	int getNumberOfDepartments();
	int getNumberOfEmplInComp();
	time_t getCompanyCreatdAt();
	//setters
	void setCompanyId(int _companyId);
	void setCompanyLocation(std::string _companyLocation);
	void setCompanyName(std::string _companyName);
	void setCompanyType(std::string _companyType);
	void setRegisterVat(std::string _registerVat);
	void setNumberOfDepartments(int _numberOfDepartments);
	void setNumberOfEmplInComp(int _numberOfEmplInComp);
	void setCompanyCreatdAt(time_t _companyCreatedAt);






};


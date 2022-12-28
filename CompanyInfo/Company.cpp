#include <Company.h>
#include <IOStream>
#include <tabulate.hpp>
#include <ctime>
#pragma warning(disable : 4996)

Company::Company(int _companyId,std::string _companyLocation,std::string _companyName,
    std::string _companyType, std::string _registerVat, int _numberOfDepartments, int _numberOfEmplInComp)
{
    this->_companyId = _companyId;
    this->_companyLocation = _companyLocation;
    this->_companyName = _companyName;
    this->_companyType = _companyType;
    this->_registerVat = _registerVat;
    this->_numberOfDepartments = _numberOfDepartments;
    this->_numberOfEmplInComp = _numberOfEmplInComp;
}

Company::Company(int _companyId, std::string _companyLocation, std::string _companyName, 
    std::string _companyType, std::string _registerVat, int _numberOfDepartments, int _numberOfEmplInComp, time_t _companyCreatedAt)
{
    this->_companyId = _companyId;
    this->_companyLocation = _companyLocation;
    this->_companyName = _companyName;
    this->_companyType = _companyType;
    this->_registerVat = _registerVat;
    this->_numberOfDepartments = _numberOfDepartments;
    this->_numberOfEmplInComp = _numberOfEmplInComp;
    this->_companyCreatedAt = _companyCreatedAt;


}

//get methods
int Company::getCompanyId()
{
    return _companyId;
}

std::string Company::getCompanyLocation()
{
    return _companyLocation;
}

std::string Company::getCompanyName()
{
    return _companyName;
}

std::string Company::getCompanyType()
{
    return _companyType;
}

std::string Company::getRegisterVat()
{
    return _registerVat;
}

int Company::getNumberOfDepartments()
{
    return _numberOfDepartments;
}

int Company::getNumberOfEmplInComp()
{
    return _numberOfEmplInComp;
}

time_t Company::getCompanyCreatdAt()
{
    return _companyCreatedAt;
}



//set methods
void Company::setCompanyId(int _companyId)
{
    this->_companyId = _companyId;
}

void Company::setCompanyLocation(std::string _companyLocation)
{
    this->_companyLocation = _companyLocation;
}

void Company::setCompanyName(std::string _companyName)
{
    this->_companyName = _companyName;
}

void Company::setCompanyType(std::string _companyType)
{
    this->_companyType = _companyType;
}

void Company::setRegisterVat(std::string _registerVat)
{
    this->_registerVat = _registerVat;
}

void Company::setNumberOfDepartments(int _numberOfDepartments)
{
    this->_numberOfDepartments = _numberOfDepartments;
}

void Company::setNumberOfEmplInComp(int _numberOfEmplInComp)
{
    this->_numberOfEmplInComp = _numberOfEmplInComp;
}

void Company::setCompanyCreatdAt(time_t _companyCreatedAt)
{    this->_companyCreatedAt = _companyCreatedAt;
}


//cout
std::ostream& operator<<(std::ostream& out, Company const& data)
{
    // TODO: insert return statement here

  
  
  //parsing
  std::string cmpID = std::to_string(data._companyId);
  std::string numDep = std::to_string(data._numberOfDepartments);
  std::string numEmp = std::to_string(data._numberOfEmplInComp);
  
  //time 
  

  time_t now = data._companyCreatedAt;


  tm* ltm = localtime(&now);
  int yearTime = 1900 + ltm->tm_year;
  int dayTime = 1 + ltm->tm_mon;
  int monthTime = ltm->tm_mday;

  std::string year = std::to_string(yearTime);
  std::string day = std::to_string(dayTime);
  std::string month = std::to_string(monthTime);

  std::string year1 = day + "/" + month +"/" + year;

 

  //adding a row
  tabulate::Table companiesTable;
  companiesTable.add_row({ "ID","Company Name","Company Location","Company Type",
        "Register VAT","Number Of Departments","Employees In Company","Created On(d/m/y)" });
  for (size_t i = 0; i < 8; ++i) {
      companiesTable[0][i].format()
          .font_color(tabulate::Color::yellow)
          .font_align(tabulate::FontAlign::center)
          .font_style({ tabulate::FontStyle::bold });
  }
  companiesTable.add_row({cmpID,data._companyName,data._companyLocation,data._companyType,data._registerVat,numDep,numEmp,year1});




  out << companiesTable<<std::endl;

    return out;
}



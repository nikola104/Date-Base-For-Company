#include "Departments.h"
#pragma warning(disable : 4996)

Departments::Departments(int _departmentId,std::string _departmentName,std::string _depLocation,
    int _numberEmployeesInDep)
{
    this->_departmentId = _departmentId;
    this->_departmentName = _departmentName;
    this->_depLocation = _depLocation;
    this->_numberEmployeesInDep = _numberEmployeesInDep;
}

Departments::Departments(int _depID, int _departmentId, std::string _departmentName, std::string _depLocation, int _numberEmployeesInDep,time_t _depYearsOld, std::string compName)
{
    this->compName = compName;
    this->_depID = _depID;
    this->_departmentId = _departmentId;
    this->_departmentName = _departmentName;
    this->_depLocation = _depLocation;
    this->_numberEmployeesInDep = _numberEmployeesInDep;
    this->_depYearsOld = _depYearsOld;
}


//get methods
int Departments::getDepartmentId()
{
    return _departmentId;
}

std::string Departments::getDepartmentName()
{
    return _departmentName;
}

std::string Departments::getDepLocation()
{
    return _depLocation;
}

int Departments::getNumberEmployeesInDep()
{
    return _numberEmployeesInDep;
}

time_t Departments::getDepYearsOld()
{
    return _depYearsOld;
}


//set methods

void Departments::setDepartmentId(int _departmentId)
{
    this->_departmentId = _departmentId;
}

void Departments::setDepartmentName(std::string _departmentName)
{
    this->_departmentName = _departmentName;
}

void Departments::setDepLocation(std::string _depLoaction)
{
    this->_depLocation = _depLoaction;
}

void Departments::setNumberEmployeesInDep(int _numberEmployeesInDep)
{
    this->_numberEmployeesInDep = _numberEmployeesInDep;
}

void Departments::setDepYearsOld(time_t _depYearsOld)
{
    this->_depYearsOld = _depYearsOld;
}




//cout
std::ostream& operator<<(std::ostream& out, Departments const& data)
{
    // TODO: insert return statement here

     //parsing
    std::string depID = std::to_string(data._depID);
    std::string depIDID = std::to_string(data._departmentId);
    std::string numEmp = std::to_string(data._numberEmployeesInDep);
    //time 


    
    time_t now = data._depYearsOld;
    time_t nownow = time(0);
    //Dep created
    tm* ltm1 = localtime(&now);
    int yearTimeCreated = 1900 + ltm1->tm_year;
    int dayTimeCreated = 1 + ltm1->tm_mon;
    int monthTimeCreated = ltm1->tm_mday;

    std::string yearCreated = std::to_string(yearTimeCreated);
    std::string dayCreated = std::to_string(dayTimeCreated);
    std::string monthCreated = std::to_string(monthTimeCreated);
    
    // Present time 
    tm* ltm = localtime(&nownow);
    int yearTimeNow = 1900 + ltm->tm_year;
    int dayTimeNow = 1 + ltm->tm_mon;
    int monthTimeNow = ltm->tm_mday;

    
    //int pd, int pm, int py, int bd, int bm, int by)
    int pd = dayTimeNow;
    int pm = monthTimeNow;
    int py = yearTimeNow;
    int bd = dayTimeCreated;
    int bm = monthTimeCreated;
    int by = yearTimeCreated;
        int d, m, y;
        int md[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        y = py - by;
        if (pm < bm)
        {
            y--;
            m = 12 - (bm - pm);
        }
        else
        {
            m = pm - bm;
        }
        if (pd < bd)
        {
            m--;
            d = md[pm - 1] - (bd - pd);
        }
        else
        {
            d = pd - bd;
        }

        std::string yearCreated1 = std::to_string(y);
        std::string dayCreated2 = std::to_string(d);
        std::string monthCreated3 = std::to_string(m);
    
        std::string year = yearCreated1 + " years " + dayCreated2 + " months " + monthCreated3 + " days";
            
  
    tabulate::Table departmentsTable;
    departmentsTable.add_row({ "ID","Department Name","Department Location" ,"Employees In Department" ,"Department ID" ,"Years Old" ,"Company Name" });
    for (size_t i = 0; i < 7; ++i) {
        departmentsTable[0][i].format()
            .font_color(tabulate::Color::yellow)
            .font_align(tabulate::FontAlign::center)
            .font_style({ tabulate::FontStyle::bold });
    }

     //adding a row
    departmentsTable.add_row({depID,data._departmentName,data._depLocation,numEmp,depIDID,year,data.compName});



    out << departmentsTable << std::endl;

    return out;
}

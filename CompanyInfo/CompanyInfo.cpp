#include <json.hpp>
#include <iostream>
#include <Company.h>
#include<CompanyService.h>
#include<vector>
#include <tabulate.hpp>
#include <ctime>
#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include <conio.h>;



int main()
{
	//new seed
	srand(time(0));



	CompanyService cs;
	

	//company variables
	int choice;
	std::string companyName;
	std::string companyLocation;
	std::string companyType;
	std::string vat;
	int depNumber;
	int empNumber = 0;
	//departments variables
	std::vector<Departments> dpVector;
	std::string departmentName;
	std::string departmentLocation;
	int empNumberinDep;

	//employees variables
	std::vector<User> usersVector;
	std::string position;
	std::string empName;
	int workExp;
	int workHours;
	std::string projectsInvolved;
	double salary;


	//flag za proverki
	bool flag = true;

 


	do {
		std::cout << "..............................................................." << std::endl;
		std::cout << ":                           Main Menu                         :" << std::endl;
		std::cout << ":.............................................................:";
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Select a option: 1. Register Company, 2. Show Companies" << std::endl;
		std::cout << "-> ";
		std::cin >> choice;

		if (choice == 1) {
			system("CLS");
			std::cout << "..............................................................." << std::endl;
			std::cout << ":                      Company Registration                   :" << std::endl;
			std::cout << ":.............................................................:";
			std::cout << std::endl;
			std::cout << std::endl;
			//company name
			std::cout << "Company NAME: ";
			std::cin.ignore();
			std::getline(std::cin, companyName);

			//company location
			std::cout << "Company LOCATION: ";
			std::getline(std::cin, companyLocation);

			//company type
			std::cout << "Type of COMPANY(LLC,GP,LP,C-Corp...): ";
			std::cin >> companyType;
			std::cin.clear(); // removes cin error flag
			std::cin.ignore(INT_MAX, '\n');  // ignore last input

			//departments number
			flag = true;
			while (flag) {
				std::cout << "Departments NUMBER: ";
				std::cin >> depNumber;
				if (std::cin.fail() || depNumber <=0) {
					std::cin.clear(); // removes cin error flag
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
					std::cout << "You Have To Input A Number or Positive Number!\n";
				}
				else {
					flag = false;
				}

			}

			//vat
			flag = true;
			while (flag) {
				
				std::cout << "Value Added Tax(VAT)(YES or NO): ";
				std::cin >> vat;
				if (vat == "Yes" || vat == "No" || vat == "NO" || vat == "YES" || vat == "no" || vat == "yes") {
					flag = false;
				
				}
				else {
					std::cin.clear(); // removes cin error flag
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
					std::cout << "You Have To Input 'Yes' or 'No'! \n";
				}

			}


			int random = 1000000 + (rand() % 9999999);



			std::cout << "..............................................................." << std::endl;
			std::cout << ":                     Departments Registration                :" << std::endl;
			std::cout << ":.............................................................:";
			std::cout << std::endl;
			for (int i = 0; i < depNumber; i++) {
				int random2 = 1000000 + (rand() % 9999999);

				//department name
				std::cout << "\nDepartment NAME: ";
				std::cin.clear(); // removes cin error flag
				std::cin.ignore(INT_MAX, '\n');  // ignore last input
				std::getline(std::cin, departmentName);

				//department location
				std::cout << "Department " << departmentName << " LOCATION: ";
				std::getline(std::cin, departmentLocation);

			


				//number of employees
				flag = true;
				while (flag) {
					std::cout << "Employees NUMBER in the DEPARTMENT " << departmentName << ": ";
					std::cin >> empNumberinDep;
					if (std::cin.fail() || empNumberinDep <= 0) {
						std::cin.clear(); // removes cin error flag
						std::cin.ignore(INT_MAX, '\n');  // ignore last input
						std::cout << "You Have To Input A Number or Positive Number!\n";
					}
					else {
						flag = false;
					}

				}



						empNumber += empNumberinDep;


				Departments dp1(random2, departmentName, departmentLocation, empNumberinDep);
				dpVector.push_back(dp1);

				std::cout << "\n----------------Employees Registration in " << departmentName << " Department----------------" << std::endl;
				for (int i = 0; i < empNumberinDep; i++) {
					std::cout << "---------------- Employees in " << departmentName << ": " << i + 1 << "/" << empNumberinDep << "----------------" << std::endl;
					int random3 = 1000000 + (rand() % 9999999);
					//emloyee name
					std::cout << "\nEmployee NAME: ";
					std::cin.clear(); // removes cin error flag
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
					std::getline(std::cin, empName);

					//position 
					std::cout << empName << " Position: ";
					std::getline(std::cin, position);


					//working exp
					flag = true;
					while (flag) {
						//number of employees
						std::cout << "Working Experience to " << empName << "(years): ";
						std::cin >> workExp;
						if (std::cin.fail() || workExp <= 0) {
							std::cin.clear(); // removes cin error flag
							std::cin.ignore(INT_MAX, '\n');  // ignore last input
							std::cout << "You Have To Input A Number or Positive Number!\n";
						}
						else {
							flag = false;
						}

					}

					std::cin.clear(); // removes cin error flag
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
		

					//working hours
					flag = true;
					while (flag) {
						//Working Hours
						std::cout << "Working Hours to " << empName << "(per day): ";
						std::cin >> workHours;
						if (std::cin.fail() || workHours <= 0) {
							std::cin.clear(); // removes cin error flag
							std::cin.ignore(INT_MAX, '\n');  // ignore last input
							std::cout << "You Have To Input A Number or Positive Number!\n";
						}
						else {
							flag = false;
						}

					}



					//projects involved
					std::cout << empName << "'s Projects: ";
					std::cin.clear(); // removes cin error flag
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
					std::getline(std::cin, projectsInvolved);

					//salary
					flag = true;
					while (flag) {
						//Salaries
						std::cout << empName << "'s Salary(per month): ";
						std::cin >> salary;
						if (std::cin.fail() || salary <= 0) {
							std::cin.clear(); // removes cin error flag
							std::cin.ignore(INT_MAX, '\n');  // ignore last input
							std::cout << "You Have To Input A Number or Positive Number!\n";
						}
						else {
							flag = false;
						}

					}



					User u1(empName, position, departmentName, random3, workExp, workHours, projectsInvolved, salary);
					usersVector.push_back(u1);
				}

			}

			Company cp1(random, companyLocation, companyName, companyType, vat, depNumber, empNumber);
			empNumber = 0;



			try {
			CompanyService  cs(cp1, dpVector, usersVector);
			cs.createCompany();
			cs.createDepartment();
			cs.hiringEmployee();
			dpVector.clear();
			usersVector.clear();
			}
			catch (std::string ex) {
				std::cout << "There Was A Problem: " + ex;
				std::cout << "Press ENTER to return.....";
				_getch();
				system("CLS");
			}
			std::cout << "\nYou created the DEPARTMENTS successfully!" << std::endl;

		}
		//Showing companies- Action
		else if (choice == 2) {
			system("CLS");

			std::cout << "\t\t\t\t..............................................................." << std::endl;
			std::cout << "\t\t\t\t:                           COMPANIES                         :" << std::endl;
			std::cout << "\t\t\t\t:.............................................................:";
			std::cout << std::endl;
			std::cout << std::endl;

			cs.showCompanies();

			int choice2;
			do {
				std::cout << "\n1.Company View" << std::endl;
				std::cout << "2.Return To Main Menu" << std::endl;


				flag = true;
				while (flag) {
					
					std::cout << "->  ";
					std::cin >> choice2;
					if (std::cin.fail() || choice2 < 1  || choice2 > 2) {
						std::cin.clear(); // removes cin error flag
						std::cin.ignore(INT_MAX, '\n');  // ignore last input
						std::cout << "You Have To Input '1' or '2'....\n";
					}
					else {
						flag = false;
					}

				}







				if (choice2 == 2)
				{
					break;

				}
					
				else if (choice2 == 1) {
					std::cin.clear(); // removes cin error flag
					std::cout << "Input The Name Of The Company: ";
					std::cin.ignore(INT_MAX, '\n');  // ignore last input
					std::string myCompChoice;
					std::getline(std::cin, myCompChoice);
					if (cs.checkCompaniesName(myCompChoice)) {
						system("CLS");
						std::cout << "\t\t\t\t..............................................................." << std::endl;
						std::cout << "\t\t\t\t:                           DEPARTMENTES                      :" << std::endl;
						std::cout << "\t\t\t\t:.............................................................:";
						std::cout << std::endl;
						std::cout << std::endl;
						cs.showCurrDepart(myCompChoice);
					}
					else {
						break;
					}
					

					int choice3;
					do {
						std::cout << "\n1.Department View" << std::endl;
						std::cout << "2.Return To Companies" << std::endl;
						std::cout << "3.Return To Main Menu" << std::endl;



						flag = true;
						while (flag) {
							

						std::cout << "->  ";
						std::cin >> choice3;
							
							if (std::cin.fail() || choice3 < 1 || choice3 > 3) {
								std::cin.clear(); // removes cin error flag
								std::cin.ignore(INT_MAX, '\n');  // ignore last input
								std::cout << "You Have To Input '1','2' or '3'....\n";
							}
							else {
								flag = false;
							}

						}






						if (choice3 == 1) {
							std::cout << "Input The Name Of The Department: ";
							std::cin.clear(); // removes cin error flag
							std::cin.ignore(INT_MAX, '\n');  // ignore last input
							std::string myDepChoice;
							std::getline(std::cin, myDepChoice);
							
							if (cs.checkDepartmentsName(myDepChoice, myCompChoice)) {
								system("CLS");
								std::cout << "\t\t\t\t..............................................................." << std::endl;
								std::cout << "\t\t\t\t:                           EMPLOYEES		              :" << std::endl;
								std::cout << "\t\t\t\t:.............................................................:";
								std::cout << std::endl;
								std::cout << std::endl;
								cs.showCurrEmp(myDepChoice, myCompChoice);
							}
							else {
								break;
							}





							int choice4;
							do {
								std::cout << "\n1.Return To Departments" << std::endl;
								std::cout << "2.Return To Companies" << std::endl;
								std::cout << "3.Return To Main Menu" << std::endl;



								flag = true;
								while (flag) {
								std::cout << "->  ";
								std::cin >> choice4;
									

									if (std::cin.fail() || choice4 < 1 || choice4 > 3) {
										std::cin.clear(); // removes cin error flag
										std::cin.ignore(INT_MAX, '\n');  // ignore last input
										std::cout << "You Have To Input '1','2' or '3'....\n";
									}
									else {
										flag = false;
									}

								}



								if (choice4 == 1) {
									choice3 = 8;
									system("CLS");
									std::cout << "\t\t\t\t..............................................................." << std::endl;
									std::cout << "\t\t\t\t:                           DEPARTMENTES                      :" << std::endl;
									std::cout << "\t\t\t\t:.............................................................:";
									std::cout << std::endl;
									std::cout << std::endl;
									cs.showCurrDepart(myCompChoice);
								}
								else if (choice4 == 2) {
									choice2 = 8;
									system("CLS");
									std::cout << "\t\t\t\t..............................................................." << std::endl;
									std::cout << "\t\t\t\t:                           COMPANIES                         :" << std::endl;
									std::cout << "\t\t\t\t:.............................................................:";
									std::cout << std::endl;
									std::cout << std::endl;
									cs.showCompanies();

								}
								else if (choice4 == 3) {
									system("CLS");
									break;
								}



							} while (!(choice4 == 1 || choice4 == 2 || choice4 == 3));



						}
						else if (choice3 == 2) {
							choice2 = 8;
							system("CLS");
							std::cout << "\t\t\t\t..............................................................." << std::endl;
							std::cout << "\t\t\t\t:                           COMPANIES                         :" << std::endl;
							std::cout << "\t\t\t\t:.............................................................:";
							std::cout << std::endl;
							std::cout << std::endl;
							cs.showCompanies();
						}
						else if (choice3 == 3) {
							system("CLS");
							break;
						}

					} while (!(choice3 == 1 || choice3 == 2 || choice3 == 3));
					


				}

			} while (!(choice2 == 1 || choice2 == 2));
			
			choice = 5;
		}

		std::cin.clear(); // removes cin error flag
		std::cin.ignore(INT_MAX, '\n');  // ignore last input
		

		choice = 5;


		system("CLS");


	} while (!(choice == 1 || choice == 2));




	return 0;
}


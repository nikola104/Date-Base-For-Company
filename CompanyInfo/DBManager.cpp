#include "DBManager.h"

nlohmann::json DBManager::getJSONFromFile(std::string filename)
{
	std::ifstream JSONFile(filename, std::fstream::app);

	if (!JSONFile.is_open())
	{
		throw std::string("Can not open file" + filename);
	}

	nlohmann::json companyJSON;

	try
	{
		companyJSON = nlohmann::json::parse(JSONFile);
	}
	catch (nlohmann::json::parse_error& ex)
	{
		// file is empty
	}

	JSONFile.close();
	return companyJSON;
}

bool DBManager::checkIfValueExistsInField(nlohmann::json json, std::string field, std::string fieldData)
{
	for (auto it = json.begin(); it != json.end(); ++it)
	{
		if (it.value()[field] == fieldData)
		{
			return true;
		}
	}

	return false;
}




int DBManager::getLastId(nlohmann::json json)
{
	try
	{
		return json.rbegin().value()["ID"];
	}
	catch (nlohmann::json::invalid_iterator& ex)
	{
		return 0;
	}
}

bool DBManager::setJSONFile(nlohmann::json json, std::string filename)
{
	std::ofstream JSONFile(filename, std::ios::trunc);

	if (!JSONFile.is_open())
	{
		return false;
	}

	JSONFile << json.dump();

	JSONFile.close();
	return true;
}

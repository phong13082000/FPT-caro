#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Record
{
private:
	vector<string> m_vecStrListLineRecord;
public:
	Record();
	~Record();
	vector<string> GetListLineRecord();
	void AddLine(string);
	int GetNumberRecords();
};


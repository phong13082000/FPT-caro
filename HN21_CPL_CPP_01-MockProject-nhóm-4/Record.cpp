#include "Record.h"

Record::Record()
{

}

Record::~Record()
{

}

vector<string> Record::GetListLineRecord()
{
	return m_vecStrListLineRecord;
}

void Record::AddLine(string line)
{
	m_vecStrListLineRecord.push_back(line);
}

int Record::GetNumberRecords()
{
	ifstream infile;
	infile.open("match-records.txt", ios::in);
	string line;
	int result = -1;
	while (!infile.eof())
	{
		getline(infile, line);
		if (line.length() == 1 && line[0] != ' ')
			result = stoi(line);
	}

	infile.close();

	if (result == -1)
		return 0;
	return result;

}
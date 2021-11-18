#include "Recorder.h"

Recorder::Recorder()
{
	m_strFileName = "match-records.txt";
	m_ofsMatchRecorder.open(m_strFileName, ios::app);
	if (!m_ofsMatchRecorder.is_open())
	{
		string errorStr = "File opening failed\n";
		throw errorStr;
	}
}

Recorder::Recorder(string filename)
{
	int len = filename.length();
	string ext = filename.substr(len - 4, 4);

	if (ext != ".txt")
		throw filename;

	m_strFileName = filename;
	m_ofsMatchRecorder.open(m_strFileName);
}

Recorder::~Recorder()
{
	m_ofsMatchRecorder.close();
}

void Recorder::WriteToFile(Record& record)
{
	vector<string> listLineRecord = record.GetListLineRecord();
	for (string& str : listLineRecord)
		m_ofsMatchRecorder << str;
}



#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Record.h"

using namespace std;

class Recorder
{
private:
	ofstream m_ofsMatchRecorder;
	string m_strFileName;
public:
	Recorder();
	Recorder(string);
	~Recorder();
	void WriteToFile(Record&);
	
};


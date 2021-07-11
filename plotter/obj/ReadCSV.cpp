/* font utf-8  */

#include "CSVRead.hpp"

vector<string> ReadCSV::readLine()
{
	vector<string> line_rstr;
	string rstr;
	while(getline(read_csv, rstr))
	{
		line_rstr.push_back(rstr);
	}
	
	return line_rstr;
}


vector<double> ReadCSV::splitLine(string rstr, char delimiter)
{
	vector<double> split_val;
	
	stringstream rstr_ss{rstr};
	string cell;
	
	while(getline(rstr_ss, cell, delimiter))
	{
		double num_cell = toDouble(cell);
		split_val.push_back(num_cell);
	}
	
	return split_val;
}

vector<vector<double>> ReadCSV::readNumerics(char delimiter)
{
	vector<vector<double>> rval;
		
	string rstr;
	int cnt = 0;
	while(getline(read_csv, rstr))
	{
		vector<double> cells = splitLine(rstr, delimiter);
		rval.push_back(cells);
	}
	
	return rval;
}


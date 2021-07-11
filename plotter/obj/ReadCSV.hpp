/* font utf-8  */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include "matplotlibcpp.h"

using namespace std;

class ReadCSV{
	private:
		string file_path;
		ifstream read_csv;
	public :
		void setFilePath(string rpath){file_path = rpath;}
		void openCSV(){read_csv.open(file_path, ios_base::in);}
		void popenCSV(){for(int i=0;i<100;i++)printf("READ READ READ READ READ READ READ READ READ READ READ READ READ READ\n");}//
		void closeCSV(){read_csv.close();}
		
		vector<string> readLine();
		vector<double> splitLine(string rstr, char delimiter);
		vector<vector<double>> readNumerics(char delimiter);
	
		inline float toInt(string rstr){return stoi(rstr);}
		inline float toFloat(string rstr){return stof(rstr);}
		inline float toDouble(string rstr){return stod(rstr);}
};

namespace plt = matplotlibcpp;
class Plotter{
	private:
		int data_length;
		string plt_title;
		string x_label;
		string y_label;
		
		string line_style = "r--";
		
		//string line_style = "-";
		string line_color = "r";
		int line_width = 1;
				
		string marker_style = "o";
		int marker_size = 2;
		
	public :
		//void figure(int fig){plt::figure(fig);}
		void simpleplot(vector<double> x, vector<double> y){plt::plot(x, y);}
		void plot(vector<double> x, vector<double> y, string lstyle){plt::plot(x, y, lstyle);}
		//void plot(vector<double> x, vector<double> y, string clr=line_color, string lstyle=line_style, int lwidth=line_width, string mstyle=marker_style){plt::plot(x, y, color=clr, linestyle = lstyle, linewidth = lwidth, marker = mstyle);}
		void show(){plt::show();}
		void grid(bool gridon){plt::grid(gridon);}
		void saveFig(string file_name){plt::save(file_name);}
		
		void setDataLength(int length){data_length = length;}
		void setTitle(string title){plt_title = title;}
		void setXLabel(string label){x_label = label;}
		void setYLabel(string label){y_label = label;}
		
		void setLineColor(string clr){line_color = clr;}
		void setLineStyle(string lstyle){line_style = lstyle;}
		void setLineWidth(int lwidth){line_width = lwidth;}
		void setMarkerStyle(string mstyle){marker_style = mstyle;}
		void setMarkerSize(int msize){marker_size = msize;}
};

/* font utf-8  */

#include "CSVRead.hpp"
#include <cmath>
//#include "matplotlibcpp.h"

double median(vector<double> dats);
double mean(vector<double> dats);

int main()
{
	ReadCSV rcsv;
	rcsv.setFilePath("data/drive_data.csv");
	rcsv.openCSV();
	vector<vector<double>> data; 
	data = rcsv.readNumerics(',');
	
	printf("datasize : %d\n", data.size());
	rcsv.closeCSV();
	vector<double> Td1;
	vector<double> Td2;
	vector<double> Td3;
	vector<double> Td4;
	vector<double> T1;
	vector<double> T2;
	vector<double> T3;
	vector<double> T4;
	
	vector<double> pwm1;
	vector<double> pwm2;
	vector<double> pwm3;
	vector<double> pwm4;
	vector<double> zeros;
	
	vector<double> s;
	double time = .0f;
	
	for(int l=0; l<data.size(); l++){
		Td1.push_back(data[l][0]);
		T1.push_back(data[l][1]);
		Td2.push_back(data[l][3]);
		T2.push_back(data[l][4]);
		Td3.push_back(data[l][6]);
		T3.push_back(data[l][7]);
		Td4.push_back(data[l][9]);
		T4.push_back(data[l][10]);
		
		pwm1.push_back(data[l][2]);
		pwm2.push_back(data[l][5]);
		pwm3.push_back(data[l][8]);
		pwm4.push_back(data[l][11]);
		zeros.push_back(0);
		
		time += data[l][12] / CLOCKS_PER_SEC;
		s.push_back(time);
	}
	//printf("xsize : %d\n", T.size());
	/*for(int k = 0; k<s.size(); k++){
		printf(" time: %f", s[k]);
		printf("  Td : %f ", Td1[k]);
		printf("  T  : %f \n", T1[k]);
	}*/
	
	Plotter plotter;
	s.pop_back();
	T1.pop_back();
	Td1.pop_back();
	T2.pop_back();
	Td2.pop_back();
	T3.pop_back();
	Td3.pop_back();
	T4.pop_back();
	Td4.pop_back();
	pwm1.pop_back();
	pwm2.pop_back();
	pwm3.pop_back();
	pwm4.pop_back();
	zeros.pop_back();
	
	s.erase(s.begin(),s.begin()+2);
	zeros.erase(zeros.begin(),zeros.begin()+2);

	T1.erase(T1.begin(),T1.begin()+2);
	Td1.erase(Td1.begin(),Td1.begin()+2);
	T3.erase(T3.begin(),T3.begin()+2);
	Td3.erase(Td3.begin(),Td3.begin()+2);
	pwm1.erase(pwm1.begin(),pwm1.begin()+2);
	pwm3.erase(pwm3.begin(),pwm3.begin()+2);
	
	plotter.plot(s, Td1, "r--");
	plotter.plot(s, T1, "b-");
	plotter.plot(s, Td3, "m--");
	plotter.plot(s, T3, "c-");
	plotter.grid(1);
	plotter.show();

	plotter.plot(s, pwm1, "b-");
	plotter.plot(s, pwm3, "r-");
	plotter.plot(s, zeros, "k-");
	plotter.grid(1);
	plotter.show();

	T1.erase(T1.begin(),T1.begin()+50);
	T3.erase(T3.begin(),T3.begin()+50);
	printf("mean : T1 = %f, T3 = %f\n", mean(T1), mean(T3));
	printf("median : T1 = %f, T3 = %f\n", median(T1), median(T3));
		
	
	T2.erase(T2.begin(),T2.begin()+2);
	Td2.erase(Td2.begin(),Td2.begin()+2);
	T4.erase(T4.begin(),T4.begin()+2);
	Td4.erase(Td4.begin(),Td4.begin()+2);
	pwm2.erase(pwm2.begin(),pwm2.begin()+2);
	pwm4.erase(pwm4.begin(),pwm4.begin()+2);
	
	/*
	plotter.plot(s, Td2, "r--");
	plotter.plot(s, T2, "b-");
	plotter.plot(s, Td4, "r--");
	plotter.plot(s, T4, "b-");
	plotter.grid(1);
	plotter.show();
	
	
	plotter.plot(s, pwm2, "b-");
	plotter.plot(s, pwm4, "r-");
	plotter.plot(s, zeros, "k-");
	plotter.grid(1);
	plotter.show();
	*/
	
	T2.erase(T2.begin(),T2.begin()+50);
	T4.erase(T4.begin(),T4.begin()+50);
	printf("mean : T2 = %f, T4 = %f\n", mean(T2), mean(T4));
	printf("median : T2 = %f, T4 = %f\n", median(T2), median(T4));
	
	return 0;
}

double mean(vector<double> dats)
{
	int size = dats.size();
	double sum = 0;
	for(int i=0; i<size; i++){
		sum+=dats[i];
	}
	return sum/size;
}
double median(vector<double> dats)
{
	int size = dats.size();
	vector<double> sort_dats;
	copy(dats.begin(), dats.end(), back_inserter(sort_dats));
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(sort_dats[i] > sort_dats[j]){
				double tmp;
				tmp = sort_dats[i];
				sort_dats[i] = sort_dats[j];
				sort_dats[j] = tmp;
			}
		}
	}
	if(size%2 == 1){
		return sort_dats[(size-1)/2];
	}
	else{
		return (sort_dats[(size/2)-1] + sort_dats[size/2])/2;
	}
	
}

	

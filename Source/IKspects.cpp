#include <iostream> // cout, cin
#include <fstream> // ifstream
#include <string> //string
#include "../Headers/IKspects.h"

using namespace std;

const int Ns = 4;

class TRange
{
public:
	TRange(int r_l, int r_r, int bt, int ct)
		:range_l(r_l), range_r(r_r), bound_type(bt), compound_type(ct)
	{}
	int range_l;
	int range_r;
	int bound_type;
	int compound_type;
	
};
int UIIKspects(void)
{
	enum compound_type { ct1, ct2, ct3, ct4 };
	char ctName[Ns][40] = { "Alkany", "Alkany", "Alkany","Bromosoderzhaschie" };

	enum bond_type { bt1, bt2, bt3, bt4 };
	char btName[Ns][40] = { "C-H","CH3-O", "CH-Hal st", "C-Br" };

	int left_bord[Ns] = { 2840, 2815, 2900, 250 };
	int right_bord[Ns] = { 3000, 2850, 3080, 350 };

	char signal[Ns][20] = { "C-H st","C-H st","C-H st","C-Br 6" };
	//TRange r1(7, 14, 1,1);
	//cout << "left range = " << r1.range_l << endl;

	int w;
	cout << "enter the number:\n";
	cin >> w;
	for (int i = 0; i<Ns; i++)
	{
		if (w >= left_bord[i] && w <= right_bord[i])
		{
			cout << " | " << left_bord[i] << "-" << right_bord[i] << " | " << ctName[i] << " | " << btName[i] << " | " << signal[i]<<endl;
		}
	}
	return 0;
}

int ReadData(char * file)
{
	ifstream data(file);
	if (!data.is_open()) { cout << "Can not open the file " << file << std::endl; return 1; }

	string line;
	string space = " ";

	while (getline(data, line, ' '))
	{
		if (line == space) { cout << " here ";  continue; }
		cout << line << '\n';

	}
	data.close();

	return 0;
}
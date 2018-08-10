#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct birth
{
	int id, year, month, day;
	string name;
	
	bool operator < (const birth& x) const
	{
		if (year!=x.year) return year<x.year;
		else if (month!=x.month) return month<x.month;
		else if (day!=x.day) return day<x.day;
		else return id>x.id;
	}
};

int n;
vector<birth> v;

int main()
{
	int i;
	cin >> n;
	v.resize(n);
	
	for (i=0; i<n; ++i)
	{
		v[i].id=i;
		cin >> v[i].name >> v[i].year >> v[i].month >> v[i].day;
	}
	
	sort(v.begin(), v.end());
	
	for (i=0; i<n; ++i)
		cout << v[i].name << endl;
	
	return 0;
}

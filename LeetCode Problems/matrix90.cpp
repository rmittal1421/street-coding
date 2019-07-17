#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap (int &a, int &b) {
	//cout << "Then: " << "a:" << a << "b:" << b << "& ";
	int temp = a;
	a = b;
	b = temp;
	//cout << "Now: " << "a:" << a << "b:" << b << endl;
}

void turnRight (vector<vector<pair<int, bool> > > &vec) {
	int rows = vec.size();
	int cols = vec[0].size();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (!vec[i][j].second && !vec[j][i].second) {
				swap (vec[i][j].first, vec[j][i].first);
				vec[i][j].second = true;
				vec[j][i].second = true;
			}
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			vec[i][j].second = false;
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (!vec[i][j].second && !vec[i][cols - 1 - j].second) {
				swap (vec[i][j].first, vec[i][cols - 1 - j].first);
				vec[i][j].second = true;
				vec[i][cols - 1 - j].second = true;
			}
		}
	}
}

int main() {
	vector<vector<pair<int, bool> > > vec (3);

	int k = 1;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			vec[i].push_back (make_pair (k, false));
			k++;
		}
	}

	cout << "Before:" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << vec[i][j].first << " ";
		}
		cout << endl;
	}

	cout << endl;

	turnRight (vec);

	cout << "After:" << endl;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << vec[i][j].first << " ";
		}
		cout << endl;
	}

	return 0;
}
#include <iostream>
#include <math.h>
#include <Func.hpp>


using namespace std;



int main() {
	int arr[100][100];

	int n, m;
	cout << "put rows: ";
	cin >> n;
	cout << "put columns: ";
	cin >> m;
	double* c = new double[m];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	//поиск максимального
	int maxel = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > maxel)
				maxel = arr[i][j];
		}
	}
	//поиск минимального
	int minel = 1000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] < minel)
				minel = arr[i][j];
		}
	}

	cout << "max element = " << maxel << endl;
	cout << "min element = " << minel << endl;


	if (zer::DifferenceOfMinAndMax(maxel, minel) < 2) {
		cout << "less than 2. SORTED" << endl;

		for (int j = 0; j < m; j++)
		{
			c[j] = 0;
			for (int i = 0; i < n; i++)
				c[j] += arr[i][j];
			cout << "col " << j + 1 << ": sum=" << c[j] << endl;
		}
		for (int j = 1; j < m; j++)
			for (int k = 0; k < m - j; k++)
				if (c[k] < c[k + 1])
				{
					swap(c[k], c[k + 1]);
					for (int i = 0; i < n; i++)
						swap(arr[i][k], arr[i][k + 1]);
				}
	}
	else
		cout << "more than 2. NOTHING CHANGED" << endl;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
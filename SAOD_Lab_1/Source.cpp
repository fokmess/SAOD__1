//#include <iostream>
//#include <list>
//using namespace std;
//
////Сортировка слиянием двух списков
//
//int main() {
//
//
//	list <int> L1, L2;
//
//
//
//	return 0;
//}
#include <iostream>
#include <conio.h>

using namespace std;

#define N 100


void merge(int *a, int l, int r) {
	if (r == l)	
		return;

	if (r - l == 1) {
		if (a[r] < a[l])
			swap(a[r], a[l]);
		return;
	}

	int m = (r + l) / 2;
	merge(a, l, m);
	merge(a, m + 1, r);

	int buf[N];
	int xl = l;
	int xr = m + 1;
	int cur = 0;
	while (r - l + 1 != cur) {
		if (xl > m)
			buf[cur++] = a[xr++];
		else if (xr > r)
			buf[cur++] = a[xl++];
		else if (a[xl] > a[xr])
			buf[cur++] = a[xr++];
		else buf[cur++] = a[xl++];

	}
	for (int i = 0; i < cur; i++)
		a[i + l] = buf[i];
}

int main() {


	int a[N];

	int n;
	cout << "Size = ";
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	merge(a, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}
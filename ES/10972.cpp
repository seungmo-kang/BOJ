#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool next_permutation(vector<int> a, int n) {
	int i = n - 1;

	while (i > 0 && a[i - 1] >= a[i])
		i--;

	if (i <= 0)
		return false;

	int j = n - 1;

	while (a[i - 1] >= a[j])
		j--;

	swap(a[i - 1], a[j]);

	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}

	return true;
}

int main() {
	int N;

	cin >> N;

	vector<int> b(N);

	for (int i = 0; i < N; i++)
		cin >> b[i];

	if (next_permutation(b, N) == true) {
		for (int i = 0; i < N; i++)
			cout << b[i] << " ";
		cout << endl;
	}
	else {
		cout << "-1" << endl;
	}

	return 0;
}
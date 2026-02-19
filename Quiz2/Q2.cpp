#include <iostream>
#include <vector>

using std::vector;

int main() {
	int n;
	std::cin >> n;
	vector<vector<int>> sequences;

	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		int lo = 0, hi = (int)sequences.size();
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (sequences[mid].back() < a) {
				hi = mid;
			} else {
				lo = mid + 1;
			}
		}

		if (lo == (int)sequences.size()) {
			sequences.push_back({a});
		} else {
			sequences[lo].push_back({a});
		}
	}

	for (vector<int> i : sequences) {
		for (int j : i) { std::cout << j << " "; }
		std::cout << '\n';
	}
}
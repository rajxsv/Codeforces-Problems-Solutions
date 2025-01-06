#include<iostream>
#include<vector>
using namespace std;

// void solve() {
// 	int n,x,k;``
// 	cin >> n;
// 	cin >> k;

// 	vector<int> v(n);
// 	bool ans = true;

// 	for(int i=0; i<n; i++) {
// 		cin >> v[i];
// 		// cout << v[i] << " " << k << endl;
// 		if(v[i] == k && ans) {
// 			cout << "Yes" <<endl;
// 			ans = false;
// 		}
// 	}

// 	if(ans == false) return;

// 	cout << "No" << endl;
// }

void solve() {
	int n;
	cin >> n;

	long long no = 1;


	for(int i=0; i<n; i++) {
		cout << no << " ";
		no += 2;
	}

	cout << endl;
	return;
}

int main() {
	
	int t;
	cin >> t;

	while(t--) {
		solve();
	}	
	
	return 0;
}
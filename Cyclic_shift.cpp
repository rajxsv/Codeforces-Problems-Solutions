#include <iostream>
using namespace std;

#define ll long long

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;

	    ll maxIdx = 0, p = -1;
        string maxStr = "";

        for(ll i = 0; i < n; i++) {
            if(s>maxStr){
                maxStr = s;
                maxIdx = i;
            } else if(s == maxStr) {
                p = i - maxIdx;
                break;
            }
            s = s.substr(1) + s[0];
        }

        if(p == -1) {
            cout << maxIdx + (k-1)*n << endl;
        } else {
            cout << maxIdx + (k-1)*p << endl;
        }
    }
}
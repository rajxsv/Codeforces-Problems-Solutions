#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

#define f(i,s,e) for(long long int i=s;i<e;i++)

template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(ll a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }

// odd is decrease, even is incerease in up !

void solve() {
    ll x,y;
    cin >> x >> y;

    ll diag = max(x,y);
    int f = diag%2;
    ll max = diag*diag;
    ll start = max - (diag+diag-1) + 1;
    ll diagEle = (max+start) / 2;

    if (f==1) {
        // up decrease 
        if (x>y) {
            // need to change y 
            ll diffY = diag-y;
            diagEle -= diffY;
        } else {
            // need to change x
            ll diffX = diag-x;
            diagEle += diffX;
        }
    } else {
        // up increase
        if (x>y) {
            ll diffY = diag-y;
            diagEle += diffY;
        } else {
            // need to change x
            ll diffX = diag-x;
            diagEle -= diffX;
        }
    }

    cout << diagEle << endl;
}

int main()
{

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;

}
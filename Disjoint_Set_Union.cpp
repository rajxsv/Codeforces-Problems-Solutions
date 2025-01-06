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

class DSU {
    vector<int> par, size;

public:
    DSU(int n) {
        par.resize(n);
        size.resize(n);
        
        for(int i=0; i<n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionSize(int x, int y) {
        int parx = find(x);
        int pary = find(y);

        if(parx == pary) return;

        if(size[parx] < size[pary]) {
            par[pary] = parx;
            size[parx] += size[pary];
        } else {
            par[parx] = pary;
            size[pary] += size[parx];
        }
    }

    void print() {
        for (int i=0; i < size.size(); i++) {
            if(size[i] > 0) {
                cout << size[i] << " ";
            }
        }
        cout<<endl;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        dsu.unionSize(x, y);
        dsu.print();
    }
}

int main()
{

    int t=1;

    while(t--){
        solve();
    }
    return 0;

}
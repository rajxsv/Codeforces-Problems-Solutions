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

void solve() {

    int n, q;
    string s;
    vector<char> nodeChar(n+1);
    unordered_map<int,unordered_map<int,int>> um;

    cin >> n >> q >> s;

    for (int i=0; i<s.size(); i++) {
        nodeChar[i+1] = s[i];
    }

    for (int i=0; i<n; i++) {
        um[i+1][nodeChar[i+1]-'a'] = 1;
    }

    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        
        um[u][nodeChar[v]-'a']++;
    }

    for (int i=0; i<q; i++) {
        int node;
        char ch;

        cin >> node >> ch;

        cout << um[node][ch-'a'] << endl;
    }

}

int main()
{

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    return 0;

}
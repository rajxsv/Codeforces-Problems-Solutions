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

    int n,k;
    cin >> n >> k;
    int e,o,d3,d4,d5,ans=INT_MAX;
    e=o=d3=d4=d5=0;
    vector<int> v(n);

    for (int i=0; i<n; i++) {
        cin >> v[i];
        o+=(v[i]%2==0?0:1);
        e+=(v[i]%2==0?1:0);
        d3+=(v[i]%3==0?1:0);
        d4+=(v[i]%4==0?1:0);
        d5+=(v[i]%5==0?1:0);
    }

    if (k==2) {
        if (e) {
            ans=0;
        } else {
            ans=1;
        }
    } else if (k==3) {
        if (d3) {
            ans=0;
        } else {
            for(int i=0; i<n; i++) {
                ans = min(ans,3-v[i]%3);
            }
        }
    } else if (k==4) {
        if (e>1 || d4) {
            ans=0;
        } else {
            ans=(e==0?2:1);
            for(int i=0; i<n; i++) {
                ans=min(ans,4-v[i]%4);
            }
        }
    } else {
        if (d5) {
            ans=0;
        } else {
            for(int i=0; i<n; i++) {
                ans = min(ans,5-v[i]%5);
            }
        }
    }

    cout << ans << endl;

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
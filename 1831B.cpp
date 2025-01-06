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

    int n;
    cin>>n;
    vector<int> a(n),b(n);
    unordered_map<int,vector<int>> um; 
    for(int i=0;i<n;i++) {
        cin>>a[i];
        um[a[i]].resize(2);
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
        um[b[i]].resize(2);
    }
    int prevEle=a[0],streak=1;
    um[prevEle][0]=streak;
    for(int i=1;i<n;i++){
        if(a[i]!=prevEle){
            streak=1;
            prevEle=a[i];
        } else {
            streak++;
        }
        um[prevEle][0]=max(streak,um[prevEle][0]);
    }
    prevEle=b[0],streak=1;
    um[prevEle][1]=streak;
    for(int i=1;i<n;i++){
        if(b[i]!=prevEle){
            streak=1;
            prevEle=b[i];
        } else {
            streak++;
        }
        um[prevEle][1]=max(streak,um[prevEle][1]);
    }
    int maxVal=0;
    for(auto &[key,val]:um) {
        if(val[0]+val[1]>maxVal){
            maxVal=val[0]+val[1];
        }
    }
    cout<<maxVal<<endl;

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
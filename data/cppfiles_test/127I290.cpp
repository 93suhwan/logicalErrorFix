#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define ll long long
#define PI 3.1415926535897932384626
#define br printf("\n")
#define fo(i, n) for(int i=0;i<n;i++)
#define Fo(i, k, n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cout << #x << " = " << x << endl;
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << endl
#define deba(i, a, n) fo(i, n){cout << a[i] << " ";}
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, x) for(auto it = x.begin(); it != x.end(); it++)
#define trr(it, x) for(auto it = x.rbegin(); it != x.rend(); it+)
#define rev(x, n) for(int i=0; i<n/2; i++) swap(x[i], x[n-i-1]);
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

/* ======= globals here ======= */
const int mod = 1'000'000'007;
const int N = 3e5;


/* ========== solving function here ========= */

void solve() {
    string s, t;
    cin>>s>>t;
    
    map<char, int> mp;
    for(int i=0; i<s.size(); i++)
        mp[s[i]]++;
        
    swap(t[0], t[2]);
    
    int ta = mp[t[0]];
    mp[t[0]] = 0;
    while(ta--)
        cout<<t[0];
    ta = mp[t[1]];
    mp[t[1]] = 0;
    while(ta--)
        cout<<t[1];
    ta = mp[t[2]];
    mp[t[2]] = 0;
    while(ta--)
    cout<<t[2];
    
    for(auto it: mp){
        if(it.S){
            int temp = it.S;
            while(temp--)
                cout<<it.F;
        }
    }
    
    cout<<endl;
}
/* ========== main function here ========= */

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;
    cin>>(t);
    while(t--) {
        solve();
    }
    return 0;
}
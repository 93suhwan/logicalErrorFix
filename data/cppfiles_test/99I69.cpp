#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define ppb 			pop_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define M               1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(x)            int x; cin>>x; while(x--)
#define ld				long double
#define nline 			"\n"
#define all(x) 			(x).begin(), (x).end()
#define PI 3.1415926535897932384626
pii fill(vector<int> &arr){
    pii p = {inf , -inf};
    for(int i=0;i<arr.size();i++){
        int x = 0;cin>>x;arr[i] = x;
        p.ff = min(p.ff , x);p.ss = max(p.ss , x);
    }
    return p;
}
void print(vi &arr){
    for(int ele : arr)cout<<ele<<" ";
    cout<<nline;
}

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1'000'000'007;

int four(int n){
    return 2*n*(n+1);
}
int five(int n){
    return n*(2*n - 1);
}
int two(int n){
    return 2 * n * n;
}
int three(int n){
    return n * (2 * n + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--) {
        int n = 0,m=0,k=0,x=0;
        string s = "";
        cin>>x>>n;
        int ans = x;
        ans += n*(n+1)/2;


        if(x%2 == 0){
            ans -= (four(n/4) + five((n+3)/4))*2;
        }else{
            ans -= (two((n+2)/4) + three((n+1)/4))*2;
        }

        cout<<ans<<nline;

        
    }

    return 0;
}



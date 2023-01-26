#include<bits/stdc++.h>
#define int long long
using namespace std;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": "; _print(x); cerr << endl;
#define debug_array(x, n) cerr << #x << ": "; _print(x, n); cerr << endl;
#else
#define debug(x)
#define debug_array(x, n)
#endif

void _print(bool t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[  "; for (T i : v) {_print(i); cerr << "  ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[  "; for (T i : v) {_print(i); cerr << "  ";} cerr << "]\n";}
template <class T> void _print(multiset <T> v) {cerr << "[  "; for (T i : v) {_print(i); cerr << "  ";} cerr << "]\n";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[  "; for (auto i : v) {_print(i); cerr << "  ";} cerr << "]\n";}
template <class T> void _print(T v[], int n) {cerr << "[  "; for (int i = 0; i < n; i++) {_print(v[i]); cerr << "  ";} cerr << "]\n";}

const int MOD = 998244353;

void run(){
    
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    
    int ways1[n+1] = {0}, ways2[n+1] = {0};

    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            ways1[0] *= 2;
            ways1[0] %= MOD;

            ways1[0]++;
            ways1[0] %= MOD;
        }
        else if(a[i] == 1){
            ways1[1] += ways1[0];
            ways1[1] %= MOD;

            ways2[1] *= 2;
            ways2[1] %= MOD;

            ways2[1]++;
            ways2[1] %= MOD;
        }
        else{
            ways1[a[i]] += ways1[a[i] - 1];
            ways1[a[i]] %= MOD;

            ways2[a[i]] += ways1[a[i]-2];
            ways2[a[i]] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        ans += (ways1[i] + ways2[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie();

    int t;
    cin >> t;
    // t = 1;

    for(int tc = 1; tc <= t; tc++){
        // cout << "Case #" << tc << ": ";
        run();
    }

}

/*


*/



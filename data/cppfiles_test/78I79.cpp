#include <bits/stdc++.h>
using namespace std;
#define MAX 31622777
#define PI 2*acos(0.0)
#define fast_io  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
 
void setIO(string s){
    if (s.empty()){
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    else{
        freopen((s + ".in").c_str(), "r", stdin);
        freopen((s + ".out").c_str(), "w", stdout);
    }
}
 
inline ll mult(ll a, ll b, ll mod){
    return (a*b-(ll)((long double)a/mod*b)*mod + mod)%mod;
}
 
inline ll ksm(ll a, ll b, ll mod){
    ll res=1;
    a %= mod;
    while(b){
        if (b & 1)
            res = mult(res, a, mod);
        a = mult(a, a, mod);
        b >>= 1;
    }
    return res % mod;
}

int main() {
    // setIO("");
    int t;
    cin >> t;
    while(t--){
        int n, x; cin >> n;
        vector<int> cont(31);
        for(int i = 0; i < n; i++){
            cin >> x;
            for(int j = 0; j <= 30; j++){
                if(x & (1<<j))cont[j]++;
            }
        }
        vector<int> res;
        if(count(cont.begin(), cont.end(), 0) == cont.size()){
            for(int i = 1; i <= n; i++){
                cout << i << " ";
            }
            cout << "\n";
        }
        else{
            int g = 0;
            for(int j = 0; j <= 30; j++){ 
                g = __gcd(g, cont[j]);
            }
            for(int i = 1; i*i <= n; i++){
                if(g%i == 0) res.push_back(i);
                if(i != (n/i) && g%(n/i) == 0)res.push_back(n/i);
            }
            sort(res.begin(), res.end());
            for(auto x: res)cout << x << " ";
            cout << "\n";
        }
    }
    
}
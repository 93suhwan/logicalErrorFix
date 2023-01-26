#include <bits/stdc++.h>
using namespace std;

#define begin_code_from_here ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define MOD 998244353

template<typename T> T MODadd(T x, T y) { x += y; while(x >= MOD) x -= MOD; while(x < 0) x += MOD; return x; }
template<typename T> T MODmul(T x, T y) { return (x * 1ll * y) % MOD; }
template<typename T> T MODbinpow(T x, T y){ T z = 1; while(y) { if(y & 1) z = MODmul(z, x); x = MODmul(x, x); y >>= 1; } return z; }   // x^y
template<typename T> T MODinv(T x) { return MODbinpow(x, MOD - 2); }
template<typename T> T MODdivide(T x, T y) { return MODmul(x, MODinv(y)); }
void Sieves(vector<bool>& prime, ll n) {prime.resize(n+1,true);for (ll p = 2; p * p <= n; p++) { if (prime[p] == true) { for (ll i = p * p; i <= n; i += p) prime[i] = false;}}}
ll lcm(ll a, ll b) { return (a / __gcd(a, b)) * b;}

/*
IMPORTANT_DEFINITIONS : 
---------------------------------------------------

lower_bound : Returns a value which is not less than x
              so, if index i is returned, then a[j] <= x, where j <= i ;

upper_bound : Returns a valud which is greater than x 
              so, if index i is returned, then a[j] > x,  where j >= i ;

*/


int main(){
    begin_code_from_here
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<ll> a(n+1);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        a[n] = 0;
        sort(a.begin(),a.end());
        
        int z;
        for(int i = 0 ; i < n ; i++){
            if(a[i] == 0){
                z = i;
                break;                
            }
        }
        ll rght = a[n];
        ll lft = abs(a[0]);       
        ll ans = 0; 
        
            // process rght
            int used = 0;
            for(int i = z+1 ; i <= n ; i++){
                used++;                
                if(i+1 < n && a[i] == a[i+1]){
                    int j = i+1;
                    while(used < k && a[j] == a[i]){
                        j++;
                        used++;
                    }
                    //cout << a[i] << " ";
                    ans += 2*a[i];
                    i = j-1;
                    used = 0;
                    continue;
                }
                
                if(used == k || i == n){
                    //cout << a[i] << " ";
                    ans += 2*a[i];
                    used = 0;
                }
            }
            
            // process left
            used = 0;
            for(int i = z-1 ; i >= 0 ; i--){
                used++;
                if(i-1 >=0 && a[i] == a[i-1]){
                    int j = i-1;
                    while(used < k && a[j] == a[i]){
                        j--;
                        used++;
                    }
                    //cout << a[i] << " ";
                    ans += 2*abs(a[i]);
                    i = j-1;
                    used = 0;
                    continue;
                }
                
                if(used == k || i == 0){     
                    //cout << a[i] << " ";               
                    ans += 2*abs(a[i]);
                    used = 0;
                }
            }
        //cout << ans << "\n";

        if(rght > lft){            
            ans -= a[n];
        }
        else{            
            ans -= abs(a[0]);
        }

        cout << ans << "\n";
    }
    return 0;
}
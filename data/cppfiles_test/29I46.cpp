#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
#define trace(x) cerr<<#x<<": "<<x<<endl;
void debug_all(){ cerr<<"]\n"; }
template<typename T, typename... Types> 
void debug_all(T var1, Types... var2) { cerr<<' '<<var1<<' '; debug_all(var2...);}
#define dbgs(...) cerr<<"["<<#__VA_ARGS__<<"]: [", debug_all(__VA_ARGS__)
int binomialCoeff(int n, int r){
    if(r > n){
        return 0;
    }
    long long int m = 1000000007;
    long long int inv[r + 1] = {0};
    inv[0] = 1;
    if(r+1 >= 2){
        inv[1] = 1;
    }
    for(int i = 2; i <= r; i++){
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
    int ans = 1;
    for (int i = 2; i <= r; i++){
        ans = ((ans % m) * (inv[i] % m)) % m;
    }
    for (int i = n; i >= (n - r + 1); i--){
        ans = ((ans % m) * (i % m)) % m;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tc, n, z, o, ans;
    cin>>tc;
    while(tc--){
        cin>>n;
        vector<ll>a(n);
        z = o = 0;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(a[i] == 0){
                z++;
            }
            else if(a[i] == 1){
                o++;
            }
        }
        ans = o;
        for(int i = 1; i <= z; i++){
            ans += o*(binomialCoeff(z,i));
        }
        cout<<ans<<endl;

    }
    return 0;
}
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
typedef long long ll;

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<pair<ll,ll>, null_type, less<pair<ll,ll>>, rb_tree_tag, tree_order_statistics_node_update>
 
int mod=998244353;
 
// ll binPow(ll a,ll b)
// {
//     if (b == 0)return 1;
//     if (b == 1)return a;
//     ll ret = binPow(a,b/2);
//     if (b%2 == 0)return (ret * ret)%mod;
//     return ((ret * ret)%mod * a)%mod;
// }
// ll inv(ll a)
// {
//     return (binPow(a,mod - 2)%mod + mod)%mod;
// }
// ll binom(ll a,ll b)
// {
//     if (b < 0 or a < 0)return 0;
//     return (((sum[a] * inv(sum[b]))%mod * inv(sum[a - b]))%mod + mod)%mod;
// }
 
// void SieveOfEratosthenes(int n,vector<int>& prime)
// {
//     prime[0]=0;
//     prime[1]=0;
//     for (int p = 2; p * p <= n; p++)
//     {
//         // If prime[p] is not changed,
//         // then it is a prime
//         if (prime[p] == 0)
//         {
//             // Update all multiples
//             // of p greater than or
//             // equal to the square of it
//             // numbers which are multiple
//             // of p and are less than p^2
//             // are already been marked.
//             for (int i = p * p; i <= n; i += p){
//                 if(prime[i]==0)
//                     prime[i]=p;
//                 else 
//                     prime[i]=min(prime[i],p);
//             }
//         }
//     }
//  }

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c=1;
        n--;
        if(n%2==0){
            int a=n/2-1;
            int b=n/2+1;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            int a=n/2;
            int b=n/2+1;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }
}
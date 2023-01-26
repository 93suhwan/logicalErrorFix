#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> super_set;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 5e5+7;
const int INF = 1e9+7;
int A[N],S[N],dp[N*2];
vector<int> V[N*2];
int pref[N*2];
void solve(){
   int n,d;
   cin>>n>>d;
   set<int> renum;

   for(int i = 1;i<=n;++i){
       cin>>S[i]>>A[i];
       renum.insert(S[i]);
       renum.insert(A[i]);
   }
   map<int,int> M;
   int ptr = 0;
   for(int to:renum){
       M[to] = ++ptr;
   }
   for(int i = 1;i<=n;++i){
       S[i] = M[S[i]];
       A[i] = M[A[i]];
       V[S[i]].push_back(A[i]);
       ++pref[S[i]];
   }
   for(int i = 1;i<=ptr+1;++i){
        pref[i] += pref[i-1];
        dp[i] = INF;
   }
   dp[1] = 0;
   for(int i = 1;i<=ptr;++i){
       int c = 0;
       for(int to:V[i]){
           if (to<=i)
               ++c;
       }
       for(int to:V[i]){
           if (to<=i)
               continue;
           dp[to] = min(dp[to],dp[i]+pref[to-1]-pref[i-1]-1-c);
       }
       dp[i+1] = min(dp[i+1],dp[i]+pref[i]-pref[i-1]-c);
   }
   cout<<n-dp[ptr+1]<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); 
#define int long long
#define ll long long
#define ull unsigned long long
#define endl "\n"
#define INF INT_MAX
#define NINF INT_MIN
#define pb push_back
#define f first
#define s second
#define debug(x) cout<<#x<<"-->"<<x<<endl
#define print(x) cout<<x<<endl
#define printc(x) cout<<x<<" "
#define foreach(arr) for(auto &e : arr) cout<<e<<" "
#define nextline cout<<"\n"
#define MOD 1000000007
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define timeTaken std::cout <<"\nTime: "<< float( clock () - begin_time ) /  CLOCKS_PER_SEC
using namespace std;
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// less: it is the basic for comparison of two function. Use less_equal for ordered multiset.
// order_of_key(k): Number of items strictly smaller than k
// find_by_order(k): kth element in a set (counting from zero) 
const int N = 1e5+2;

int32_t main(){
   FASTIO;
   const clock_t begin_time = clock();
   ll t=1;
   cin>>t;
   while(t--){
      ll m,n;
      cin>>m>>n;
      std::vector<vector<ll>> p(m, vector<ll>(n,0));
      vector<ll> maxVal(n,0);

      for(int i=0; i<m; ++i){
         for(int j=0; j<n; ++j){
            cin>>p[i][j];
            maxVal[j] = max(maxVal[j], p[i][j]);
         }
      }

      if(m <= n-1){
         ll ans = maxVal[0];
         for(int j=0; j<n; ++j) ans = min(ans, maxVal[j]);
         cout<<ans;
      }else {
         ll val = 0;
         vector<ll> minVal(m);
         for(int i=0; i<m; ++i){ 
            sort(p[i].begin(), p[i].end());
            minVal[i] = min(p[i][n-2], p[i][n-1]);
         }
         ll ans = *max_element(minVal.begin(), minVal.end());
         cout<<ans;
      }

      nextline;
   }//while
   //timeTaken;
   return 0;
}

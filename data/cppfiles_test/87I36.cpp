//ΗΔɌΞ ƘɌI⟆ΗŊΔ!!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

 
#define ull         unsigned long long
#define ld          long double
#define ll          long long 
#define Setbit(n)   __builtin_popcountll(n)
#define pb          push_back
#define ff          first
#define ss          second
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define sz(x)       (int)(x).size()
#define all(x)      x.begin(), x.end()

#define Set tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

template <typename T> using prqueue  = priority_queue<T>;
template <typename T> using prqueues = priority_queue<T,vector<T>,greater<T>>;

template <typename T> bool  ckmin(T& a,const T& b) { return b < a ? a = b ,1 : 0;}
template <typename T> bool  ckmax(T& a,const T& b) { return a < b ? a = b ,1 : 0;}
 
const ll  MOD =  998244353;
const ull INF =  1000000000000000000;
const ll  N   =  1e7+7;

void solve(){
      Set st;
      ll f,n;cin >> f >> n;
      ll a[n];
      for(int i=0;i<n;i++){
            cin >> a[i];
      }
      ll ans=0;
      map<int,int> m;
      for(int i=0;i<n;i++){
            st.insert(a[i]);
            ans+=st.order_of_key(a[i]);
      }
      cout << ans << "\n";
}
int main() {
      cin.tie(0)->sync_with_stdio(0); 
      cin.exceptions(cin.failbit);
      int T = 1;
      cin >> T;
      while(T--){
            solve();
      }
      return 0;
}


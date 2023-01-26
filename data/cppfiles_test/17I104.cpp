#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

void FastIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

using ll = long long ;
#define pi pair<int,int>

 // fast hash table :
 mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct chash { /// use most bits rather than just the lowest ones
	const uint64_t C = ll(2e18*acos((long double)-1))+71; // large odd number
	const int RANDOM = rng();
	ll operator()(ll x) const { /// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x^RANDOM)*C); }
};
template <typename T>
using ordered_set =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k .
// find_by_order(k) : K-th element in a set (counting from zero)

void txtInput(){
  freopen(".txt", "r", stdin);
  freopen(".txt", "w", stdout);
}
const int mod = 1e9 + 7 ;

int main()
{
   FastIO();
   int t , n , ans = 0  , tmp  ;
   cin >> t ;
   while(t -- ){
    cin >> n ;
    ordered_set< int > sorted ;
    ans = 0 ;
   for(int i= 0 ; i < n ; i ++ ){
     cin >> tmp  ;
     ans += min( sorted.order_of_key(tmp) ,(int) sorted.size() -  sorted.order_of_key(tmp + 1) ) ;
     sorted.insert(tmp) ;
   }
   cout << ans << "\n" ;
   }


   return 0;
}

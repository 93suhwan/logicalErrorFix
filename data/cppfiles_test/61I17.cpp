#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef vector<vbool> vvbool;
typedef pair<ll, ll> pll;
#define ff first
#define ss second
#define FAST_IO	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fileInput freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#ifdef largeInteger
	#include <boost/multiprecision/cpp_int.hpp>
	using namespace boost::multiprecision;
	// Use 'cpp_int' instead of 'int'
#endif
#ifdef useOrderedSet
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	using namespace __gnu_pbds;
	#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
	// os.find_by_order(int order), os.order_of_key(int val) {Order is 0-based index} 
	// NOTE: Using less_equal<int> comparator makes lower_bound function like upper_bound and vice-versa.
	// Same with greater_equal<int>
#endif

int main(){
	FAST_IO
	
	int TT;
	cin >> TT;
	for(int tt = 1; tt <= TT; tt++){
		#ifdef caseInfo
			cout << "Case #" << tt << ":\n";
		#endif
		ll n;
		cin >> n;
		int a, b;
		int cntT[n + 1] = {}, cntD[n + 1] = {};
		for(int i = 0; i < n; i++)	cin >> a >> b, cntT[a]++, cntD[b]++;
		ll sumT = 0, sumD = 0;
		for(int i = 1; i <= n; i++){
			sumT += max(0, cntT[i] - 1);
			sumD += max(0, cntD[i] - 1);
		}
		ll res = (n * (n - 1ll) * (n - 2ll)) / 6ll - sumT * sumD;
		cout << res << "\n";
	} 
	
	return 0;
}

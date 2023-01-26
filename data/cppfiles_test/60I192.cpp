#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // to include bit_xor

using namespace std;
using namespace __gnu_pbds;
    
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
        
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
         
typedef long long  ll; 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vbool;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pair<ll,ll>>vp;
typedef vector<pair<double,double>>vpd;
typedef pair<int, int> pii;
         
#define sz(v)   ((int)(v).size())
#define sortBegin(v)   sort(v.begin() , v.end())
#define sortEnd(v)   sort(v.rbegin() , v.rend())
#define N 300005
         
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int main() {
 	fast_io;
 	//freopen("solve.in", "r", stdin);
   //freopen("hello.out", "w", stdout);
	ll t ; cin >> t;
	while(t--){
		ll n  ; cin >> n  ;
		vl v(n);
		for (int i = 0; i < n && cin >> v[i]; i++);
		sortBegin(v);
		cout << (v[0] & v[n-1]) << endl;
	}
 
}
 


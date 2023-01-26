#include <bits/stdc++.h>
#include <ext/numeric>

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
using namespace std;
#define go ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#define ll long long
typedef vector<vector<int>> vvi;
typedef complex<long double> Point;
const double Pi = acos(-1.0), eps = 1e-8;
#define S second
#define F first
#define X real()
#define Y imag()
#define Angle(v) (atan2((v).Y , (v).X))
#define Length(v) ((long double)hypot((v).Y , (v).X))
#define Lengthsqr(v) (dot((v) , (v)))
const int mxn = 4e2 + 5, mod = 1e9 + 7, MOD = 1e9 + 7, mod2 = 998244353;


void bingo() {
	int n;
	cin>>n;
	string s1 , s2;
	cin>>s1>>s2;
	ll out = 0;
	int prv = 0;
	// one there is two ones
	// two there is two zeros
	for(int i = 0; i < n; i++){
		int a = s1[i] - '0' , b = s2[i] - '0';
		if(a + b == 1){
			out += 2;
			prv = 0;
		}else if(a + b == 0){
			if(prv == 2){
				out++;
			}
			else if(prv == 1){
				out += 2;
				prv = 0;
			}else{
				prv = 2;
			}
		}else{
			if(prv == 2){
				out += 2;
				prv = 0;
			}else{
				prv = 1;
			}
		}
	}
	if(prv == 2)
		out++;
	cout<<out<<'\n';
//	int n, m;
//	cin>>n>>m;
//	vector<array<int,2>>vi(n);
//	for(int i = 0; i < n; i++){
//		cin>>vi[i][0];
//		vi[i][1] = -(i + 1);
//	}
//	sort(vi.begin() , vi.end());
//	vector<int>v(n + 1);
//	for(int i = 0; i < n ; i++){
//		v[-vi[i][1]] =
//	}
//	set<int>st;
//	ll out = 0;
//	for(int i = 0; i < n;i++){
//		int curr = -vi[i][1];
//		int idx = *st.upper_bound(curr);
//		--idx;
//		out += idx + 1;
//		st.insert(vi[i][1]);
//	}
//	cout<<out<<'\n';
}

int main() {
	go
#ifdef LOCAL
	freopen("input.in", "rt", stdin);
//	freopen("output.out", "wt", stdout);
#endif
	//freopen("card.in", "rt", stdin);
	int t = 1;
	cin>>t;
	while (t--) {
		bingo();
	}
	return 0;
}

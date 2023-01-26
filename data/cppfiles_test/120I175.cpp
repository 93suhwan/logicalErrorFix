#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void _print(long long t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*--------------------------------------------------------------------------------------------------------------------------*/
void precision(int a) {cout << setprecision(a) << fixed;}
/*--------------------------------------------------------------------------------------------------------------------------*/

void solve(){
	int t=1;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int val=1;
		int tnum=r-l+1;
		vector<int> v;
		while(val<=r){
			if(val>=l && val<=r) v.push_back(val);
			val*=2;
		}
		int n=v.size();
		if(n==0){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		if(l<v[0]){
			ans=v[0]-l;
		}
		// ans=max(ans,tnum-tnum/2);
		for(int i=0;i<n-1;i++){
			ans=max(ans,v[i+1]-v[i]);
		}
		if(r>v[n-1]) ans=max(ans,r-v[n-1]+1);
		cout<<tnum-ans<<endl;
		
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("Error.txt", "w", stderr);
	#endif

	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
	#ifndef ONLINE_JUDGE
		cerr << "Time: " << duration . count() / 1000 <<" ms"<< endl;
	#endif
	return 0;
	
}
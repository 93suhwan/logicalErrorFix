#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
typedef tree<pi, null_type, less<pi>, rb_tree_tag,
	tree_order_statistics_node_update> oset;

const int mxn = 1000000;
int n, m;
int a[mxn], b[mxn], d[mxn], f[mxn], p[mxn];
vector<int> v;
oset s;

void sol(int x, int y, int l, int r){
	if(x > y) return;
	int z = (x + y) / 2;
	f[l] = p[r + 1] = 0, d[z] = l;
	for(int i = l; i <= r; i++) f[i + 1] = f[i] + (a[i] > b[z]);
	for(int i = r; i >= l; i--) p[i] = p[i + 1] + (a[i] < b[z]);
	for(int i = l; i <= r + 1; i++) if(f[i] + p[i] < f[d[z]] + p[d[z]]) d[z] = i;
	sol(x, z - 1, l, d[z] - 1), sol(z + 1, y, d[z], r); 
}

void answer(){
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < m; i++) cin >> b[i];
	
	sort(b, b + m);
	
	sol(0, m - 1, 0, n - 1);
	
	v.clear();
	for(int i = 0, j = 0; i <= n; i++){
		for(; j < m && d[j] <= i; j++) v.push_back(b[j]);
		if(i < n) v.push_back(a[i]);
	}
	
	ll ret = 0;
	s.clear();
	for(int i = 0; i < n + m; i++){
		ret += s.size() - s.order_of_key({v[i] + 1, -1});
		s.insert({v[i], i});
	}
	
	cout << ret << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) answer();
	
	return 0;
}
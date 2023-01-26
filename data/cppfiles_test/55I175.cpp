// Problem: E1. Rubik's Cube Coloring (easy version)
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<node, null_type, less<node>,splay_tree_tag, tree_order_statistics_node_update> splay;

const int N = 2e5+5,mod = 1e9+7;

typedef long long LL;

int t;
LL ksm(LL a,LL b){
	LL res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	// cin >> t;
	t = 1;
	while(t--){
		int k;
		cin >> k;
		LL tmp = (ksm(2,k)-2+mod)%mod;
		tmp = (tmp*2)%mod;
		cout << ksm(2,tmp)*6%mod;
	}
	return 0;
}
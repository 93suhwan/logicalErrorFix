#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> node;
typedef tree<node, null_type, less<node>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef tree<node, null_type, less<node>,splay_tree_tag, tree_order_statistics_node_update> splay;

const int N = 2e5+5;

typedef long long LL;

int t;

int main(){
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--){
		LL s,n,k;
		cin >> s >> n >> k;
		if(s<n)cout << "NO" << endl;
		else if(s<k)cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}
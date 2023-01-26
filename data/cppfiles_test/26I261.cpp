#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using i64 = long long;
using namespace std;
using namespace __gnu_pbds;
typedef tree<i64,null_type,less<i64>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
// 	freopen("kext.inp", "r", stdin);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		// cout << s << endl;
		bool ok = false;
		int teamA = 0, teamB = 0;
		for(int i = 0; i < 10; i++) {
			if(~i & 1) {
				if(s[i] == '1') teamA++;
				if(s[i] == '?') {
					if(teamA > teamB || teamA == teamB) teamA++;
				}
			}
			else {
				if(s[i] == '1') teamB++;
				if(s[i] == '?') {
					if(teamB > teamA) teamB++;
				}
			}
			if(teamA > teamB && teamA - teamB > 10 - i - 1) {
				cout << i << endl;
				ok = true;
				break;
			}
			else if(teamB > teamA && teamB - teamA > 10 - i - 1) {
				cout << i << endl;
				ok = true;
				break;
			}
		}
		if(!ok) cout << "10" << endl;
	}
	return 0;
}
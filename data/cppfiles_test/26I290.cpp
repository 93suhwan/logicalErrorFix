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
		int A = 0, B = 0;
		for(int i = 0; i < 10; i++) {
			if(~i & 1 && s[i] != '0') A++;
			else if(i & 1 && s[i] != '0') B++; 
		}
		bool ok = false;
		int teamA = 0, teamB = 0;
		int ans_A, ans_B;
		for(int i = 0; i <= 10; i++) {
			if(i == 10) {
				ans_A = 10;
				break;
			}
			if(~i & 1) {
				if(s[i] == '1') teamA++;
				if(s[i] == '?') teamA++;
			}
			else {
				if(s[i] == '1') teamB++;
			}
			if(teamA > teamB && teamA - teamB > 10 - i - 1) {
				ans_A = i;
				break;
			}
			else if(teamB > teamA && teamB - teamA > 10 - i - 1) {
				ans_A = i;
				break;
			}
		}
		teamA = 0, teamB = 0;
		for(int i = 0; i <= 10; i++) {
			if(i == 10) {
				ans_B = 10;
				break;
			}
			if(~i & 1) {
				if(s[i] == '1') teamA++;
			}
			else {
				if(s[i] == '1') teamB++;
				if(s[i] == '?') teamB++;
			}
			if(teamA > teamB && teamA - teamB > 10 - i - 1) {
				ans_B = i;
				break;
			}
			else if(teamB > teamA && teamB - teamA > 10 - i - 1) {
				ans_B = i;
				break;
			}
		}
		cout << min(ans_A, ans_B) << endl;
	}
	return 0;
}
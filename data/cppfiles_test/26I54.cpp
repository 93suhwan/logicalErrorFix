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
		bool ok = false;
		int teamA = 0, teamB = 0;
		int ans_A = 10, ans_B = 10, ans_C = 10;
		for(int i = 1; i <= 10; i++) {
			if(~(i - 1) & 1) {
				if(s[i - 1] == '1') teamA++;
				if(s[i - 1] == '?') teamA++;
			}
			else {
				if(s[i - 1] == '1') teamB++;
			}
			int matchA = (10 - i) / 2;
			int matchB = (10 - i) / 2;
			if(~(i - 1) & 1) matchB++;
			else matchA++;
			if(teamB > teamA && teamB - teamA > matchA) {
				ans_A = i;
				break;
			}
			else if(teamA > teamB && teamA - teamB > matchB){
				ans_A = i;
				break;
			}
		}
		teamA = 0, teamB = 0;
		for(int i = 1; i <= 10; i++) {
			if(~(i - 1) & 1) {
				if(s[i - 1] == '1') teamA++;
			}
			else {
				if(s[i - 1] == '1') teamB++;
				if(s[i - 1] == '?') teamB++;
			}
			int matchA = (10 - i) / 2;
			int matchB = (10 - i) / 2;
			if(~(i - 1) & 1) matchB++;
			else matchA++;
			if(teamB > teamA && teamB - teamA > matchA) {
				ans_B = i;
				break;
			}
			else if(teamA > teamB && teamA - teamB > matchB){
				ans_B = i;
				break;
			}
		}
		teamA = 0, teamB = 0;
		for(int i = 1; i <= 10; i++) {
			if(~(i - 1) & 1) {
				if(s[i - 1] == '1') teamA++;
				if(s[i - 1] == '?') teamA++;
			}
			else {
				if(s[i - 1] == '1') teamB++;
				if(s[i - 1] == '?') teamB++;
			}
			int matchA = (10 - i) / 2;
			int matchB = (10 - i) / 2;
			if(~(i - 1) & 1) matchB++;
			else matchA++;
			if(teamB > teamA && teamB - teamA > matchA) {
				ans_C = i;
				break;
			}
			else if(teamA > teamB && teamA - teamB > matchB){
				ans_C = i;
				break;
			}
		}
		cout << min({ans_A, ans_B, ans_C}) << endl;
	}
	return 0;
}
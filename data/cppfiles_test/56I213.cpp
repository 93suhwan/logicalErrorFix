#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define siz(x) (int)x.size()

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

bool ckmin(auto &a, const auto &b) { return b < a ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return b > a ? a = b, 1 : 0; }

int qry(int x, int y) {
	cout << x << " " << y << endl; 
	string res; 
	cin >> res; 
	if (res == "Done") 
		return 0;
	else if (res == "Right" || res == "Left")
		return 1; 
	else if (res == "Down-Right" || res == "Down-Left" || res == "Down") 
		return 2; 
	else 
		return 3; 
}

int reps = 0; 

void solve() {
	auto w = qry(1, 8); 
	if (w == 0) 
		return; 
	for (int row = 1; row <= 8; row++) {
		for (int i = 1; i <= 8; i++) {
			reps++; 
			if (reps >= 200) 
				exit(0); 
			w = qry(row, i); 
			if (w == 0) 
				return; 
			else if (w == 2) {
				if (i != 1)
					qry(row, 1);
				goto jmp; 
			} else if (w == 3) {
				if (i == 1) 
					i = 1; 
				else 
					i = 0; 
				continue; 
			} 
		}
		
		qry(row, 1); 
		;jmp:;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t; 
	cin >> t; 
	while (t--) {
		solve();
	}
}
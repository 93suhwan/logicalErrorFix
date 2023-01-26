#include<bits/stdc++.h>
#define f first
#define s second
#define int long long
#define pii pair<int,int>
using namespace std;
const int N = 2e5 + 5, inf = 1e15 + 5; // !
int t,n,a[N],done[N],dp[N];
set<pii> s;
vector<pii> aft[N];
main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		s.clear();
		aft[0].clear();
		for(int i = 1; i <= n; i++) {
			s.insert({a[i],i});
			aft[i].clear();
		}
		s.insert({0,0});
		for(int i = 1; i <= m; i++) {
			int l,r;
			cin >> l >> r;
			done[i] = dp[i] = inf;
			if(s.upper_bound({l,0}) != s.end() && (*s.upper_bound({l,0})).f <= r) continue;
			aft[(*--s.upper_bound({l,0})).s].push_back({l,r});
		}
		for(int i = 0; i <= n; i++) {
			int m = inf,min_ = done[i - 1], min_2 = done[i - 1];
			sort(aft[i].begin(),aft[i].end());
			for(int j = (int)aft[i - 1].size() - 1; j >= 0; j--) {
				int l = aft[i - 1][j].f, r = aft[i - 1][j].s;
				m = min(m,r);
				
				min_ = min(min_, (a[i] - m) * 2 + (j > 0 ? dp[j - 1] : (i > 1) * done[i - 2]));
				min_2 = min(min_2, a[i] - m + (j > 0 ? dp[j - 1] : (i > 1) * done[i - 2]));
			}
			done[i - 1] = min(done[i - 1], min_2);
			if(!aft[i].size()) {
				
				done[i] = min_2;
				continue;
			}
			
			for(int j = 0; j < aft[i].size(); j++) {
				int l = aft[i][j].f, r = aft[i][j].s;
				dp[j] = min(min_2 + (l - a[i]) * 2, min_ + (l - a[i]));
				done[i] = dp[j];
				if(!i) dp[j]  = inf;
			}
			if(!i) done[i] = inf;
			if(done[i] < 0) {
				cout << i;
				return 0;
			}
		} //cout << endl;
		cout << done[n] <<" ";
	}
 }

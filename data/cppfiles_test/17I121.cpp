#define REP(i, n) for(int i = 0; i < n; i ++)
#define REPL(i,m, n) for(int i = m; i < n; i ++)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(arr) sort(arr.begin(), arr.end())
#define LSOne(S) ((S)&-(S))
#define M_PI 3.1415926535897932384
#define INF 999999999
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef double ld;
typedef tree<ii,null_type,less<ii>,rb_tree_tag, tree_order_statistics_node_update> ost;
void solve() {
	int n;cin>>n;
	int tot =0;
	ost tr;
	int x;cin>>x;
	tr.insert({x,0});
	REP(i, n-1) {
		int y;cin>>y;
		int lw = tr.order_of_key({y, -1});
		int hgh = tr.size() - tr.order_of_key({y+1, -1});
		tot += min(lw, hgh);
		tr.insert({y,i+1});
	}cout<<tot<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int tc;
	cin>>tc;
	REP(i, tc) {
		solve();
	}

}
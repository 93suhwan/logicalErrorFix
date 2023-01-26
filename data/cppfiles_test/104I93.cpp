#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define deb(x)          cout << #x << "=" << x << endl
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define all(x)			x.begin(), x.end()
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)

mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	w(x) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int> > food;
		vector<pair<int, int> > food_ranges;
		int X = 0, Y = 0;
		int sub = 0, ans;
		rep(i, 0, n) {
			int fish, meat;
			cin >> fish >> meat;
			food.pb({fish, meat});
			sub += fish - meat;
			int l = m - meat > 0 ? m - meat : 0;
			food_ranges.pb({l, min(fish, m)});
			X += food_ranges[i].ff;
			Y += food_ranges[i].ss;
		}

		/*rep(i, 0, n) {
			cout << food_ranges[i].ff << " " << food_ranges[i].ss << "\n";
		}*/
		sub += n * m;
		/*deb(sub);
		deb(X);
		deb(Y);*/
		int comp = sub / 2;
		if (comp >= X and comp <= Y) {
			if (sub & 1) {
				ans = 1;
			} else {
				ans = 0;
			}
			cout << ans << "\n";
			int sum = 0;
			int i = 0;
			while (sum < comp and i < n) {
				cout << food_ranges[i].ss << " " << m - food_ranges[i].ss << "\n";
				i++;
				sum += food_ranges[i].ss - food_ranges[i].ff;
			}

			while (i < n) {
				cout << food_ranges[i].ff << " " << food_ranges[i].ff << "\n";
				i++;
			}


		} else if (comp < X) {
			ans = abs(sub - 2 * X);
			cout << ans << "\n";
			rep(i, 0, n) {
				cout << food_ranges[i].ff << " " << m - food_ranges[i].ff << "\n";
			}
		} else {
			ans = abs(sub - 2 * Y);
			cout << ans << "\n";
			rep(i, 0, n) {
				cout << food_ranges[i].ss << " " << m - food_ranges[i].ss << "\n";
			}
		}

	}
}

int32_t main()
{
	clock_t begin = clock();
	c_p_c();
#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define var(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define sz(x) ((int)x.size())
#define vec vector
#define endl "\n"

struct Node
{
	int l, r, p;
};

int n, k;

const int N = 2e5 + 5;

auto level = vec(N + 1, '.');
auto tree = vec(N + 1, Node{});
auto ids = vec(N + 1, 0);
auto res = vec(N + 1, string(""));

auto dupli = vec(N + 1, '.');

int curr_id = 0;

auto nearest_index = vec(26, deque<int>());

void dfs(int s)
{
	if (tree[s].l != 0)
	{
		dfs(tree[s].l);
	}

	curr_id++;

	ids[s] = curr_id;
	nearest_index[level[s] - 'a'].push_back(curr_id);

	res[curr_id] = level[s];

	if (tree[s].r != 0)
	{
		dfs(tree[s].r);
	}
}

auto k_cnt = vec(N + 1, 0);

void dfs1(int s, int req, bool can_level)
{
	k_cnt[s] = req;

	if (tree[s].l != 0)
	{
		dfs1(tree[s].l, req + 1, can_level);
	}

	int id = ids[s];

	int greater_id = INT_MAX;
	int smaller_id = INT_MAX;

	nearest_index[level[s] - 'a'].pop_back();

	for (int j = 0; j < 26 && can_level; j++)
	{
		if (j == level[s] - 'a' || nearest_index[j].empty())
		{
			continue;
		}

		int curr = nearest_index[j].front();


		if (j < level[s] - 'a')
		{
			smaller_id = min(smaller_id, curr);
		}
		else if (j > level[s] - 'a')
		{
			greater_id = min(greater_id, curr);
		}
	}

	if (greater_id < smaller_id && k_cnt[s] <= k)
	{
		int me = s;

		while (true)
		{
			if (me == 0 || k_cnt[me] == 0)
			{
				break;
			}
			k_cnt[me] = 0;
			me = tree[me].p;
			k--;
		}
	}


	if (tree[s].r != 0)
	{

		dfs1(tree[s].r, k_cnt[s] + 1, k_cnt[s] == 0);
	}

	if (k_cnt[s] == 0)
	{
		//cout << var(id) << var(s) << var(greater_id) << var(smaller_id) << endl;
		res[id] += res[id];
	}
}

void run_case([[maybe_unused]] const int &TC)
{
	cin >> n >> k;

	string s;
	cin >> s;

	for (int i = 1; i <= n; i++)
	{
		level[i] = s[i - 1];
	}

	tree[1].p = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> tree[i].l >> tree[i].r;

		tree[tree[i].l].p = i;
		tree[tree[i].r].p = i;
	}

	dfs(1);

	dfs1(1, 1, true);

	for (int i = 1; i <= n; i++)
	{
		cout << res[i];
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);

	int t = 1;
	//cin >> t;

	for (int tc = 1; tc <= t; tc++)
		run_case(tc);

	return 0;
}
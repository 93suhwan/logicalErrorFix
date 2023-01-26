#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const long long mod = 1'000'000'007;

template<typename T>
void deb(initializer_list<T> l)
{
	for (auto &e : l)
		cout << e << ' ';
	cout << endl;
}

int timer = 0;
vector<int> in, out, parent;
vector<bool> parity;

void dfs(int u, int p, vector<vector<int>>& adj, vector<bool>& vis)
{
	in[u] = timer++;
	vis[u] = true;
	parent[u] = p;

	for (int i = 0; i < (int) adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if (!vis[v])
			dfs(v, u, adj, vis);
		else
		{
			swap(adj[u][i], adj[u].back());
			adj[u].pop_back();
			--i;
		}
	}

	out[u] = timer++;
}

bool isAncestor(int u, int v)
{
	return in[u] <= in[v] && out[v] <= out[u];
}

void findPath(int u, int v, vector<int>& path, vector<vector<int>>& adj)
{
	// deb({u, v});
	path.push_back(u);
	if (u == v)
		return;

	if (!isAncestor(u, v))
	{
		parity[u] = !parity[u];
		findPath(parent[u], v, path, adj);
	}
	else
	{
		for (auto& child : adj[u])
		{
			if (isAncestor(child, v))
			{
				parity[child] = !parity[child];
				findPath(child, v, path, adj);
				break;
			}
		}
	}
}

vector<vector<bool>> calc;

int dfs(int u, int continues, vector<vector<int>>& dp,
		vector<vector<int>>& adj)
{
	if (calc[continues][u])
		return dp[continues][u];

	calc[continues][u] = true;
	vector<int> oddEdge;
	for (auto& v : adj[u])
		if (parity[v])
			oddEdge.push_back(v);

	int& ret = dp[continues][u];
	if (continues)
	{
		if (!oddEdge.empty())
		{
			ret += dfs(oddEdge.back(), continues, dp, adj);
			oddEdge.pop_back();
		}
		else
			++ret;

		for (auto& v : oddEdge)
			ret += dfs(v, 0, dp, adj);
		for (auto& v : adj[u])
			if (!parity[v])
				ret += dfs(v, 0, dp, adj);

		return ret;
	}

	if ((int) oddEdge.size() >= 2)
	{
		int a = oddEdge.back();
		oddEdge.pop_back();
		int b = oddEdge.back();
		oddEdge.pop_back();

		ret += dfs(a, 1, dp, adj) + dfs(b, 1, dp, adj) - 1;
	}
	else if ((int) oddEdge.size() == 1)
	{
		int a = oddEdge.back();
		oddEdge.pop_back();
		ret += dfs(a, 1, dp, adj);
	}

	for (auto& v : oddEdge)
		ret += dfs(v, 0, dp, adj);
	for (auto& v : adj[u])
		if (!parity[v])
			ret += dfs(v, 0, dp, adj);

	return ret;
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	in.resize(n);
	out.resize(n);
	parent.resize(n);
	parity.resize(n);
	vector<bool> vis(n);
	dfs(0, -1, adj, vis);

	// for (int i = 0; i < n; ++i)
	// 	deb({i, in[i], out[i]});
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << i << ": ";
	// 	for (auto& v : adj[i])
	// 		cout << v << ' ';
	// 	cout << endl;
	// }

	int Q;
	cin >> Q;
	vector<vector<int>> path(Q);

	for (int q = 0; q < Q; ++q)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;

		path[q].reserve(n);
		findPath(a, b, path[q], adj);
	}

	if (!accumulate(parity.begin(), parity.end(), 0))
	{
		cout << "YES\n";
		for (auto& path : path)
		{
			cout << path.size() << '\n';
			for (auto& e : path)
				cout << e + 1 << ' ';
			cout << '\n';
		}

		return;
	}

	calc.resize(2, vector<bool>(n));
	vector dp(2, vector<int>(n));
	cout << "NO\n" << dfs(0, 0, dp, adj) << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();

	return 0;
}

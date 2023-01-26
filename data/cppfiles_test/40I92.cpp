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

int n, m;
vector<vector<int>> adj;

vector<int> parent, in, out;
int timer = 0;

void dfs(int u, int par, vector<bool>& vis)
{
	in[u] = timer++;
	vis[u] = true;
	parent[u] = par;

	for (auto& v : adj[u])
		if (!vis[v])
			dfs(v, u, vis);

	out[u] = timer++;
}

bool isAncestor(int u, int v)
{
	return in[u] <= in[v] && out[v] <= out[u];
}

auto getPath(int u, int v)
{
	vector<int> path;
	while (true)
	{
		path.push_back(u);
		if (isAncestor(u, v))
			break;

		u = parent[u];
	}

	return path;
}

void solve()
{
	cin >> n >> m;

	adj.resize(n);
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	parent.resize(n);
	in.resize(n);
	out.resize(n);
	vector<bool> vis(n);
	dfs(0, -1, vis);

	int Q;
	cin >> Q;
	vector<vector<int>> path(Q);
	vector<bool> parity(n);

	for (int q = 0; q < Q; ++q)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;

		parity[u] = !parity[u];
		parity[v] = !parity[v];

		path[q] = getPath(u, v);
		auto path2 = getPath(v, u);
		path2.pop_back();
		path[q].insert(path[q].end(), path2.rbegin(), path2.rend());

	}

	int odd = accumulate(parity.begin(), parity.end(), 0);
	if (odd)
		cout << "NO\n" << odd / 2 << '\n';
	else
	{
		for (auto& path : path)
		{
			cout << path.size() << '\n';
			for (auto& e : path)
				cout << e + 1 << ' ';
			cout << '\n';
		}
	}
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

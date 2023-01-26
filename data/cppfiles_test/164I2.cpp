#include <bits/stdc++.h>
using namespace std;
template<typename A,typename B>
string to_string(pair<A,B>p){return"("+to_string(p.first)+", "+to_string(p.second)+")";}
template<typename A,typename B,typename C>
string to_string(tuple<A,B,C>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+")";}
template<typename A,typename B,typename C,typename D>
string to_string(tuple<A,B,C,D>p){return"("+to_string(get<0>(p))+", "+to_string(get<1>(p))+", "+to_string(get<2>(p))+", "+to_string(get<3>(p))+")";}
string to_string(const string &s){return'"'+s+'"';}
string to_string(const char *s){return to_string((string)s);}
string to_string(bool b){return(b?"true":"false");}
string to_string(vector<bool>v){int f=0;string r="{";for(bool i:v)r+=(f++?",":"")+to_string(i);r+="}";return r;}
template<size_t N>
string to_string(bitset<N>v){string res="";for(size_t i=0;i<N;res+=char('0'+v[i++]));return res;}
template<typename A>
string to_string(A v){int f=0;string r="{";for(auto&i:v)r+=(f++?",":"")+to_string(i);r+="}";return r;}
void debug_out(){cerr<<']'<<endl;}
template<typename Head,typename...Tail>
void debug_out(Head H,Tail...T){cerr<<to_string(H);if(sizeof...(T))cerr<<", ";debug_out(T...);}
#ifdef LOCAL
#define debug(x...) cerr << "[" << (#x) << "] = [", debug_out(x)
#else
#define debug(x...) 33
#endif
#define int long long
int N, K;
char S[200'200];
vector<int> g[200'200];
int par[200'200];
int dep[200'200];

vector<int> dfsOrder;
int dfsN[200'200];
void dfs(int now)
{
	
	for (int i = 0; i < 2; ++i)
	{
		int it = g[now][i];
		if (it != -1) 
		{
			dep[it] = dep[now] + 1;
			dfs(it);
		}
		if (!i)
		{
            dfsN[now] = (int)dfsOrder.size();
            dfsOrder.push_back(now);
        }
	}
	// for (auto &it: g[now]) 
	// {
	// 	if (it != -1) 
	// 	{
	// 		dep[it] = dep[now] + 1;
	// 		dfs(it);
	// 	}
	// }
}
int nextNode[200'200];
bool go_dup[200'200];
int NodeNode[200'200];

bool real_iduc[200'200];
int for_who_dfsN[200'200];
int reachable_dfsN[200'200];
void dfs2(int now)
{
	for (auto &it: g[now]) 
	{
		if (it != -1) dfs2(it);
	}
	real_iduc[now] = go_dup[now];
	if (go_dup[now])
	{
		for_who_dfsN[now] = dfsN[now];
		reachable_dfsN[now] = dfsN[now];
	}
	if (g[now][0] != -1)
	{
		real_iduc[now] |= real_iduc[g[now][0]];

		if (real_iduc[g[now][0]])
		{
			for_who_dfsN[now] = for_who_dfsN[g[now][0]];

			if (reachable_dfsN[now] == -1)
			{
				reachable_dfsN[now] = reachable_dfsN[g[now][0]];
			}
		}

	}
}
void dfs3(int now, int reallll)
{
	real_iduc[now] = real_iduc[now] && reallll;
	for (auto &it: g[now])
	{
		if (it != -1) dfs3(it, reallll && real_iduc[now]);
	}
}
int really_dup[200'200];

int find_cost(int now)
{
	if (really_dup[now]) return 0;
	if (now == 0) return 1;
	return find_cost(par[now]) + 1;
}
void fill_really_dup(int now)
{
	if (really_dup[now]) return;
	really_dup[now] = true;
	if (now == 0) return;
	fill_really_dup(par[now]);
}
signed main()
{
    cin.tie(0)->sync_with_stdio(false);
	memset(reachable_dfsN, -1, sizeof reachable_dfsN);
	cin >> N >> K;
	cin >> S;

	par[0] = -1;
	for (int i = 0; i < N; ++i)
	{
		int u, v; cin >> u >> v; --u, --v;

		g[i].push_back(u);
		g[i].push_back(v);
		
		par[u] = par[v] = i;
	}
	dfs(0);
	// debug(dfsOrder);
	memset(nextNode, -1, sizeof nextNode);
	for (int x = 0; x + 1 < (int)dfsOrder.size(); ++x)
	{
		nextNode[dfsOrder[x]] = dfsOrder[x + 1];
	}

	for (int i = 0, j = 0; i < (int)dfsOrder.size(); ++i)
	{
		while(j < (int)dfsOrder.size() && S[dfsOrder[i]] == S[dfsOrder[j]])
			++j;

		assert(i < j);
		if (j == (int)dfsOrder.size())
		{
			NodeNode[dfsOrder[i]] = -1;
		}
		else
		{
			NodeNode[dfsOrder[i]] = dfsOrder[j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (NodeNode[i] == -1) go_dup[i] =false;
		else
		{
			assert(S[i] != S[NodeNode[i]]);

			if (S[i] > S[NodeNode[i]]) go_dup[i] = false;
			else go_dup[i] = true;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (dep[i] >= K)
		{
			go_dup[i] = false;
		}
	}
	dfs2(0);
	dfs3(0, 1);
	
	vector<pair<int, int>> ps;
	for (int i = 0; i < N; ++i)
	{
		if (real_iduc[i])
		{
			ps.push_back(make_pair(dfsN[i], i));
		}
	}
	sort(ps.begin(), ps.end());
	for (auto &[dN, node]: ps)
	{
		int cost = find_cost(node);
		if (cost <= K)
		{
			K -= cost;
			fill_really_dup(node);
		}
	}

	// vector<tuple<int, int, int>> omy;
	// for (int i = 0; i < N; ++i)
	// {
	// 	if (real_iduc[i])
	// 	{
	// 		omy.push_back({for_who_dfsN[i], -dep[i], i});
	// 	}
	// }
	// sort(omy.begin(), omy.end());
	// for (int i = 0; i < K && i < (int)omy.size(); ++i)
	// {
	// 	really_dup[get<2>(omy[i])] = true;
	// }

	// vector<pair<int, int>> pp;
	// for (int i = 1; i < N; ++i)
	// {

	// 	pp.push_back({dep[i], i});
	// }
	// sort(pp.begin(), pp.end());
	// for (auto &[dp, node]: pp)
	// {
		
	// 	if (really_dup[par[node]] == false)
	// 	{
	// 		really_dup[node] = false;
	// 	}
	// }
	// for (int i = 1; i < N; ++i)
	// {
	// 	if (really_dup[i]) assert(really_dup[par[i]]);
	// }
	
	for (auto &it: dfsOrder)
	{
		cout << S[it];

		if (really_dup[it]) cout << S[it];
	}
	cout << '\n';

    return 0;
}
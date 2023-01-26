#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <numeric>
#include <bitset>
#include <ext/algorithm>
#include <ext/numeric>
#define ffor(_a,_f,_t) for(int _a=(_f),__t=(_t);_a<__t;_a++)
#define all(_v) (_v).begin() , (_v).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define SET(__set, val) memset(__set, val, sizeof(__set))
#define FOR(__i, __n) ffor (__i, 0, __n)
typedef long long LL; using namespace std;

int n, k;

const int MAXN = 1 << 18;

int G[MAXN][2];
string S;
vector<pair<char, int>> vals;
int mapToV[MAXN];
int p[MAXN];

int dfsVals(int v, int idx) {
	if (v == -1)
		return idx;
	int ret = dfsVals(G[v][0], idx);
	vals.pb({S[v], ret});
	mapToV[ret] = v;
	ret++;
	return dfsVals(G[v][1], ret);;
}

bool duplicate[MAXN];
int valsIdx;

void markParents(int v) {
	if (v < 0 || duplicate[v])
		return;
	duplicate[v] = true;
	markParents(p[v]);
}

void dfsDuplicate(int v, int nonMarkedParents) {
	if (v == -1)
		return;
	dfsDuplicate(G[v][0], nonMarkedParents + 1);

	int target;
	while (valsIdx < SZ(vals) && duplicate[target = mapToV[vals[valsIdx].second]])
		valsIdx++;


	if (valsIdx < SZ(vals) && target == v) {
		int need = nonMarkedParents + 1;
		if (need <= k) {
			k -= need;
			markParents(v);
		}
	}
	if (duplicate[v])
		dfsDuplicate(G[v][1], 0);
}

string Sret;

void createSolution(int v) {
	if (v < 0)
		return;
	createSolution(G[v][0]);
	Sret.pb(S[v]);
	if (duplicate[v])
		Sret.pb(S[v]);
	createSolution(G[v][1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	
	cin >> n >> k;
	cin >> S;
	int a, b;
	SET(p, 255);
	FOR (i, n) {
		cin >> a >> b;
		a--;
		b--;
		G[i][0] = a;
		G[i][1] = b;
		p[a] = p[b] = i;
	}
	
	vals.clear();
	dfsVals(0, 0);
	sort(all(vals));
	if (vals[0].first == vals[SZ(vals) - 1].first) {
		cout << S << endl;
		return 0;
	}
	
	SET(duplicate, 0);
	valsIdx = 0;
	dfsDuplicate(0, 0);
	
	Sret = "";
	createSolution(0);
	cout << Sret << endl;
	
	return 0;
}

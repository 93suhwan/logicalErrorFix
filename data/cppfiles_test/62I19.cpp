#include <bits/stdc++.h>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3fll
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
const int SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);

template<typename T> struct Color{
	set<tuple<int, int, T>> se; 
	vector<tuple<int, int, T>> update(int l, int r, T c) {
		auto ret = query(l, r);
		se.erase(se.lower_bound({l, -INF, c}), se.upper_bound({r, INF, c}));
		se.emplace(l, r, c);
		return ret;
	}
	auto cut(int x){
		auto it = se.lower_bound({x, -INF, T()});
		if (it != se.begin() and get<1>(*prev(it)) >= x) {
			auto [L, R, C] = *--it;
			se.erase(it);
			se.emplace(L, x-1, C), it = se.emplace(x, R, C).first;
		}
		return it;
	}
	vector<tuple<int, int, T>> query(int l, int r){
		cut(r+1);
		vector<tuple<int, int, T>> ret;
		for(auto it = cut(l); it != se.end() and get<0>(*it) <= r; ++it)
			ret.push_back(*it);
		return ret;
	}
	T query(int i){
		if (auto it = se.upper_bound({i, INF, T()}); it == se.begin() or get<1>(*--it) < i) return -1;
		else return get<2>(*it);
	}
	ii getInterval(int i){//Ainda precisa fazer a união com os intervalos adjacentes
		auto it = se.upper_bound({i, INF, T()});
		it--;
		return {get<0>(*it), get<1>(*it)};
	}
};

int dx[2] = {1, 0};
int dy[2] = {0, 1};

void test_case(){
	int n, m, q, x, y;
	cin >> n >> m >> q;
	if(max(n, m) == 1){
		for(int i = 0; i < q; i++){
			cin >> x >> y;
			cout << (i%2) << '\n';
		}
	}
	vector<Color<int>> C(n+m);
	vector<vector<int>> status(n, vector<int>(m, 1));
	vector<vector<vector<ii>>> diagonal(n, vector<vector<ii>>(m));
	auto valid = [&](int x, int y){
		return x < n && y < m;
	};
	ll ans = n * m;
	auto f = [&](int n){
		return n*(n-1)/2;
	};
	int k = 0;
	for(int i = 0; i < n-1; i++){
		int x = i;
		int y = 0;
		int pos = 0;
		do{
			diagonal[x][y].emplace_back(k, pos);
			x = x + dx[pos&1];
			y = y + dy[pos&1];
			pos++;
		}while(valid(x, y));
		C[k].update(0, pos-1, 1);
		ans += f(pos);
		k++;
	}
	for(int i = 0; i < m-1; i++){
		int x = 0;
		int y = i;
		int pos = 0;
		do{
			diagonal[x][y].emplace_back(k, pos);
			pos++;
			x = x + dx[pos&1];
			y = y + dy[pos&1];
		}while(valid(x, y));
		C[k].update(0, pos-1, 1);
		ans += f(pos);
		k++;
	}
	while(q--){
		cin >> x >> y;
		x--;y--;
		if(status[x][y]){
			for(auto [d, pos]: diagonal[x][y]){
				auto [l, r] = C[d].getInterval(pos);
				C[d].update(pos, pos, 0);
				ans -= f(r-l+1);
				ans += f(r-pos);
				ans += f(pos-l);
			}
			ans--;
		}
		else{
			for(auto [d, pos]: diagonal[x][y]){
				int l = pos, r = pos;
				if(C[d].query(pos-1) == 1) l = C[d].getInterval(pos-1).f;
				if(C[d].query(pos+1) == 1) r = C[d].getInterval(pos+1).s;
				auto V = C[d].update(l, r, 1);
				ans += f(r-l+1);
				ans -= f(r-pos);
				ans -= f(pos-l);
			}
			ans++;
		}
		status[x][y]^=1;
		cout << ans << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int t = 1;
	//cin >> t;
	for(int i = 1; i <= t; i++){
		//cout << "Case #"<< i << ":" << endl;
		test_case();
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> sz(k);
	vector<vector<int>> ind(k);
	for(auto i = 0; i < k; ++ i){
		cin >> sz[i];
		ind[i].resize(sz[i]);
		for(auto &t: ind[i]){
			cin >> t, -- t;
		}
	}
	vector<vector<array<int, 2>>> range(k);
	for(auto i = 0; i < k; ++ i){
		y_combinator([&](auto self, int l, int r)->void{
			if(r - l == 1){
				return;
			}
			int m = l + r >> 1;
			self(l, m), self(m, r);
			range[i].push_back({l, r});
		})(0, sz[i]);
	}
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	for(auto START = high_resolution_clock::now(); duration<double>(high_resolution_clock::now() - START).count() <= 0.9; ){
		shuffle(p.begin(), p.end(), rng);
		for(auto t = 0; t < k; ++ t){
			for(auto [l, r]: range[t]){
				int m = l + r >> 1;
				static vector<int> temp;
				temp.clear();
				for(auto i = l, j = m; i < m || j < r; ){
					if(j == r || i < m && p[ind[t][i]] < p[ind[t][j]]){
						temp.push_back(p[ind[t][i ++]]);
					}
					else{
						temp.push_back(p[ind[t][j ++]]);
					}
				}
				for(auto i = l; i < r; ++ i){
					p[ind[t][i]] = temp[i - l];
				}
			}
		}
		if(!is_sorted(p.begin(), p.end())){
			cout << "REJECTED\n";
			return 0;
		}
	}
	cout << "ACCEPTED\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////
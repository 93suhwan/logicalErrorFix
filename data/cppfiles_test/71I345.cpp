#pragma GCC target ("sse4")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

#define endl '\n'
#define pb push_back
#define fr first
#define sc second
#define ll long long int
#define ld long double
#define bit(idx) idx&(-idx)
#define bin(x) bitset<32>(x).to_string()
#define all(A) A.begin(), A.end()
#define de(x) cout << #x << " = " << x << endl;

using namespace std;
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using matrix = vector<vector<T>>;
/// find_by_order(x) -> x-th element in the set
/// order_of_key(x)  -> how many elements are smaller than x
/// insert(x)		 -> inserts x into the set

set<ll> S1, S2;

void init(){
	for(auto x : {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111}){
		for(int i = 1; i <= 9; i ++){
			S1.insert(x * i);
		}
	}
	for(int A = 0; A <= 9; A ++){
		for(int B = 0; B <= 9; B ++){
			if(A == B) continue;
			for(int len = 0; len <= 9; len ++){
				for(int i = 0; i < (1 << len); i ++){
					ll x = 0;
					for(int j = 0; j < len; j ++){
						x *= 10;
						if((i >> j) & 1){
							x += A;
						}
						else{
							x += B;
						}
					}
					ll xx = x, used[10] = {0}, cnt = 0;
					while(xx){
						if(!used[xx % 10]){
							used[xx % 10] = 1;
							++ cnt;
						}
						xx /= 10;
					}
					if(cnt == 2) S2.insert(x);
				}
			}
		}
	}
}

void s(){
	ll n, k; cin >> n >> k;
	cout << (k == 1 ? *lower_bound(all(S1), n) : *lower_bound(all(S2), n)) << endl;
}

int main(){
	/// ios_base::sync_with_stdio(false); cin.tie(NULL);
	init();
	int t; cin >> t; while(t --) s();
}
/**
4
1 1
221 2
177890 2
998244353 1


*/
//#define _GLIBCXX_DEBUG
#pragma region Template
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
namespace std{template<class F>class y_combinator_result{F f_;public:template <class T>explicit y_combinator_result(T&&f):f_(forward<T>(f)){}template<class...A>decltype(auto)operator()(A&&...a){returnf_(ref(*this),forward<A>(a)...);}};template<class F>inline decltype(auto)y_combinator(F &&f){return y_combinator_result<decay_t<F>>(forward<F>(f));}}
#endif
using namespace std;using pii=pair<int,int>;using tii=tuple<int,int,int>;using qii=tuple<int,int,int,int>;using ll=long long;using pll=pair<ll,ll>;using tll=tuple<ll,ll,ll>;using qll=tuple<ll,ll,ll,ll>;using ld=long double;using pld=pair<ld,ld>;using tld=tuple<ld,ld,ld>;using qld=tuple<ld,ld,ld,ld>;const ll INF=2e9+11,llINF=1e17+11;
struct custom_hash{static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}size_t operator()(uint64_t x)const{static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}size_t operator()(pair<uint64_t,uint64_t>x)const{return(*this)(x.first)^__builtin_bswap64((*this)(x.second));}size_t operator()(tuple<uint64_t,uint64_t,uint64_t>x)const{return(*this)(get<0>(x))+__builtin_bswap64((*this)(make_pair(get<1>(x),get<2>(x))));}size_t operator()(tuple<uint64_t,uint64_t,uint64_t,uint64_t>x)const{return(*this)(get<0>(x))+__builtin_bswap64((*this)(make_tuple(get<1>(x),get<2>(x),get<3>(x))));}};
#if __has_include(<bits/extc++.h>)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;using namespace __gnu_cxx;
template<class K,class V>using hash_map=gp_hash_table<K,V,custom_hash>;template<class K>using hash_set=gp_hash_table<K,null_type,custom_hash>;template<class K,class V>using os_map=tree<K,V,less<K>,rb_tree_tag,tree_order_statistics_node_update>;template <class K>using os_set=os_map<K,null_type>;
#endif
#define FF first
#define SS second
#define PB push_back
#define PF push_front
#define EB emplace_back
#define EF emplace_front
#define PPB pop_back
#define PPF pp_front
#pragma endregion Template
// cm or bust

const ll MOD = 1e9 + 7;

long long fast_pow(long long a, long long b) { 
    long long res = 1; 
    for (a %= MOD; b; b >>= 1) { 
        if (b & 1) 
            res = res * a % MOD; 
        a = a * a % MOD; 
    } 
    return res; 
}

int N, M, rb, cb, rd, cd, P;

bool b;

pair<pll, pll> dfs(int r = rb, int c = cb, int dr = 1, int dc = 1) {
    //cout << N << ' ' << M << " : " << r << ' ' << c << ' ' << dr << ' ' << dc << '\n';
    if (r == rb && c == cb && dr == 1 && dc == 1) {
        if (b)
            return {{0, 1}, {1, 1}};
        else 
            b = 1;
    }

    bool change = 0;
    if (r == N && dr != -1)
        dr = -1, change = 1;
    else if (r == 1 && dr != 1)
        dr = 1, change = 1;
    if (c == M && dc != -1)
        dc = -1, change = 1;
    else if (c == 1 && dc != 1)
        dc = 1, change = 1;
    if (change)
        return dfs(r, c, dr, dc);
    auto [c0, c1] = dfs(r + dr, c + dc, dr, dc);
    c0.FF += c0.SS;
    if (r == rd || c == cd) {
        c0.FF = (c0.FF * (100 - P)) % MOD, c0.SS = (c0.SS * 100) % MOD;
        c1.FF = (c1.FF * (100 - P)) % MOD, c1.SS = (c1.SS * 100) % MOD;
    }
    return {c0, c1};
}

void solve() {
    cin >> N >> M >> rb >> cb >> rd >> cd >> P;
    b = 0; auto [c0, c1] = dfs();

    //cout << c0.FF << ' ' << c0.SS << " | " << c1.FF << ' ' << c1.SS << '\n';

    auto inv = [](pll p) -> ll {
        return p.FF % MOD * fast_pow(p.SS, MOD - 2) % MOD; 
    };

    c1 = {c1.SS - c1.FF, c1.SS};
    auto l0 = inv(c0), l1 = inv(c1);
    cout << inv({l0, l1}) << '\n';
}

int main() {
#ifndef _GLIBCXX_DEBUG
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif
    
    int TT; cin >> TT;
    while (TT--)
        solve();
}
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <string>
#include <time.h>
#include <vector>

#define INF 1E9
#define INF64 2E18

using namespace std;

template<class T1, class T2> void pr(const pair<T1,T2>& x);
template<class T, size_t SZ> void pr(const array<T,SZ>& x);
template<class T> void pr(const vector<T>& x);
template<class T, class C> void pr(const set<T,C>& x);
template<class T, class C> void pr(const multiset<T,C>& x);
template<class T1, class T2> void pr(const map<T1,T2>& x);
template<class T1, class T2> void pr(const map<T1,T2>& x);
template<class... T> void pr(const tuple<T...>& tup);

template<class T> void pr(const T& x) { cout << x; }
template<class Arg, class... Args> void pr(const Arg& first, const Args&... rest) {
  pr(first); pr(rest...);
}
template<class T1, class T2> void pr(const pair<T1,T2>& x) {
  pr("{",x.first,", ",x.second,"}");
}
template<class T> void prContain(const T& x) {
  pr("{");bool fst = 1; for(auto &a: x) pr(!fst?", ":"",a), fst = 0;pr("}");
}
template<class T, size_t SZ> void pr(const array<T,SZ>& x) { prContain(x); }
template<class T> void pr(const vector<T>& x) { prContain(x); }
template<class T, class C> void pr(const set<T,C>& x) { prContain(x); }
template<class T, class C> void pr(const multiset<T,C>& x) { prContain(x); }
template<class T1, class T2> void pr(const map<T1,T2>& x) { prContain(x); }

template<class T, size_t... I>
void pr(const T& tup, index_sequence<I...>) {
  pr("("); (..., (cout << (I == 0? "" : ", ") << get<I>(tup))); pr(")");
}
template<class... T>
void pr (const tuple<T...>& tup) {
  pr(tup, make_index_sequence<sizeof...(T)>());
}
void ps() { pr("\n"); }
template<class Arg, class... Args> void ps(const Arg& first, const Args&... rest) {
  pr(first," "); ps(rest...);
}

template<typename T> int remin(T& a,const T& b){if(b<a){a=b;return true;}return false;}
template<typename T> int remax(T& a,const T& b){if(b>a){a=b;return true;}return false;}

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


template<class T = int>
struct Fenwick_Tree {
  vector<T> bit;
  int _n;
  Fenwick_Tree(int n): _n(n) {
    bit.resize(n+1);
  }
  inline int low_bit(int idx) { return idx&(-idx); }
  T sum(int idx) {
    T total = 0;
    int k = idx + 1;
    while (k > 0) {
      total += bit[k];
      k -= low_bit(k);
    }
    return total;
  }
  void update(int idx, int v) {
    assert(idx >= 0 && idx < _n);
    int k = idx + 1;
    while (k < _n+1) {
      bit[k] += v;
      k += low_bit(k);
    }
  }
  T query(int l, int r) {
    assert(r < _n);
    assert(l <= r);
    return sum(r) - sum(l-1);
  }
};

void solve() {
  int n; scanf("%d", &n);
  vi va;
  vi a;
  for (int i = 0; i < n; ++i) {
    int k; scanf("%d", &k);
    a.push_back(k);
    va.push_back(k);
  }
  sort(va.begin(), va.end());
  va.erase(unique(va.begin(), va.end()), va.end());

  Fenwick_Tree ft(n+2);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int d = lower_bound(va.begin(), va.end(), a[i]) - va.begin();
    int r = ft.query(d+1, n+1), l = ft.sum(d-1);
    // ps(a[i], l, r);
    if (l <= r) {
      ans += l;
    } else {
      ans += r;
    }
    ft.update(d, 1);
  }
  printf("%d\n", ans);
}

int main(int argc, const char **argv) {
  int TT; scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
  return 0;
}

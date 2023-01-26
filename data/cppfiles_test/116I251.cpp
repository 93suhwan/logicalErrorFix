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

const int MOD = 998244353;

struct int_mod {
  // (a^(b%MOD))%MOD != (a^b)%MOD
  int value;
  int_mod() : value(0) {}
  int_mod(int _value) : value(_value) {}
  int_mod& operator+=(int_mod const& rhs) {
    value = (value + rhs.value) % MOD;
    return *this;
  }
  int_mod& operator-=(int_mod const& rhs) {
    value = (value - rhs.value + MOD) % MOD;
    return *this;
  }
  int_mod& operator*=(int_mod const& rhs) {
    value = ((1LL * value * rhs.value % MOD) + MOD)%MOD;
    return *this;
  }
  int_mod& fexp(ll e) {
    assert(e >= 0);
    if (e == 0) {
      value = 1;
      return *this;
    }
    if (e&1) {
      value = (1LL * value * this->fexp(e-1).value) % MOD;
      return *this;
    }
    value = (1LL * value * value) % MOD;
    return this->fexp(e/2);
  }

  int_mod& operator/=(const int_mod &rhs) {
    int a = rhs.value;
    a %= MOD;
    if (a < 0) a += MOD;
    int b = MOD, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += MOD;
    int_mod r = u;
    *this *= r;
    return *this;
  }
  // int_mod& operator/=(int_mod rhs) { // if MOD is prime
  //   *this *= rhs.fexp(MOD-2);
  //   return *this;
  // }

  friend int_mod operator*(int_mod a, int_mod const b) { return a *= b; }
  friend int_mod operator+(int_mod a, int_mod const b) { return a += b; }
  friend int_mod operator-(int_mod a, int_mod const b) { return a -= b; }
  friend int_mod operator/(int_mod a, int_mod const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, int_mod const& lhs) { return os << lhs.value; }
  friend int_mod fast_exp(int_mod lhs, const ll e) {
    assert(e >= 0);
    if (e == 0) return 1;
    if (e & 1) return lhs * fast_exp(lhs, e-1);
    return fast_exp(lhs * lhs, e/2);
  }
};
int_mod fast_exp(int a, const ll e) { return fast_exp((int_mod) a, e); }


void solve() {
  int n; scanf("%d", &n);
  vector<int_mod> dp(n+1);
  vi a(n);
  map<int, int> mp;
  int_mod ans = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    mp[a[i]]++;
  }
  for (int i = 0; i < n; ++i) {
    mp[a[i]]--;
    int k = a[i];
    if (k == 1) ans += 1;
    if (k == 0) {
      dp[k] += dp[k] + 1;
    } else {
      dp[k] += dp[k] + dp[k-1];
    }
    ans += dp[k] * mp[k + 2];
  }
  for (int i = 0; i <= n; ++i) {
    ans += dp[i];
  }
  printf("%d\n", ans.value);
}

int main(int argc, const char **argv) {
  int TT; scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
  return 0;
}

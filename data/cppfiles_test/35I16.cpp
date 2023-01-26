#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma,tune=native")
template <typename T>
void print(T&& x) {
  cout << x << "\n";
}
template <typename T, typename... S>
void print(T&& x, S&&... y) {
  cout << x << ' ';
  print(y...);
}
template <long long maxn>
struct NT {
  vector<long long> pr;
  long long lpd[maxn];
  NT() {
    pr.clear();
    for (long long i = (0); i < ((long long)(maxn)); i++) lpd[i] = -1;
    for (long long i = (2); i < ((long long)(maxn)); i++) {
      if (lpd[i] == -1) lpd[i] = i, pr.push_back(i);
      for (auto p : pr) {
        if (p * i >= maxn) break;
        lpd[p * i] = p;
        if (i % p == 0) break;
      }
    }
  }
  inline bool isp(long long x) { return lpd[x] == x; }
  signed fac_cnt(signed x) {
    assert(x >= 1 && x < maxn);
    signed res = 1, lst = 0, cur = 0;
    while (x > 1) {
      signed p = lpd[x];
      if (p != lst) res *= cur + 1, cur = 0;
      cur++;
      lst = p;
      x /= p;
    }
    return res * (cur + 1);
  }
};
const long long Mod = 1000000007, Mod2 = 998244353;
const long long MOD = Mod;
const long long maxn = 1000005;
long long n, a[maxn], curval[maxn], res;
string str;
NT<maxn> nt;
vector<pair<long long, long long> > vec[maxn];
vector<pair<long long, long long> > op[maxn];
void orzck() {
  cin >> n;
  for (long long i = (0); i < ((long long)(n)); i++) cin >> a[i];
  cin >> str;
  for (long long i = (0); i < ((long long)(n)); i++) {
    long long x = a[i];
    long long sign = 1;
    if (str[i] == '/') sign = -1;
    while (x > 1) {
      long long p = nt.lpd[x];
      826;
      if (((long long)vec[p].size()) && vec[p].back().second == i)
        vec[p].back().first += sign, 826;
      else
        vec[p].push_back({sign, i});
      x /= p;
    }
  }
  for (long long i = (0); i < ((long long)(maxn)); i++) curval[i] = -1;
  for (long long i = (0); i < ((long long)(maxn)); i++)
    if (((long long)vec[i].size())) {
      for (long long j = (1); j < ((long long)(((long long)vec[i].size())));
           j++)
        vec[i][j].first += vec[i][j - 1].first;
      vector<pair<long long, long long> > stk;
      for (long long j = (((long long)vec[i].size()) - 1);
           j >= ((long long)(0)); j--) {
        while (((long long)stk.size()) && vec[i][j].first <= stk.back().first)
          stk.pop_back();
        op[vec[i][j].second].push_back(
            {((long long)stk.size()) ? stk.back().second : n, i});
        stk.push_back(vec[i][j]);
        826;
      }
      while (((long long)stk.size()) && stk.back().first >= 0) stk.pop_back();
      curval[i] = ((long long)stk.size()) ? stk.back().second : n;
    }
  multiset<long long> st;
  for (long long i = (0); i < ((long long)(maxn)); i++)
    if (curval[i] != -1) st.insert(curval[i]);
  for (long long i = (0); i < ((long long)(n)); i++) {
    826;
    res += (*st.begin()) - i;
    for (auto [x, y] : op[i]) {
      st.erase(st.find(curval[y]));
      curval[y] = x;
      st.insert(x);
    }
  }
  print(res);
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(15);
  long long t;
  t = 1;
  while (t--) orzck();
  return 0;
}

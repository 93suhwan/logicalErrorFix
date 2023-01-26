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
template <int maxn>
struct NT {
  vector<int> pr;
  int lpd[maxn];
  NT() {
    pr.clear();
    for (int i = (0); i < ((int)(maxn)); i++) lpd[i] = -1;
    for (int i = (2); i < ((int)(maxn)); i++) {
      if (lpd[i] == -1) lpd[i] = i, pr.push_back(i);
      for (auto p : pr) {
        if (p * i >= maxn) break;
        lpd[p * i] = p;
        if (i % p == 0) break;
      }
    }
  }
  inline bool isp(int x) { return lpd[x] == x; }
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
const int Mod = 1000000007, Mod2 = 998244353;
const int MOD = Mod;
const int maxn = 1000005;
int n, a[maxn], curval[maxn];
long long res;
string str;
NT<maxn> nt;
vector<pair<int, int> > vec[maxn];
vector<pair<int, int> > op[maxn];
void orzck() {
  cin >> n;
  for (int i = (0); i < ((int)(n)); i++) cin >> a[i];
  cin >> str;
  for (int i = (0); i < ((int)(n)); i++) {
    int x = a[i];
    int sign = 1;
    if (str[i] == '/') sign = -1;
    while (x > 1) {
      int p = nt.lpd[x];
      826;
      if (((int)vec[p].size()) && vec[p].back().second == i)
        vec[p].back().first += sign, 826;
      else
        vec[p].push_back({sign, i});
      x /= p;
    }
  }
  for (int i = (0); i < ((int)(maxn)); i++) curval[i] = -1;
  for (int i = (0); i < ((int)(maxn)); i++)
    if (((int)vec[i].size())) {
      for (int j = (1); j < ((int)(((int)vec[i].size()))); j++)
        vec[i][j].first += vec[i][j - 1].first;
      vector<pair<int, int> > stk;
      for (int j = (((int)vec[i].size()) - 1); j >= ((int)(0)); j--) {
        while (((int)stk.size()) && vec[i][j].first <= stk.back().first)
          stk.pop_back();
        op[vec[i][j].second].push_back(
            {((int)stk.size()) ? stk.back().second : n, i});
        stk.push_back(vec[i][j]);
        826;
      }
      while (((int)stk.size()) && stk.back().first >= 0) stk.pop_back();
      curval[i] = ((int)stk.size()) ? stk.back().second : n;
    }
  multiset<int> st;
  for (int i = (0); i < ((int)(maxn)); i++)
    if (curval[i] != -1) st.insert(curval[i]);
  st.insert(n);
  for (int i = (0); i < ((int)(n)); i++) {
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
  int t;
  t = 1;
  while (t--) orzck();
  return 0;
}

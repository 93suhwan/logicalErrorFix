#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1000006;
const int MAXN = 150005;
int A[MAXN], par[MAXV], pfact[MAXV], p_comp[MAXV];
vector<int> primes;
set<int> ans[MAXV];
int parent(int pos) {
  if (par[pos] != pos) par[pos] = parent(par[pos]);
  return par[pos];
}
int dsu_merge(int u, int v) {
  u = parent(u);
  v = parent(v);
  if (u > v) swap(u, v);
  par[v] = u;
  return u;
}
vector<int> get_factors(int num) {
  vector<int> res;
  int cp = -1;
  while (num > 1) {
    if (pfact[num] != cp) res.push_back(pfact[num]);
    cp = pfact[num];
    num /= pfact[num];
  }
  return res;
}
void precomp() {
  for (int i = 2; i < MAXV; ++i) {
    if (pfact[i]) continue;
    primes.push_back(i);
    for (int j = i; j < MAXV; j += i) {
      pfact[j] = i;
    }
  }
}
int main(int argc, char const *argv[]) {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &A[i]);
    par[A[i]] = A[i];
  }
  precomp();
  for (int i = 0; i < primes.size(); ++i) {
    int p = primes[i], cc = 0;
    for (int j = p; j < MAXV; j += p) {
      if (!par[j]) continue;
      int nc = parent(j);
      if (cc == 0)
        cc = nc;
      else
        cc = dsu_merge(cc, nc);
    }
    p_comp[p] = cc;
  }
  for (int i = 1; i <= n; ++i) {
    int ai = A[i];
    int nxt = ai + 1;
    vector<int> factors = get_factors(nxt);
    for (int j = 0; j < factors.size(); ++j) {
      int f = factors[j];
      if (p_comp[f]) factors[j] = parent(p_comp[f]);
    }
    int cc = parent(ai);
    for (int j = 0; j < factors.size(); ++j) {
      ans[cc].insert(factors[j]);
      for (int k = j + 1; k < factors.size(); ++k) {
        ans[factors[j]].insert(factors[k]);
      }
    }
  }
  while (q--) {
    int u, v;
    scanf("%d %d", &u, &v);
    u = parent(A[u]);
    v = parent(A[v]);
    if (u == v)
      printf("0\n");
    else if ((ans[u].find(v) != ans[u].end()) ||
             (ans[v].find(u) != ans[v].end()))
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}

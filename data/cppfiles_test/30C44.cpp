#include <bits/stdc++.h>
using namespace std;
const int oo = 2e5 + 7, po = 1e6 + 7;
int n, q, a[oo], s, t;
int parent[oo], dsusize[oo], primeparent[po];
int getp(int a) {
  if (parent[a] == a) return a;
  return parent[a] = getp(parent[a]);
}
int getpp(int a) {
  if (primeparent[a] == -1) return -1;
  return primeparent[a] = getp(primeparent[a]);
}
void unite(int a, int b) {
  a = getp(a), b = getp(b);
  if (dsusize[b] > dsusize[a]) swap(a, b);
  parent[b] = a;
  dsusize[a] += dsusize[b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = 0; i < po; i++) primeparent[i] = -1;
  vector<vector<int>> divisors(po);
  for (int i = 2; i < po; i++)
    if (divisors[i].empty())
      for (int j = i; j < po; j += i) divisors[j].push_back(i);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i], parent[i] = i, dsusize[i] = 1;
  for (int i = 0; i < n; i++) {
    for (int e : divisors[a[i]]) {
      if (getpp(e) == -1)
        primeparent[e] = getp(i);
      else if (getpp(e) != getp(i))
        unite(getpp(e), getp(i));
    }
  }
  set<int> conns[n];
  for (int i = 0; i < n; i++) {
    int p = getp(i);
    set<int> belongings = {p};
    for (int e : divisors[a[i] + 1]) {
      int pp = getpp(e);
      if (pp != -1) belongings.insert(pp);
    }
    for (int e : belongings)
      for (int k : belongings)
        if (e != k) conns[e].insert(k), conns[k].insert(e);
  }
  for (int _q = 0; _q < q; _q++) {
    cin >> s >> t;
    s--, t--;
    int g1 = getp(s), g2 = getp(t);
    if (g1 == g2)
      cout << 0 << endl;
    else if (conns[g1].count(g2))
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}

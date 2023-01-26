#include <bits/stdc++.h>
using namespace std;
const int DIM = 5e5 + 7;
const int INF = 7e18 + 7;
const int mod = 998244353;
const int base = 29;
int n, t, k;
int a[DIM];
int b[DIM];
int pos[DIM];
set<int> s[DIM];
void del(int type, int var) { s[type].erase(var); }
void clr(int type, int var) {
  while (s[type].size() && (*s[type].begin()) <= var)
    s[type].erase(s[type].begin());
}
void add(int type, int var) { s[type].insert(var); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    set<int> all;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      all.insert(a[i]);
      b[i] = a[i];
      s[a[i]].insert(i);
    }
    if (all.size() != n) {
      cout << "YES\n";
      for (int i = 1; i <= n; i++) {
        s[b[i]].clear();
      }
      continue;
    }
    sort(b + 1, b + n + 1);
    int good = 1;
    int el1, el2, el3, k1, k2, k3;
    for (int i = 1; i <= n; i++) {
      if (b[i] == a[i]) {
        clr(a[i], i);
        continue;
      }
      if (i == n - 1) {
        good = 0;
        break;
      };
      el1 = a[i];
      k1 = i;
      el2 = b[i];
      k2 = (*s[el2].begin());
      el3 = a[i + 1];
      if (k2 == i + 1) el3 = a[i + 2];
      k3 = (*s[el3].rbegin());
      a[k1] = el2;
      a[k2] = el3;
      a[k3] = el1;
      del(el1, k1);
      del(el2, k2);
      del(el3, k3);
      add(el2, k1);
      add(el3, k2);
      add(el1, k3);
      clr(a[i], i);
    }
    for (int i = 1; i <= n; i++) {
      s[b[i]].clear();
    }
    if (good)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

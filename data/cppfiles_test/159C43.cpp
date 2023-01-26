#include <bits/stdc++.h>
using namespace std;
const int INF = (int)(1e9) + 5, MN = (int)(1e6) + 5;
int n, tab[MN];
unsigned long long h[MN], f[MN];
map<unsigned long long, int> dict;
void solve() {
  cin >> n;
  for (int i = 2; i <= n; i++) {
    if (!tab[i]) {
      for (int j = 2 * i; j <= n; j += i) {
        if (!tab[j]) {
          tab[j] = i;
        }
      }
    }
  }
  mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
  for (int i = 2; i <= n; i++) {
    if (!tab[i]) {
      h[i] = rnd();
    } else {
      h[i] = h[tab[i]] ^ h[i / tab[i]];
    }
  }
  unsigned long long sum_h = 0;
  dict[0] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = f[i - 1] ^ h[i];
    dict[f[i]] = i;
    sum_h ^= f[i];
  }
  if (sum_h == 0) {
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
      cout << i << " ";
    }
    return;
  }
  if (dict.find(sum_h) != dict.end()) {
    cout << n - 1 << "\n";
    int del = dict.find(sum_h)->second;
    for (int i = 1; i <= n; i++) {
      if (i != del) {
        cout << i << " ";
      }
    }
    return;
  }
  for (int i = 1; i <= n; i++) {
    if (dict.find(sum_h ^ f[i]) != dict.end() &&
        dict.find(sum_h ^ f[i])->second != i) {
      cout << n - 2 << "\n";
      int del = dict.find(sum_h ^ f[i])->second;
      for (int j = 1; j <= n; j++) {
        if (j != i && j != del) {
          cout << j << " ";
        }
      }
      return;
    }
  }
  cout << n - 3 << "\n";
  for (int i = 1; i <= n; i++) {
    if (i != 2 && i != n && i != (n - 1) / 2) {
      cout << i << " ";
    }
  }
}
void clear() { cout << "\n"; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int test = 1;
  while (test--) {
    solve();
    clear();
  }
  return 0;
}

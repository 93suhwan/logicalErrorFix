#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
const int maxn = 200000 + 10, modd = 16714589, inf = 2147483647,
          half_inf = 2147483647 / 2;
const long long inf_ll = 9223372036854775807, mul_ll = 1000000;
void solve() {
  int n, m, v, u;
  unordered_set<int> gr[maxn];
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> v >> u;
    v--;
    u--;
    gr[v].insert(u);
    gr[u].insert(v);
  }
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1; i2 < n; i2++) {
      if (gr[i1].count(i2) == 0) {
        continue;
      }
      for (int i3 = i2; i3 < n; i3++) {
        if (gr[i1].count(i3) == 0 || gr[i2].count(i3) == 0) {
          continue;
        }
        for (int i4 = i3; i4 < n; i4++) {
          if (gr[i1].count(i4) == 0 || gr[i2].count(i4) == 0 ||
              gr[i3].count(i4) == 0) {
            continue;
          }
          for (int i5 = i4; i5 < n; i5++) {
            if (gr[i1].count(i5) == 0 || gr[i2].count(i5) == 0 ||
                gr[i3].count(i5) == 0 || gr[i4].count(i5) == 0) {
              continue;
            }
            cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5
                 << "\n";
            return;
          }
        }
      }
    }
  }
  for (int i1 = 0; i1 < n; i1++) {
    for (int i2 = i1; i2 < n; i2++) {
      if (gr[i1].count(i2) != 0) {
        continue;
      }
      for (int i3 = i2; i3 < n; i3++) {
        if (gr[i1].count(i3) != 0 || gr[i2].count(i3) != 0) {
          continue;
        }
        for (int i4 = i3; i4 < n; i4++) {
          if (gr[i1].count(i4) != 0 || gr[i2].count(i4) != 0 ||
              gr[i3].count(i4) != 0) {
            continue;
          }
          for (int i5 = i4; i5 < n; i5++) {
            if (gr[i1].count(i5) != 0 || gr[i2].count(i5) != 0 ||
                gr[i3].count(i5) != 0 || gr[i4].count(i5) != 0) {
              continue;
            }
            cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5
                 << "\n";
            return;
          }
        }
      }
    }
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

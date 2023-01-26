#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p) cin >> i;
    vector<bool> pos_suffix(n, true), neg_suffix(n, true);
    for (int i = n - 2; i >= 0; --i) {
      pos_suffix[i] = p[i] < p[i + 1] && pos_suffix[i + 1];
      neg_suffix[i] =
          (-p[i] < -p[i + 1] && neg_suffix[i + 1]) || pos_suffix[i + 1];
    }
    bool inversion = false, exists = true;
    p[0] = -p[0];
    for (int i = 1; i < n; ++i) {
      if (!inversion && neg_suffix[i]) {
        inversion = true;
        p[i] = -p[i];
      } else if (p[i - 1] < -p[i]) {
        p[i] = -p[i];
      } else if (p[i - 1] > p[i]) {
        exists = false;
      }
    }
    if (!exists) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto &i : p) cout << i << " ";
      cout << "\n";
    }
  }
}

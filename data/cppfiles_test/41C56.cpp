#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > c;
void gen(int l, int r, int k, int x) {
  if (l >= r) return;
  vector<int> m(k - 1);
  vector<int> t(r + 1, -1);
  for (int i = 0; i < k - 1; i++) {
    m[i] = (l * (i + 1) + r * (k - i - 1)) / k;
  }
  sort(m.begin(), m.end());
  for (int i = l; i <= m[0]; i++) {
    t[i] = 0;
  }
  for (int j = 0; j < k - 2; j++) {
    for (int i = m[j] + 1; i <= m[j + 1]; i++) {
      t[i] = j + 1;
    }
  }
  for (int i = m[k - 2] + 1; i <= r; i++) {
    t[i] = k;
  }
  for (int i = l; i <= r; i++) {
    for (int j = i + 1; j <= r; j++) {
      if (t[l] == -1) continue;
      if (t[r] == -1) continue;
      if (t[l] == t[r]) continue;
      c[i][j] = x;
    }
  }
  gen(l, m[0], k, x + 1);
  gen(m[k - 2] + 1, r, k, x + 1);
  for (int j = 0; j < k - 2; j++) {
    gen(m[j] + 1, m[j + 1], k, x + 1);
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  c.resize(n, vector<int>(n, 0));
  gen(0, n - 1, k, 1);
  int maxi = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      maxi = max(maxi, c[i][j]);
    }
  }
  cout << maxi << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << c[i][j] << " ";
    }
  }
  cout << endl;
}

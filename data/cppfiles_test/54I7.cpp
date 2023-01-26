#include <bits/stdc++.h>
using namespace std;
vector<int> color;
void solve() {
  long long n, m;
  cin >> n >> m;
  color = vector<int>(n + 1, 2);
  bool ok = true;
  while (m--) {
    long long i, j;
    string c;
    cin >> i >> j >> c;
    if (color[i] != 2 && color[j] != 2) {
      if (c[0] == 'i' && color[i] == color[j] ||
          c[0] == 'c' && color[j] != color[i]) {
        ok = false;
      }
    }
    if (color[i] == 2 && color[j] == 2) {
      color[i] = 1;
    }
    if (color[i] != 2 && color[j] == 2) {
      if (c[0] == 'i')
        color[j] = 1 - color[i];
      else
        color[j] = color[i];
    }
    if (color[i] == 2 && color[j] != 2) {
      if (c[0] == 'i')
        color[i] = 1 - color[j];
      else
        color[i] = color[j];
    }
  }
  if (!ok) {
    cout << "-1\n";
    return;
  }
  long long cnt[] = {0, 0, 0};
  for (int i = 1; i <= n; i++) cnt[color[i]]++;
  cout << max(cnt[0], cnt[1]) + cnt[2] << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}

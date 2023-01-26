#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> D(n), I(n);
  long long int left = 0, right = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    D[i] = {a, b};
    int x = min(a, m);
    int y = min(b, m);
    int L = (a - x) - (b - (m - x));
    int R = (a - (m - y)) - (b - y);
    I[i] = {L, R};
    left += L;
    right += R;
  }
  long long int ans;
  vector<pair<int, int>> T(n);
  if (right < 0) {
    ans = -right;
    for (int i = 0; i < n; i++) {
      int t = min(m, D[i].second);
      T[i] = {m - t, t};
    }
  } else {
    if (0 < left) {
      ans = left;
      for (int i = 0; i < n; i++) {
        int t = min(m, D[i].first);
        T[i] = {t, m - t};
      }
    } else {
      ans = 0;
      for (int i = 0; i < n; i++) {
        if (right >= 0) {
          if (right - I[i].second + I[i].first >= 0) {
            right = right - I[i].second + I[i].first;
            int t = min(D[i].first, m);
            T[i] = {t, m - t};
          } else {
            int z = 0;
            while (right - I[i].second + I[i].first + 2 * z < 0) {
              z++;
            }
            right = right - I[i].second + I[i].first + 2 * z;
            int t = min(D[i].first, m);
            t -= z;
            T[i] = {t, m - t};
          }
        } else {
          throw;
        }
      }
      ans = right;
    }
  }
  cout << ans << endl;
  for (auto &u : T) {
    cout << u.first << " " << u.second << endl;
  }
  cout << endl;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  int test = 1;
  cin >> test;
  while (test) {
    solve();
    test--;
  }
  return 0;
}

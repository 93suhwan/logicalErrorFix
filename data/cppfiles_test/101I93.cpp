#include <bits/stdc++.h>
using namespace std;
const char nl = '\n';
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<int, char>> a(N);
    for (int i = 0; i < N; i++) cin >> a[i].first;
    for (int i = 0; i < N; i++) cin >> a[i].second;
    sort(a.begin(), a.end());
    vector<int> pos(N + 1, 0);
    iota(pos.begin(), pos.end(), 0);
    int cur = 1;
    bool ok1 = true, ok2 = true, ok = true;
    for (int i = 0; i < N; i++) {
      if (a[i].second == 'B') {
        if (a[i].first >= cur)
          cur++;
        else
          ok1 = false;
      } else if (a[i].second == 'R') {
        if (a[i].first <= cur)
          cur++;
        else
          ok1 = false;
      }
    }
    cur = 1;
    for (int i = N - 1; i >= 0; i--) {
      if (a[i].second == 'B') {
        if (a[i].first >= cur)
          cur++;
        else
          ok2 = false;
      } else if (a[i].second == 'R') {
        if (a[i].first <= cur)
          cur++;
        else
          ok2 = false;
      }
    }
    ok = ok1 | ok2;
    cout << (ok ? "YES" : "NO") << nl;
  }
}

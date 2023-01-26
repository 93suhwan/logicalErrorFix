#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> even, odd;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] % 2) {
      odd.push_back(i);
    } else {
      even.push_back(i);
    }
  }
  auto evn = [&](int st) {
    int64_t cnt = 0;
    for (int i = st, p = 0; i < n; i += 2, p++) {
      int dist = abs(even[p] - i);
      cnt += dist;
    }
    return cnt;
  };
  auto od = [&](int st) {
    int64_t cnt = 0;
    for (int i = st, p = 0; i < n; i += 2, p++) {
      int dist = abs(odd[p] - i);
      cnt += dist;
    }
    return cnt;
  };
  int osz = (int)odd.size(), esz = (int)even.size();
  if (n % 2 == 0) {
    if (osz != esz) {
      cout << -1 << '\n';
    } else {
      int64_t best = LLONG_MAX;
      best = min(best, evn(0) + od(1));
      best = min(best, evn(1) + od(0));
      cout << best / 2 << '\n';
    }
  } else {
    int up = (n + 1) / 2;
    if (osz == up && esz == n / 2) {
      cout << (od(0) + evn(1)) / 2 << '\n';
    } else if (osz == n / 2 && esz == up) {
      cout << (od(1) + evn(0)) / 2 << '\n';
    } else {
      cout << -1 << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

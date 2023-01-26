#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 200;
const int mod = 1e9 + 7;
const int inf = 1e9;
int n, c[3], ans, fen[2][maxn];
pair<pair<int, int>, int> a[maxn];
vector<int> vec;
void upd(int f, int x, int y) {
  for (x += 5; x < maxn; x += x & -x) {
    fen[f][x] += y;
  }
  return;
}
int get(int f, int x) {
  int y = 0;
  for (x += 5; x > 0; x -= x & -x) {
    y += fen[f][x];
  }
  return y;
}
void solve() {
  fill(fen[0], fen[0] + n + 100, 0);
  fill(fen[1], fen[1] + n + 100, 0);
  sort(a, a + n);
  int x0 = 0, x1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second == c[0]) x0++;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i].first.first != a[i - 1].first.first) {
      int l = -1, r = n, mid;
      while (r - l > 1) {
        mid = (l + r) >> 1;
        int p1 = get(1, mid), p2 = x1 - get(0, mid);
        if (p1 <= p2)
          l = mid;
        else
          r = mid;
      }
      ans = max(ans, min({x0, get(1, l), x1 - get(0, l)}));
      ans = max(ans, min({x0, get(1, r), x1 - get(0, r)}));
    }
    if (a[i].second == c[0]) {
      x0--;
    }
    if (a[i].second == c[1]) {
      upd(0, a[i].first.second, 1);
      x1++;
    }
    if (a[i].second == c[2]) {
      upd(1, a[i].first.second, 1);
    }
  }
  fill(fen[0], fen[0] + n + 100, 0);
  fill(fen[1], fen[1] + n + 100, 0);
  x0 = 0, x1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i].second == c[0]) x0++;
  }
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i].first.first != a[i - 1].first.first) {
      int l = -1, r = n, mid;
      while (r - l > 1) {
        mid = (l + r) >> 1;
        int p1 = get(1, mid), p2 = x1 - get(0, mid);
        if (p1 <= p2)
          l = mid;
        else
          r = mid;
      }
      ans = max(ans, min({x0, get(1, l), x1 - get(0, l)}));
      ans = max(ans, min({x0, get(1, r), x1 - get(0, r)}));
    }
    if (a[i].second == c[0]) {
      x0--;
    }
    if (a[i].second == c[1]) {
      upd(0, a[i].first.first, 1);
      x1++;
    }
    if (a[i].second == c[2]) {
      upd(1, a[i].first.first, 1);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    vec.push_back(a[i].first.first);
  }
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
  for (int i = 0; i < n; i++) {
    a[i].first.first =
        lower_bound((vec).begin(), (vec).end(), a[i].first.first) - vec.begin();
  }
  vec.clear();
  for (int i = 0; i < n; i++) {
    vec.push_back(a[i].first.second);
  }
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
  for (int i = 0; i < n; i++) {
    a[i].first.second =
        lower_bound((vec).begin(), (vec).end(), a[i].first.second) -
        vec.begin();
  }
  c[0] = 1;
  c[1] = 2;
  c[2] = 3;
  do {
    for (int t = 0; t < 2; t++) {
      for (int o = 0; o < 2; o++) {
        solve();
        for (int i = 0; i < n; i++) {
          a[i].first.first = n - 1 - a[i].first.first;
        }
      }
      for (int i = 0; i < n; i++) {
        swap(a[i].first.first, a[i].first.second);
      }
    }
  } while (next_permutation(c, c + 3));
  cout << ans * 3;
  return 0;
}

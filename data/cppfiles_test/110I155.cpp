#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
long long n, c[3], ans, fen[2][maxn];
pair<pair<long long, long long>, long long> a[maxn];
vector<long long> vec;
void upd(long long f, long long x, long long y) {
  for (x += 5; x < maxn; x += x & -x) {
    fen[f][x] += y;
  }
  return;
}
long long get(long long f, long long x) {
  long long y = 0;
  for (x += 5; x > 0; x -= x & -x) {
    y += fen[f][x];
  }
  return y;
}
void solve() {
  fill(fen[0], fen[0] + n + 100, 0);
  fill(fen[1], fen[1] + n + 100, 0);
  sort(a, a + n);
  long long x0 = 0, x1 = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i].second == c[0]) x0++;
  }
  for (long long i = 0; i < n; i++) {
    if (i || a[i].first.first != a[i - 1].first.first) {
      long long l = -1, r = n, mid;
      while (r - l > 1) {
        mid = (l + r) >> 1;
        long long p1 = get(1, mid), p2 = x1 - get(0, mid);
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
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    vec.push_back(a[i].first.first);
  }
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
  for (long long i = 0; i < n; i++) {
    a[i].first.first =
        lower_bound((vec).begin(), (vec).end(), a[i].first.first) - vec.begin();
  }
  vec.clear();
  for (long long i = 0; i < n; i++) {
    vec.push_back(a[i].first.second);
  }
  sort((vec).begin(), (vec).end());
  vec.resize(unique((vec).begin(), (vec).end()) - vec.begin());
  for (long long i = 0; i < n; i++) {
    a[i].first.second =
        lower_bound((vec).begin(), (vec).end(), a[i].first.second) -
        vec.begin();
  }
  c[0] = 1;
  c[1] = 2;
  c[2] = 3;
  do {
    for (long long t = 0; t < 2; t++) {
      for (long long o = 0; o < 2; o++) {
        solve();
        for (long long i = 0; i < n; i++) {
          a[i].first.first = n - 1 - a[i].first.first;
        }
      }
      for (long long i = 0; i < n; i++) {
        swap(a[i].first.first, a[i].first.second);
      }
    }
  } while (next_permutation(c, c + 3));
  cout << ans * 3;
  return 0;
}

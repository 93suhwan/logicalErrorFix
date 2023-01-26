#include <bits/stdc++.h>
using namespace std;
void solve(long long TEST_CASE) {
  long long n, k;
  cin >> n >> k;
  vector<bool> visited(2 * n);
  vector<pair<long long, long long> > a(n);
  long long x, y, p = 0;
  for (long long i = 0; i < k; i++) {
    cin >> x >> y;
    x--;
    y--;
    if (x > y) swap(x, y);
    a[p++] = pair<long long, long long>(x, y);
    visited[x] = visited[y] = true;
  }
  if (n != k) {
    vector<long long> unvisited(2 * (n - k));
    long long q = 0;
    for (long long i = 0; i < 2 * n; i++)
      if (!visited[i]) unvisited[q++] = i;
    for (long long i = 0; i < n - k; i++)
      a[p++] = pair<long long, long long>(unvisited[i], unvisited[i + n - k]);
  }
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i != j) {
        if ((a[i].first < a[j].first && a[j].first < a[i].second &&
             a[i].second < a[j].second) ||
            (a[j].first < a[i].first && a[i].first < a[j].second &&
             a[j].second < a[i].second))
          ans++;
      }
    }
  }
  ans = ans / 2;
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long test_cases;
  cin >> test_cases;
  for (long long i = 1; i <= test_cases; i++) solve(i);
}

#include <bits/stdc++.h>
const long long mod = 1000000007;
const long long AM = 2e5 + 5;
using namespace std;
bool intersect(pair<long long, long long> p1, pair<long long, long long> p2) {
  if (p1.first > p2.first) swap(p1, p2);
  if (p2.second > p1.second && p2.first < p1.second) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    map<long long, long long> m;
    vector<pair<long long, long long>> used;
    for (__typeof(0) i = 0; i < k; ++i) {
      long long x, y;
      cin >> x >> y;
      if (x > y) swap(x, y);
      used.push_back(make_pair(x, y));
      m[x]++, m[y]++;
    }
    vector<long long> v;
    for (__typeof(1) i = 1; i < 2 * n + 1; ++i) {
      if (!m[i]) v.push_back(i);
    }
    for (__typeof(0) i = 0; i < n - k; ++i) {
      used.push_back(make_pair(v[i], v[i + n - k]));
    }
    long long ans = 0;
    for (__typeof(0) i = 0; i < n; ++i) {
      for (__typeof(i + 1) j = i + 1; j < n; ++j) {
        if (intersect(used[i], used[j])) ans++;
      }
    }
    cout << ans << '\n';
  }
}

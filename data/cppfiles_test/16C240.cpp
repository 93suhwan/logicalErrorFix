#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
void go() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solution() {
  long long n;
  cin >> n;
  vector<long long> b;
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    for (long long j = 0; j < x; ++j) {
      b.push_back(i + 1);
    }
  }
  sort(b.begin(), b.end());
  long long n1 = b.size();
  long long x = ceil((n1 * 1.0) / 2);
  vector<pair<long long, long long>> ans;
  for (long long i = 0, j = x; j < n1; ++j, ++i) {
    if (b[i] != b[j]) {
      ans.push_back({b[i], b[j]});
    }
  }
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i.first << " " << i.second << "\n";
  }
}
signed main() {
  go();
  long long t;
  cin >> t;
  while (t--) {
    solution();
  }
  return 0;
}

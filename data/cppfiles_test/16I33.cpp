#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxu = 200005;
void google(long long t) { cout << "Case #" << t << ": "; }
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long fun(long long a, long long b) {
  if (b == 0)
    return 1;
  else if (a == 1)
    return 1;
  long long temp = fun(a, b / 2) % 1000000007;
  temp = (temp * temp) % 1000000007;
  if (b % 2 == 1) temp = (temp * a) % 1000000007;
  return temp % 1000000007;
}
long long inv(long long a, long long b) {
  return (a * fun(b, 1000000007 - 2)) % 1000000007;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long i, j, k = 0, n, m, l = 0;
  long long t = 1;
  long long T = 1;
  cin >> T;
  for (t = 1; t <= T; t++) {
    cin >> n;
    long long a[n];
    multiset<pair<long long, long long>> s;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i]) s.insert({a[i], i});
    }
    vector<pair<long long, pair<long long, long long>>> v;
    long long ans = 0;
    while (s.size() > 1) {
      auto it = s.end();
      pair<long long, long long> p1, p2;
      it--;
      p1 = *(it);
      s.erase(it);
      auto it2 = s.end();
      it2--;
      p2 = *(it2);
      s.erase(it2);
      v.push_back({p2.first, {p1.second, p2.second}});
      ans += p2.first;
      if (p2.first != p1.first) {
        s.insert({p1.first - p2.first, p1.second});
      }
    }
    cout << ans << "\n";
    for (auto u : v) {
      for (i = 0; i < u.first; i++) {
        cout << u.second.first + 1 << " " << u.second.second + 1 << "\n";
      }
    }
  }
  return 0;
}

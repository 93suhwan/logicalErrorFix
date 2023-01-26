#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c, m;
    vector<long long> v(3);
    cin >> v[0] >> v[1] >> v[2] >> m;
    sort(v.begin(), v.end());
    a = v[2], b = v[1], c = v[0];
    long long mx = a + b + c - 3;
    long long mn = max(0ll, a - b - c - 1);
    if (m >= mn && m <= mx)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}

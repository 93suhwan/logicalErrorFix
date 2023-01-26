#include <bits/stdc++.h>
using namespace std;
long long int mod_add(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long int mod_mul(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long int mod_sub(long long int a, long long int b, long long int m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i, j, k, l, m, n, p, t;
  cin >> t;
  while (t--) {
    vector<long long int> v(3);
    cin >> v[0] >> v[1] >> v[2] >> m;
    sort(v.begin(), v.end());
    long long int max_adjacent = v[0] - 1 + v[1] - 1 + v[2] - 1;
    long long int min_adjacent = v[2] - v[1] - v[0] - 1;
    if (m >= min_adjacent && m <= max_adjacent)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}

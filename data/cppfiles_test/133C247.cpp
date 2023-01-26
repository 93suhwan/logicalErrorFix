#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long powr(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  if (x == 0) return 0;
  while (y) {
    if (y % 2 == 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<char, char>> v;
    for (long long i = 0; i < n - 2; i++) {
      char a, b;
      cin >> a >> b;
      v.push_back({a, b});
    }
    string s;
    s.push_back(v[0].first);
    s.push_back(v[0].second);
    for (long long i = 1; i < n - 2; i++) {
      if (v[i - 1].second != v[i].first) {
        s.push_back(v[i].first);
        s.push_back(v[i].second);
      } else
        s.push_back(v[i].second);
    }
    if (s.size() == n - 1) s.push_back('a');
    cout << s << endl;
  }
  return 0;
}

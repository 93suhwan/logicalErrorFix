#include <bits/stdc++.h>
using namespace std;
vector<int> factors(int n) {
  vector<int> f;
  for (int x = 2; x * x <= n; x++) {
    while (n % x == 0) {
      f.push_back(x);
      n /= x;
    }
  }
  if (n > 1) f.push_back(n);
  return f;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = res % 1000000007 * x % 1000000007;
    y = y >> 1;
    x = x % 1000000007 * x % 1000000007;
  }
  return res;
}
bool palindrome(const string &s) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }
  return true;
}
void answer() {
  long long int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  string s;
  cin >> s;
  vector<pair<long long int, long long int>> vp;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R')
      vp.push_back({v[i], 1e9});
    else
      vp.push_back({-1e9, v[i]});
  }
  sort(vp.begin(), vp.end());
  bool ok = true;
  for (int i = 0; i < n; i++) {
    if (vp[i].first > i + 1 || vp[i].second < i + 1) {
      ok = false;
      break;
    }
  }
  if (ok)
    cout << "YES"
         << "\n";
  else
    cout << "NO"
         << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) answer();
}

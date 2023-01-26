#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long m) {
  long long res = 1;
  a = a % m;
  if (a == 0) {
    return 0;
  }
  while (b > 0) {
    if (1 & b) {
      res = (res * a) % m;
    }
    b = b >> 1;
    a = (a * a) % m;
  }
  return res;
}
bool cmp(long long a, long long b) {
  if (a > b) {
    return true;
  }
  return false;
}
bool cmpi(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first > b.first) {
    return true;
  } else if (a.first == b.first) {
    if (a.second >= b.second) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}
long long gcd(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void solve() {
  string s;
  cin >> s;
  long long n = s.size(), i;
  if (n % 2 == 1) {
    cout << "NO";
    return;
  }
  long long m = n / 2;
  for (i = 0; i < m; i++) {
    if (s[i] != s[i + m]) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
}

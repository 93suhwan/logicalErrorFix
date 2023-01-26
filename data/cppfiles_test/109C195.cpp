#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
using namespace std::chrono;
void google(long long int t) { cout << "Case #" << t << ": "; }
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
string strrev(string s) {
  reverse(s.begin(), s.end());
  return s;
}
const long long int m = 1e7;
vector<long long int> sieve() {
  vector<bool> a(m + 1, true);
  vector<long long int> v;
  a[0] = false;
  a[1] = false;
  for (long long int p = 2; p * p <= m; p++) {
    if (a[p])
      for (long long int i = p * p; i <= m; i += p) {
        if (a[i]) a[i] = false;
      }
  }
  for (long long int i = 2; i <= m; i++) {
    if (a[i]) v.push_back(i);
  }
  return v;
}
long long int fp(long long int a, long long int b) {
  long long int res = 1;
  while (b) {
    if (b & 1) {
      res = res * a;
      b--;
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
int32_t main() {
  auto start1 = high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  long long int tc = t;
  while (t--) {
    long long int n;
    cin >> n;
    string s;
    cin >> s;
    long long int count = 0;
    for (long long int i = 0; i < n; i++) {
      if (i == n - 1 || s[i] == '0')
        count += (s[i] - '0');
      else
        count += 1 + (s[i] - '0');
    }
    cout << count << "\n";
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  long long int tm = (double)duration.count() / 1000;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long f(char c) {
  if (c == 'L')
    return -1;
  else
    return 1;
}
char g(long long x) {
  if (x == 1) return 'R';
  return 'L';
}
long long inv(long long x) { return -1 * x; }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cerr.tie(nullptr);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (auto& i : a) cin >> i;
  string s;
  cin >> s;
  long long x = 0;
  for (long long i = 1; i < n; ++i)
    if (s[i] != s[i - 1]) ++x;
  long long ind = n - x - 1;
  long long l = ind, r = ind;
  sort(a.begin(), a.end());
  vector<long long> t(n, 0);
  cout << a[ind] << ' ' << s[0] << '\n';
  t[ind] = f(s[0]);
  for (long long i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      long long k = inv(t[r]);
      ++r;
      cout << a[r] << ' ' << g(k) << '\n';
      t[r] = k;
    } else {
      long long k = inv(t[l]);
      --l;
      cout << a[l] << ' ' << g(k) << '\n';
      t[l] = k;
    }
  }
}

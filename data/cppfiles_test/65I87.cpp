#include <bits/stdc++.h>
using namespace std;
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
  cout << a[ind] << ' ' << s[0] << '\n';
  for (long long i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      ++r;
      cout << a[r] << ' ' << s[i] << '\n';
    } else {
      --l;
      cout << a[l] << ' ' << s[i] << '\n';
    }
  }
}

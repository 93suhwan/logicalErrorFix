#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for (auto &x : a) cin >> x;
  ;
  for (auto &x : a) --x;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    if (i - a[i] >= 0) v.push_back(a[i] - i);
  }
  vector<long long> z;
  for (auto x : v) {
    if (z.empty() || x >= z.back()) {
      z.push_back(x);
      continue;
    }
    auto it = lower_bound((z).begin(), (z).end(), x);
    if (*it > x) {
      *it = x;
    }
  }
  cout << z.size();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void print(bool n) {
  if (n)
    cout << "YES";
  else
    cout << "NO";
  cout << '\n';
}
long long lis(vector<long long> const &a) {
  long long n = a.size();
  const long long INF = 1e9;
  vector<long long> d(n + 1, INF);
  d[0] = -INF;
  for (long long i = 0; i < n; i++) {
    long long j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
    if (d[j - 1] < a[i] && a[i] < d[j]) d[j] = a[i];
  }
  long long ans = 0;
  for (long long i = 0; i <= n; i++) {
    if (d[i] < INF) ans = i;
  }
  return ans;
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
    if (i - a[i] >= 0) v.push_back(i - a[i]);
  }
  cout << lis(v);
  return 0;
}

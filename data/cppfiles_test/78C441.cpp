#include <bits/stdc++.h>
using namespace std;
void PV(vector<long long> v) {
  for (long long i = 0; i < (long long)v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PVV(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < (long long)v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << ' ';
  cout << "\n";
}
void IN(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
inline void op() {}
const long long M = 1e9 + 7;
const long long IM = 1e18 + 37;
const long long N = 2e5 + 10;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  op();
  long long t;
  cin >> t;
  while (t--) {
    long long l, r;
    cin >> l >> r;
    if (l == r) {
      cout << (0) << "\n";
      continue;
    }
    long long a = (r + 1) / 2;
    long long ans = (a + a - 1) % a;
    if (a < l) {
      ans = (r % l);
    }
    cout << (ans) << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long n;
vector<long long> a;
void add(long long& x, long long y) { x = (x + y) % mod; }
long long f() {
  cin >> n;
  a.resize(n);
  for (auto& x : a) cin >> x;
  long long res = 0;
  map<long long, long long> M;
  for (long long i = n - 1; i >= 0; --i) {
    map<long long, long long> N;
    long long cur = a[i];
    for (auto it : M) {
      long long lim = it.first;
      long long num = it.second;
      long long k = (cur + lim - 1) / lim;
      add(N[cur / k], (num / (i + 1)) * i);
      add(res, (k - 1) * num);
    }
    add(N[cur], i);
    M.swap(N);
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << f() << "\n";
  return 0;
}

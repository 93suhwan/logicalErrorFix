#include <bits/stdc++.h>
using namespace std;
long long absk(long long k) {
  if (k < 0) {
    return -k;
  }
  return k;
}
void solve() {
  long long n;
  cin >> n;
  set<long long> a;
  for (long long i = 1; i * i <= n; i++) a.insert(i * i);
  for (long long i = 1; i * i * i <= n; i++) a.insert(i * i * i);
  cout << a.size();
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long w;
  cin >> w;
  while (w--) {
    solve();
    cout << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long t, n;
vector<long long> a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    a.resize(n);
    for (auto& x : a) cin >> x;
    long long first = -1;
    for (long long i = 0; i < n; i++) first = max(first, a[i]);
    long long second = -1;
    for (long long i = 0; i < n; i++)
      if (a[i] != first) second = max(second, a[i]);
    if (second == -1) {
      cout << "0\n";
    } else {
      long long cnt = 0;
      for (long long i = n - 1; i >= 0; i--) {
        if (a[i] == second) {
          cnt += 2;
          break;
        }
        if (a[i] == first) {
          cnt += 1;
          break;
        }
      }
      cout << cnt << '\n';
    }
  }
}

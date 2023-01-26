#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int md = 1e9 + 7;
const int maxn = 2e5 + 5;
const int maxm = 1e9;
int n, m;
int a[maxn];
bool isnp[maxn];
vector<int> primes;
void init(int n) {
  for (int i = 2; i <= n; i++) {
    if (!isnp[i]) primes.push_back(i);
    for (int p : primes) {
      if (p * i > n) break;
      isnp[p * i] = 1;
      if (i % p == 0) break;
    }
  }
}
inline void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (isnp[sum]) {
    cout << n << endl;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << endl;
  } else {
    cout << n - 1 << endl;
    for (int i = 1; i <= n; i++) {
      if (isnp[sum - a[i]]) {
        for (int j = 1; j <= n; j++) {
          if (i != j) cout << j << " ";
        }
        cout << endl;
        return;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int __ = 1;
  cin >> __;
  init(2e5);
  while (__--) {
    solve();
  }
  return 0;
}

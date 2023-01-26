#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
vector<bool> p(200000 + 1, true);
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < (n); i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (p[sum]) {
    for (int i = 0; i < (n); i++) {
      if (!p[sum - a[i]]) {
        cout << n - 1 << "\n";
        for (int j = 1; j < (n + 1); j++)
          if (j != i + 1) cout << j << " ";
        cout << "\n";
        return;
      }
    }
  } else {
    cout << n << "\n";
    for (int i = 1; i < (n + 1); i++) cout << i << " ";
    cout << "\n";
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  cin >> t;
  p[0] = p[1] = false;
  for (long long i = 2; i <= 200000; i++) {
    for (long long j = i * i; j <= 200000; j += i) p[j] = false;
  }
  while (t--) {
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
void run_case() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int t = gcd(n, d);
  int ans = 0;
  for (int i = 0; i < t; i++) {
    vector<int> b;
    for (int j = 0; j < n / t; j++) {
      b.push_back(a[(i + j * 1LL * d) % n]);
    }
    if (count(b.begin(), b.end(), 0) == 0) {
      cout << "-1\n";
      return;
    }
    for (int i = 0, j = 0; i < n / t; i++) {
      while (j < i || b[j % (n / t)] != 0) {
        j++;
      }
      ans = max(ans, j - i);
    }
  }
  cout << ans << '\n';
}
auto clk = clock();
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    run_case();
  }
  return 0;
}

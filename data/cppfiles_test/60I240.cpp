#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long mod = 1e9 + 7;
const long long base = 31;
void fre() {}
clock_t start = clock();
double timecomplexity;
long double n, a[1000005];
unordered_map<long double, long double> m;
void solve() {
  cin >> n;
  m.clear();
  long double sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long double dis = 2 * (sum / n), ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += m[dis - a[i]];
    m[a[i]]++;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
}

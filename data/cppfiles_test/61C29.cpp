#include <bits/stdc++.h>
const long long INF = (long long)0x3f3f3f3f3f3f3f, MAX = 9e18, MIN = -9e18;
const double PI = acos(-1.0);
const double eps = 1e-6;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
const int maxm = 100 + 10;
using namespace std;
long long n, m, k;
long long a[maxn];
long long b[maxn];
void run_case() {
  cin >> n;
  map<int, long long> m1, m2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    m1[a[i]]++;
    m2[b[i]]++;
  }
  long long ans = n * (n - 1) * (n - 2) / 6;
  for (int i = 1; i <= n; i++) {
    ans -= (m1[a[i]] - 1) * (m2[b[i]] - 1);
  }
  cout << ans << "\n";
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  int _ = 1;
  cin >> _;
  while (_--) {
    run_case();
  }
}

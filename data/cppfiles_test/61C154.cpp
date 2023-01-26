#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
const int N = 2e5 + 5;
const long long int mod = 1e9 + 7;
const long long int Mod = 998244353;
const long double Pi = acos(-1);
const long long int Inf = 4e18;
const long double Eps = 1e-9;
int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};
using namespace std;
void TestCase() {
  long long int n, ans = 0;
  cin >> n;
  vector<long long int> a(n), b(n), g[n + 1], f(n + 1, 0);
  for (long long int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    g[a[i]].push_back(b[i]);
    f[b[i]]++;
  }
  for (long long int i = 1; i <= n; i++) {
    long long int sum = 0;
    for (auto x : g[i]) sum += (f[x] - 1);
    for (auto x : g[i]) {
      ans += (sum - (f[x] - 1));
    }
  }
  long long int tot = (n * (n - 1) * (n - 2)) / 6;
  cout << tot - ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    TestCase();
    cout << "\n";
  }
  return 0;
}

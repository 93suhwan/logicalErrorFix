#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const long long INF = 1e18;
long long biex(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = biex(a, b / 2);
  ans = ans * ans;
  if (b & 1)
    return ans * a;
  else
    return ans;
}
const int N = 1e5;
long long fact[N] = {0};
vector<int> divs(int n) {
  vector<int> v;
  v.push_back(1);
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      v.push_back(n / i);
    }
  }
  if ((int)v.size() > 1 && v[(int)v.size() - 1] == v[(int)v.size() - 2]) {
    v[(int)v.size() - 1] = n;
  } else {
    v.push_back(n);
  }
  sort(v.begin(), v.end());
  return v;
}
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    int z = i;
    while (z > 0 && a[i] % (z + 1) == 0) z--;
    if (z == 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= 100; i++) {
    long long x = (long long)i * fact[i - 1];
    if (x > 1e9) break;
    fact[i] = x;
  }
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}

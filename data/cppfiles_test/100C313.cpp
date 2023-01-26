#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const long long MOD = 998244353;
long long power(long long a, long long b, long long mod) {
  if (b == 0) {
    return 1;
  }
  long long ans = power(a, b / 2, mod);
  ans *= ans;
  ans %= mod;
  if (b % 2) {
    ans *= a;
  }
  return ans % mod;
}
void batman() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n == 1) {
    cout << a[n - 1] << endl;
    return;
  }
  sort(a, a + n);
  vector<int> v;
  v.push_back(a[0]);
  for (int i = 0; i < n - 1; i++) {
    v.push_back((a[i + 1] - a[i]));
  }
  sort(v.begin(), v.end());
  int x = v.size();
  cout << v[x - 1] << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  cin >> ttt;
  while (ttt--) {
    batman();
  }
}

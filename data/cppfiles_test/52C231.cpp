#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
bool isprime(int n) {
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}
vector<long long> block(int x) {
  vector<int> v;
  while (x > 0) {
    v.push_back(x % 2);
    x = x / 2;
  }
  vector<long long> ans;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 1) {
      ans.push_back(i);
    }
  }
  return ans;
}
void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> v1 = block(k);
  unsigned long long ans = 0;
  for (long long i = 0; i < v1.size(); i++) {
    unsigned long long t1 = 1;
    for (int j = 1; j <= v1[i]; j++) {
      t1 = t1 * n;
      t1 = t1 % mod;
    }
    ans += t1;
    ans = ans % mod;
  }
  cout << ans % mod << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _t;
  _t = 1;
  cin >> _t;
  while (_t--) solve();
}

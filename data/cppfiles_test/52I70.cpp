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
vector<int> block(int x) {
  vector<int> v;
  while (x > 0) {
    v.push_back(x % 2);
    x = x / 2;
  }
  vector<int> ans;
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
  vector<int> v1 = block(k);
  unsigned long long ans = 0;
  for (int i = 0; i < v1.size(); i++) {
    unsigned long long t1 = 1;
    for (int j = 1; j <= v1[i]; j++) {
      t1 = t1 * n;
    }
    ans += t1;
    ans = ans;
  }
  cout << ans % mod << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

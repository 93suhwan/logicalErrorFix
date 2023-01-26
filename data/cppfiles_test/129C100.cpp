#include <bits/stdc++.h>
using namespace std;
long long int row[4] = {1, 0, 0, -1};
long long int col[4] = {0, -1, 1, 0};
long long int mod = 1e9 + 7;
bool is_prime(long long int n) {
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long int BigMod(long long int a, long long int b, long long int m) {
  a %= m;
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long int pankha(long long int n, long long int x) {
  if (n % x == 0)
    return (n / x);
  else
    return ((n / x) + 1);
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> v, crr;
  map<long long int, long long int> mp;
  for (long long int i = 1; i <= n; i++) {
    long long int x;
    cin >> x;
    if (x <= n && !mp[x]) {
      v.push_back(x);
      mp[x]++;
    } else {
      crr.push_back(x);
    }
  }
  sort(crr.begin(), crr.end());
  bool flag = true;
  long long int cnt = 0;
  for (int i = n; i >= 1; i--) {
    if (!mp[i]) {
      long long int temp = crr.back();
      crr.pop_back();
      if (temp % (temp - i) != i) {
        flag = false;
        break;
      } else
        cnt++;
    }
  }
  if (flag)
    cout << cnt << "\n";
  else
    cout << -1 << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}

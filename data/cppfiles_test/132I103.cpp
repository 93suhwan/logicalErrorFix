#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int inf = 1e9;
const long long int maxn = 1e6 + 1;
long long int POW(long long int a, long long int b) {
  long long int ret = 1;
  for (; b; b >>= 1, a = a * a) {
    if (b & 1) {
      ret *= a;
    }
  }
  return ret;
}
long long int POWM(long long int a, long long int b, long long int MMM = mod) {
  long long int ret = 1;
  a = a % MMM;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
long long int run_test() {
  vector<long long int> a(7);
  for (long long int i = 0; i < 7; i++) {
    cin >> a[i];
  }
  for (long long int i = 0; i < 3; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
  return 0;
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tt;
  tt = 1;
  cin >> tt;
  for (long long int test = 1; test <= tt; test++) {
    run_test();
  }
  return 0;
}

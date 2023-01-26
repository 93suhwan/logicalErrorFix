#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long m) {
  long long r = 1;
  for (; y; y >>= 1) {
    if (y & 1) r = r * x % m;
    x = x * x % m;
  }
  return r;
}
const long long mod = 1e9 + 7;
const long double pi = 3.14159265358979;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
clock_t start = clock();
int run_test() {
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    sum += k;
  }
  if (sum % n) {
    cout << 1;
  } else {
    cout << 0;
  }
  cout << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long tt;
  tt = 1;
  cin >> tt;
  while (tt--) {
    run_test();
  }
}

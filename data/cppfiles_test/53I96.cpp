#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const long long SZ = 1e5 + 7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
const long long MOD = 998244353;
const long double PI = 3.1415926535897932384;
long long tc_cnt = 1;
auto clk = clock();
mt19937_64 rang(high_resolution_clock::now().time_since_epoch().count());
void run_time() {
  cerr << endl;
  cerr << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << endl;
  return;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
void solve() {
  long long int n;
  cin >> n;
  char c;
  cin >> c;
  string s;
  cin >> s;
  long long int odd = 0, even = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != c) {
      if ((i + 1) % 2 == 0) {
        even++;
      } else {
        odd++;
      }
    }
  }
  if (even == 0 && odd == 0) {
    cout << 0 << "\n";
    return;
  }
  if (s[n - 1] == c) {
    cout << 1 << "\n";
    cout << n << "\n";
  } else {
    if (n % 2 == 0) {
      if (odd == 0 || s[n - 1] == c) {
        cout << 1 << "\n";
        cout << n - 1 << "\n";
      } else {
        cout << 2 << "\n";
        cout << n - 1 << " " << n << "\n";
      }
    } else {
      if (even == 0 || s[n - 2] == c) {
        cout << 1 << "\n";
        cout << n - 1 << "\n";
      } else {
        cout << 2 << "\n";
        cout << n - 1 << " " << n << "\n";
      }
    }
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr << endl;
  long long ___tc;
  cin >> ___tc;
  while (___tc-- > 0) {
    solve();
  }
  run_time();
  return 0;
}

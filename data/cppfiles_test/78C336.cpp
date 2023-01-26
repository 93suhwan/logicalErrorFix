#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const long long INF = (long long)1e5 + 6;
void run() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
void solve() {
  int a, b;
  cin >> a >> b;
  if (a == b)
    cout << 0 << endl;
  else {
    if (a > b) {
      if (a / 2 >= b)
        cout << a % ((a / 2) + 1) << endl;
      else
        cout << a % b << endl;
    } else {
      if (b / 2 >= a)
        cout << b % ((b / 2) + 1) << endl;
      else
        cout << b % a << endl;
    }
  }
}
int main() {
  run();
  int n;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}

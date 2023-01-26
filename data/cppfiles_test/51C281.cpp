#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
int e1, e2;
int N, M;
int gcd(int a, int b);
int lcm(int a, int b);
int CEIL(int a, int b);
int power_mod(int a, int b, int mod);
void solve(int input) {
  long long int n;
  cin >> n;
  cout << -(n - 1) << " " << n << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int x = 1;
  cin >> x;
  for (int i = 1; i <= x; i++) {
    solve(i);
  }
  return 0;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int CEIL(int a, int b) { return (a + b - 1) / b; }
int power_mod(int x, int y, int mod) {
  int res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}

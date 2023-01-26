#include <bits/stdc++.h>
using namespace std;
void solve(int);
void queries() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) solve(i);
}
long long ceildiv(long long a, long long b) { return a / b + !!(a % b); }
template <class T>
T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}
const int maxn = 200200;
const double pi = 3.14159265359;
const long long mod = 1000000007;
const long long hash_p = 101;
const long long hash_inv = 940594066;
const int ddx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int ddy[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
void solve(int id) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < ceildiv(n, 2); i++) {
    if (s[i] == '0') {
      cout << (i + 2) << " ";
      cout << (n) << " ";
      cout << (i + 1) << " ";
      cout << (n) << "\n";
      return;
    }
  }
  if (s[1 + n / 2] == 1) {
    cout << (1) << " ";
    cout << (n / 2) << " ";
    cout << (2) << " ";
    cout << (1 + n / 2) << "\n";
  } else {
    cout << (1) << " ";
    cout << (1 + n / 2) << " ";
    cout << (1) << " ";
    cout << (n / 2) << " ";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << (fixed);
  cout << (setprecision(10));
  queries();
  return 0;
}

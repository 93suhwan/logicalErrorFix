#include <bits/stdc++.h>
using namespace std;
long long mpow(long long a, long long b) {
  a %= 1000000007;
  if (!b) return 1;
  long long temp = mpow(a, b / 2);
  temp = (temp * temp) % 1000000007;
  if (b % 2) return (a * temp) % 1000000007;
  return temp;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long cl(long long a, long long b) {
  if (a % b) return 1 + a / b;
  return a / b;
}
string itoj(string s, int i, int j) {
  string tmp = "";
  for (int x = i; x <= j; x++) {
    tmp += s[x];
  }
  return tmp;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  for (int i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void solve() {
  long long n;
  cin >> n;
  cout << 2 << " " << n - 1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

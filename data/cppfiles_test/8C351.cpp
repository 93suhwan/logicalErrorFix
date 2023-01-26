#include <bits/stdc++.h>
using namespace std;
void fastscan(int &number) {
  bool negative = false;
  register int c;
  number = 0;
  c = getchar();
  if (c == '-') {
    negative = true;
    c = getchar();
  }
  for (; (c > 47 && c < 58); c = getchar()) number = number * 10 + c - 48;
  if (negative) number *= -1;
}
int lo2(double n) {
  int c = 0;
  while (n > 2) {
    n = n / 2;
    c++;
  }
  return c;
}
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
int ceil_div(long long x, long long y) {
  if (x % y) {
    return (x / y) + 1;
  } else {
    return (x / y);
  }
}
void solve() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << " " << n / 3 << endl;
  } else if (n % 3 == 1) {
    cout << n / 3 + 1 << " " << n / 3 << endl;
  } else {
    cout << n / 3 << " " << n / 3 + 1 << endl;
  }
  return;
}
int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

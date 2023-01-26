#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void solve() {
  long long n;
  cin >> n;
  n--;
  if (n % 2 == 0) {
    long long no = n / 2;
    long long a = no;
    long long b = no;
    while (gcd(a, b) != 1) {
      a--;
      b++;
    }
    cout << a << " " << b << " ";
  } else {
    cout << n / 2 << " ";
    n -= n / 2;
    cout << n << " ";
  }
  cout << "1\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
}

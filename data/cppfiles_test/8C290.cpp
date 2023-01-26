#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, long long>;
void solve() {
  long long n;
  cin >> n;
  long long a = 0;
  long long b = 0;
  if (n % 3 == 0) {
  } else {
    if (n % 3 == 1) {
      n--;
      a++;
    } else {
      n -= 2;
      b++;
    }
  }
  a += n / 3;
  b += n / 3;
  cout << a << " " << b << endl;
}
string binary_of_length_n(long long num, long long n) {
  string s;
  for (long long i = n - 1; i >= 0; --i) {
    if (num & (1 << i)) {
      s.push_back('1');
    } else {
      s.push_back('0');
    }
  }
  return s;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}

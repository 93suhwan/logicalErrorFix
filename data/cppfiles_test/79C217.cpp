#include <bits/stdc++.h>
using namespace std;
long long isprime(long long n) {
  for (long long i = 2; i < n; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long val = -1;
  for (long long i = 0; i < s.size(); i++) {
    if (!isprime((s[i] - '0')) || s[i] == '1') {
      val = s[i] - '0';
      break;
    }
  }
  if (val == -1) {
    long long flag = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        long long a = (s[i] - '0');
        a = a * 10 + (s[j] - '0');
        if (!isprime(a)) {
          cout << 2 << endl;
          cout << a << endl;
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (!flag) cout << s.size() << endl << s << endl;
  } else
    cout << 1 << endl << val << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

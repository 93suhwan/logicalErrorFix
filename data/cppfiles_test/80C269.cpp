#include <bits/stdc++.h>
using namespace std;
long long t, n;
string s;
void calc() {
  for (long long i = 0; i < (n + 1) / 2; ++i) {
    if (s[i] == '0') {
      cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
      return;
    }
  }
  for (long long i = (n + 1) / 2; i < n; ++i) {
    if (s[i] == '0') {
      cout << "1 " << i + 1 << " 1 " << i << "\n";
      return;
    }
  }
  cout << "1 " << n - 1 << " 2 " << n << "\n";
}
int32_t main() {
  cin >> t;
  while (t--) {
    cin >> n >> s;
    calc();
  }
}

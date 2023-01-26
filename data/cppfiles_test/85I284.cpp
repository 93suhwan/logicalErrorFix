#include <bits/stdc++.h>
using namespace std;
bool is_prime(long long n) {
  bool b = true;
  if (n == 1) b = false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      b = false;
      break;
    }
  }
  return b;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int a[2] = {};
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1')
        a[1]++;
      else
        a[0]++;
    }
    if (a[1] == a[0])
      cout << a[1] << endl;
    else
      cout << min(a[1], a[0]) << endl;
  }
}

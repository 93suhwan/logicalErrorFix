#include <bits/stdc++.h>
using namespace std;
string s;
long long n, d = 1, ans, x;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    long long t = x / 3;
    if (x % 3 == 0) {
      cout << t << ' ' << t << '\n';
      continue;
    }
    if (x % 3 == 1) {
      cout << t + 1 << ' ' << t << '\n';
    }
    if (x % 3 == 2) {
      cout << t << ' ' << t + 1 << '\n';
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long arr[N] = {0};
void ans(int a, int b, int c, int d) {
  cout << a << " " << b << " " << c << " " << d << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long a, b, c, d, n, m;
    cin >> n;
    string s;
    cin >> s;
    n = s.length();
    int i = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == '0') break;
    }
    if (i == n) {
      ans(1, n - 1, 2, n);
    } else {
      if (i < n / 2) {
        ans(i + 1, n, i + 2, n);
      } else {
        ans(1, i + 1, 1, i);
      }
    }
  }
}

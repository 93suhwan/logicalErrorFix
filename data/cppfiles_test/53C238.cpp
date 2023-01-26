#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const long double PI = acos(-1);
const int M = 1e9 + 7;
long long n, k, T, m, u, v;
int b[N];
char s[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  char c;
  while (T--) {
    for (int i = 1; i <= n; i++) b[i] = 0;
    cin >> n >> c;
    cin >> s + 1;
    bool flag = true;
    for (int i = 1; i <= n; i++) {
      if (s[i] == c)
        b[i] = 1;
      else
        flag = false;
    }
    if (flag) {
      cout << 0 << '\n';
      continue;
    }
    for (int i = 1; i <= n; i++) {
      if (b[i]) {
        int t = 1;
        for (int j = i + i; j <= n; j += i) {
          if (!b[j]) {
            t = 0;
            break;
          }
        }
        if (t) {
          cout << 1 << '\n' << i << '\n';
          flag = true;
          break;
        }
      }
    }
    if (!flag) {
      cout << 2 << '\n' << n << " " << n - 1 << '\n';
    }
  }
  return 0;
}

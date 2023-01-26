#include <bits/stdc++.h>
using namespace std;
const int max_n = 1e5 + 100;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long a, b;
    cin >> a >> b;
    long long t = 1 + b / 4 * 4;
    while (t <= b) {
      if (a & 1)
        a += t;
      else
        a -= t;
      t++;
    }
    cout << a << "\n";
  }
  return 0;
}

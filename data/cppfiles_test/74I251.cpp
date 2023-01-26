#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
struct ui {
  int fir, sec;
  bool operator<(const ui b) const { return this->fir < b.fir; }
};
const int maxn = 1005;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int idkvwo;
  cin >> idkvwo;
  while (idkvwo--) {
    int a, b;
    cin >> a >> b;
    int n = a + b;
    int del = abs(a - b);
    int mi = min(a, b);
    int ma = max(a, b);
    if (a == b) {
      cout << a << endl;
      for (int i = 0; i <= n; i += 2) {
        cout << i << ' ';
      }
      cout << endl;
    } else {
      int l = (ma - (mi + 1) + 1) / 2;
      int r = mi * 2 + 1 + (ma - (mi + 1)) / 2;
      if (del % 2 == 0) {
        cout << (r - l + 1) / 2 << endl;
        for (int i = l; i <= r; i += 2) {
          cout << i << ' ';
        }
        cout << endl;
      } else {
        cout << r - l + 1 << endl;
        for (int i = l; i <= r; ++i) {
          cout << i << ' ';
        }
        cout << endl;
      }
    }
  }
}

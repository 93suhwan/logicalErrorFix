#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  int num;
  cin >> num;
  while (num--) {
    int ct = 0;
    map<int, int> v;
    int x, n;
    cin >> n;
    for (int w = 1; w <= n; w++) {
      cin >> x;
      if (x >= 1 && x <= n && !v[x]) {
        v[x] = 1;
        continue;
      }
      a[++ct] = (x - 1) / 2;
    }
    sort(a + 1, a + ct + 1);
    int begin = 1, ok = 1;
    for (int w = 1; w <= n; w++) {
      if (!v[w]) {
        if (a[begin++] < w) {
          ok = 0;
        }
      }
    }
    if (ok) {
      cout << ct << "\n";
    } else {
      cout << "-1"
           << "\n";
    }
  }
  return 0;
}

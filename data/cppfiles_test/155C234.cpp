#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
struct yj {
  int i;
  int x;
  char c;
};
yj a[N];
int b[N];
bool cmp(yj x, yj y) { return x.x < y.x; }
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int p = 0;
    for (int i = 1; i <= n; i++) cin >> a[i].x;
    for (int i = 1; i <= n; i++) {
      cin >> a[i].c;
      a[i].i = i;
      if (a[i].c == '0') p++;
    }
    int t = 1;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
      if (a[i].c == '0') {
        b[a[i].i] = t++;
      } else
        b[a[i].i] = ++p;
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
  }
  return 0;
}

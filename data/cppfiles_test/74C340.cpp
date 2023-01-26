#include <bits/stdc++.h>
using namespace std;
int test, a, b;
bool cl[200005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> test;
  while (test--) {
    cin >> a >> b;
    int n = a + b;
    int x = (n + 1) / 2, y = n - x;
    for (int i = 0; i <= min(a, x); ++i) {
      if (y >= a - i && b >= (x - i) && y - (a - i) == (b - (x - i))) {
        cl[x - i + a - i] = 1;
      }
    }
    swap(x, y);
    for (int i = 0; i <= min(a, x); ++i) {
      if (y >= a - i && b >= (x - i) && y - (a - i) >= (b - (x - i))) {
        cl[x - i + a - i] = 1;
      }
    }
    int rs = 0;
    for (int i = 0; i <= n; ++i)
      if (cl[i]) ++rs;
    cout << rs << '\n';
    for (int i = 0; i <= n; ++i)
      if (cl[i]) cout << i << " ";
    cout << '\n';
    for (int i = 0; i <= n; ++i) cl[i] = 0;
  }
  return 0;
}

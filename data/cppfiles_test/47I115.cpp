#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int an[N], o[N];
int a[N];
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    cout << "and"
         << " " << 1 << " " << i << endl;
    cin >> an[i];
    fflush(stdout);
    cout << "or"
         << " " << 1 << " " << i << endl;
    cin >> o[i];
    fflush(stdout);
  }
  int x, y;
  cout << "and"
       << " " << 2 << " " << 3 << endl;
  cin >> x;
  fflush(stdout);
  cout << "or"
       << " " << 2 << " " << 3 << endl;
  cin >> y;
  fflush(stdout);
  a[1] = an[2];
  int z = o[2] - an[2];
  for (int i = 0; i < 32; i++) {
    if (z & (1 << i)) {
      if (an[3] & (1 << i)) {
        a[1] += 1 << i;
      } else if ((x & (1 << i)) == 0) {
        if (o[3] & (1 << i)) {
          a[1] += 1 << i;
        }
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    a[i] = o[i] - a[1] + an[i];
  }
  sort(a + 1, a + 1 + n);
  cout << a[k] << endl;
}
int main() {
  int T = 1;
  while (T--) solve();
}

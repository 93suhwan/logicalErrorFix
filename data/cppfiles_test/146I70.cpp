#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const long long N = 2e5 + 5;
long long a[N][25], n, q;
void up() {
  for (long long j = 1; j <= 20; j++) {
    for (long long i = 1; i <= n; i++) {
      a[i][j] = a[a[i][j - 1]][j - 1];
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i][0];
  }
  up();
  while (q--) {
    long long op;
    cin >> op;
    if (op == 1) {
      long long x, y;
      cin >> x >> y;
      swap(a[x][0], a[y][0]);
      for (long long j = 1; j <= 20; j++) {
        a[x][j] = a[a[x][j - 1]][j - 1];
        a[y][j] = a[a[y][j - 1]][j - 1];
      }
    } else {
      long long x, k;
      cin >> x >> k;
      for (long long j = 1; j <= 20; j++) {
        a[x][j] = a[a[x][j - 1]][j - 1];
      }
      for (long long i = 20; i >= 0; i--) {
        if (k >= (1 << i)) {
          x = a[x][i];
          k -= (1 << i);
        }
      }
      cout << x << endl;
    }
  }
}

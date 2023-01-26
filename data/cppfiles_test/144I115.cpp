#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 99;
int n, m, k, t, a[N];
void Main() {
  cin >> n >> m >> k;
  int x = (n + m - 1) / m, last = 0;
  for (int i = 0; i < k; i++) {
    int now = n, copy = last, M = m;
    while (now > 0 && (now + m - 1) / m == x) {
      cout << x << " ";
      for (int j = 0; j < x; j++) {
        cout << last + 1 << " ";
        last = (last + 1) % n;
      }
      cout << endl;
      now -= x;
      m--;
    }
    int mv = last;
    while (now > 0) {
      cout << x - 1 << " ";
      for (int j = 0; j < x - 1; j++) {
        cout << mv + 1 << " ";
        mv = (mv + 1) % n;
      }
      cout << endl;
      mv = (mv + 1) % n;
      now -= x - 1;
      m--;
    }
    m = M;
    cout << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> t;
  while (t--) {
    Main();
  }
}

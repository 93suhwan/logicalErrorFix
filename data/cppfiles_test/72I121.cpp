#include <bits/stdc++.h>
using namespace std;
int ask(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int n;
  cin >> n;
  return n;
}
int N = 1e9;
signed main() {
  int lo = 1;
  int hi = N - 1;
  int q = N;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (ask(N, mid) > ask(N, mid + 1)) {
      lo = mid + 1;
      q = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  int p = N - ask(N, q);
  int y = ask(p, 1);
  int x = ask(1, q);
  cout << "! " << x << " " << y << " " << p << " " << q << endl;
}

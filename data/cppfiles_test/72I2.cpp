#include <bits/stdc++.h>
using namespace std;
const int N = 1e9;
int ask(int x, int y) {
  cout << "? " << x << " " << y << endl;
  cout.flush();
  cin >> x;
  return x;
}
void answerit(int x1, int y1, int x2, int y2) {
  cout << "! " << min(x1, x2) << " " << min(y1, y2) << " " << max(x1, x2) << " "
       << max(y1, y2) << endl;
}
int main() {
  int d1 = ask(1, N), d2 = ask(N, N);
  int mid = (N + d1 - d2) / 2;
  int d3 = ask(mid, 1), d4 = ask(mid, N);
  int x, y, p, q;
  y = d3 + 1, x = d1 - d4, p = N - (d2 - d4), q = N - d4;
  answerit(x, y, p, q);
  return 0;
}

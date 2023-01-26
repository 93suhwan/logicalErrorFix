#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  int orands = 0;
  vector<int> o(n + 1), a(n + 1);
  for (int i = 2; i <= n; i++) {
    cout << "and 1 " << i << endl;
    cin >> a[i];
    orands |= a[i];
  }
  int andors = (1 << 30) - 1;
  for (int i = 2; i <= n; i++) {
    cout << "or 1 " << i << endl;
    cin >> o[i];
    andors &= o[i];
  }
  cout << "and 2 3" << endl;
  int x;
  cin >> x;
  int c1 = orands;
  for (int i = 0; i < 30; i++) {
    if (((orands >> i) & 1) == 0 && ((andors >> i) & 1) == 1 &&
        ((x >> i) & 1) == 0) {
      c1 |= (1 << i);
    }
  }
  vector<int> c(n + 1);
  c[1] = c1;
  for (int i = 2; i <= n; i++) {
    c[i] = c[1] ^ (o[i] - a[i]);
  }
  sort(c.begin() + 1, c.end());
  cout << "finish " << c[k] << endl;
}

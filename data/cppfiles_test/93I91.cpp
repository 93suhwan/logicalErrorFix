#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int maxn = 3e5 + 5;
int a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  a[0] = 0;
  for (int i = 1; i < maxn; ++i) {
    a[i] = i ^ a[i - 1];
  }
  int CASE;
  cin >> CASE;
  while (CASE--) {
    int aa, bb;
    cin >> aa >> bb;
    if (aa > bb && a[aa - 1] == bb)
      cout << aa << endl;
    else if ((bb ^ a[aa - 1]) < aa)
      cout << aa + 1 << endl;
    else if ((bb ^ a[aa - 1]) == aa) {
      cout << aa + 2 << endl;
    } else
      cout << aa + 1 << endl;
  };
  return 0;
}

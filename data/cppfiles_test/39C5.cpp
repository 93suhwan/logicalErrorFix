#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, r[maxn], l[maxn], p[maxn];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "? ";
    for (int j = 1; j <= n; j++)
      if (i ^ j)
        cout << 1 << ' ';
      else
        cout << 2 << ' ';
    cout << endl;
    int x;
    cin >> x;
    if (x > 0 && x != i) r[i] = x, l[x] = i;
    cout << "?" << ' ';
    for (int j = 1; j <= n; j++)
      if (i ^ j)
        cout << 2 << ' ';
      else
        cout << 1 << ' ';
    cout << endl;
    cin >> x;
    if (x > 0 && x != i) l[i] = x, r[x] = i;
  }
  int idx = 0;
  for (int i = n; i >= 1; i--)
    if (!l[i]) {
      idx = i;
      break;
    }
  int i = 1;
  while (1 == 1) {
    p[idx] = i++;
    if (!r[idx]) break;
    idx = r[idx];
  }
  cout << "!" << ' ';
  for (int i = 1; i <= n; i++) cout << p[i] << ' ';
  cout << endl;
  return 0;
}

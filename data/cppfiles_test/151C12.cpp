#include <bits/stdc++.h>
using namespace std;
const int mxn = 5e5 + 5;
int p[mxn], t[mxn], x[mxn], y[mxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  vector<int> a;
  for (int i = 1; i <= mxn - 5; i++) p[i] = i;
  for (int i = q; i >= 1; i--) {
    cin >> t[i] >> x[i];
    if (t[i] == 2) cin >> y[i];
  }
  for (int i = 1; i <= q; i++)
    if (t[i] == 1)
      a.push_back(p[x[i]]);
    else
      p[x[i]] = p[y[i]];
  for (int i = a.size() - 1; i >= 0; i--) cout << a[i] << " ";
}

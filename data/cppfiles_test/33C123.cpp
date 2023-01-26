#include <bits/stdc++.h>
const long long int modd = 65536;
const long long int base = 233;
const double pi = acos(-1);
const int N = 2e5 + 10;
const int M = 1e9;
const double esp = 1e-6;
using namespace std;
long long int id = 0, n, m, tot = 0, ttt = 0, mod, a[100010], b[100010],
              c[100010];
string s;
vector<long long int> ans;
void innt() {
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
}
int main() {
  long long int zt, i, j, flat = 0, iz = 0, ip = 0, l, r, ma = 0, mi, x, y, k;
  ios::sync_with_stdio(false);
  cin >> n;
  innt();
  ans.clear();
  flat = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 0) flat = 1;
  }
  for (i = 1; i <= n; i++) {
    for (j = 0; j < 520; j++) {
      c[j] = b[j];
    }
    for (j = 1; j < 520; j++) {
      if (c[j] && c[j] < a[i]) {
        x = a[i] ^ j;
        if (c[x] != 0)
          b[x] = min(a[i], c[x]);
        else
          b[x] = a[i];
      }
    }
    if (c[a[i]]) {
      flat = 1;
      b[a[i]] = min(c[a[i]], a[i]);
    } else
      b[a[i]] = a[i];
  }
  ans.push_back(0);
  for (i = 1; i < 520; i++) {
    if (b[i]) ans.push_back(i);
  }
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}

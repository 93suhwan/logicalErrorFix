#include <bits/stdc++.h>
using namespace std;
const int MX = 4005;
int n, m, a[MX];
vector<long long> f(int i, int j) {
  if (i > j) return {0};
  int ind = i;
  for (int k = i; k <= j; k++)
    if (a[k] < a[ind]) ind = k;
  vector<long long> izq = f(i, ind - 1);
  vector<long long> der = f(ind + 1, j);
  vector<long long> res(j - i + 2, -1e18);
  for (int x = 0; x < int(izq.size()); x++)
    for (int y = 0; y < int(der.size()); y++) {
      res[x + y] = max(res[x + y], izq[x] + der[y] - 2ll * x * y * a[ind]);
      res[x + y + 1] =
          max(res[x + y + 1], izq[x] + der[y] - 2ll * (x * y + x + y) * a[ind] +
                                  (m - 1) * a[ind]);
    }
  return res;
}
void main_() {
  cin >> n >> m;
  for (int i = 0; i < int(n); i++) cin >> a[i];
  cout << f(0, n - 1)[m] << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) main_();
  return 0;
}

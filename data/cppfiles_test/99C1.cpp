#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
const int di[8] = {1, 0, -1, 0, -1, -1, 1, 1},
          dj[8] = {0, 1, 0, -1, -1, 1, -1, 1};
long long t, n;
long long x0;
vector<long long> v;
void solve() {
  long long r = n % 4;
  long long d = (n - 1) / 4;
  for (int i = (1); i <= (r); i++) {
    long long a = 4 * d + i;
    v.push_back(a);
  }
  long long ans = 0;
  if (abs(x0) % 2 == 1) {
    for (int i = (0); i <= ((int)(v).size() - 1); i++) {
      if (i == 0 or i == 3)
        ans += v[i];
      else
        ans -= v[i];
    }
  } else {
    for (int i = (0); i <= ((int)(v).size() - 1); i++) {
      if (i == 0 or i == 3)
        ans -= v[i];
      else
        ans += v[i];
    }
  }
  cout << x0 + ans << endl;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    v.clear();
    solve();
  }
  return 0;
}

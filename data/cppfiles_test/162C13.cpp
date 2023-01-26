#include <bits/stdc++.h>
const double pi = acos(-1);
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b != 0) {
    if (b & 1) res *= a;
    a *= a;
    b >>= 1;
  }
  return res;
}
using namespace std;
long long l, r, mid, n;
vector<long long> a;
bool check() {
  vector<long long> temp = a;
  for (int i = n - 1; i >= 2; i--) {
    if (temp[i] < mid) return 0;
    long long dif = temp[i] - mid, d = min(dif / 3, a[i] / 3);
    temp[i] -= (3 * d), temp[i - 1] += d, temp[i - 2] += (2 * d);
  }
  for (int i = 0; i < n; i++) {
    if (temp[i] < mid) return 0;
  }
  return 1;
}
void solve() {
  while (l <= r) {
    mid = (l + r) / 2;
    if (check())
      l = mid + 1;
    else
      r = mid - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int z = 1;
  cin >> z;
  for (int i = 1; i < z + 1; i++) {
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    l = 1, r = 1e9 + 2;
    solve();
    cout << r << "\n";
  }
}

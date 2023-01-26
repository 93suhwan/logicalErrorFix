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
  for (int i = 2; i < n; i++) {
    long long d = 0;
    if (temp[i - 2] < mid) {
      long long dif = mid - temp[i - 2];
      d = (dif + 1) / 2;
    }
    if (temp[i] > mid) {
      long long dif = temp[i] - mid;
      d = max(d, dif / 3);
    }
    if (temp[i - 1] < mid) d = max(d, mid - temp[i - 1]);
    d = min(d, temp[i] / 3);
    temp[i - 2] += (2 * d), temp[i - 1] += d, temp[i] -= (3 * d);
    if (temp[i] < 0) return 0;
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

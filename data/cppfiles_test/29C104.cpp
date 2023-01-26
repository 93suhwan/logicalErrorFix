#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
long long tree[N][3];
int a[N], n;
void add(int x, int y, int z) {
  for (; x < N; x += x & -x) {
    tree[x][z] += y;
  }
}
long long sum(int x, int z) {
  long long ans = 0;
  for (; x > 0; x -= x & -x) {
    ans += tree[x][z];
  }
  return ans;
}
long long sum(int l, int r, int z) { return sum(r, z) - sum(l - 1, z); }
void range_update(int l, int r, long long x, int z) {
  add(l, x, z);
  add(r + 1, -x, z);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1LL * a[i] * (i - 1);
    ans -= sum(a[i] + 1, 2);
    int cnt = 0;
    for (int x = 0; x < N; x += a[i]) {
      int y = min(x + a[i], N) - 1;
      ans += sum(x, y, 1);
      ans -= sum(x, y, 0) * x;
      range_update(x + 1, y + 1, 1LL * cnt * a[i], 2);
      ++cnt;
    }
    add(a[i], 1, 0);
    add(a[i], a[i], 1);
    cout << ans << ' ';
  }
}

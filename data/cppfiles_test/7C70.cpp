#include <bits/stdc++.h>
#pragma GCC optmize("O3,unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
inline long long inv(long long x, long long MOD = mod) {
  long long power = MOD - 2, ret = 1;
  while (power) {
    if (power & 1) (ret *= x) %= MOD;
    power >>= 1;
    (x *= x) %= MOD;
  }
  return ret;
}
inline long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int n;
long long arr[200000 + 5];
long long sgt[4 * 200000 + 100];
void build(int left, int right, int x) {
  if (left == right) {
    sgt[x] = abs(arr[left] - arr[left + 1]);
    return;
  }
  int mid = ((left + right) >> 1);
  build(left, mid, 2 * x);
  build(mid + 1, right, 2 * x + 1);
  sgt[x] = gcd(sgt[2 * x], sgt[2 * x + 1]);
}
long long query(int left, int right, int l, int r, int x) {
  if (right < l || left > r) {
    return -1;
  }
  if (left >= l && right <= r) {
    return sgt[x];
  }
  int mid = ((left + right) >> 1);
  long long r1 = query(left, mid, l, r, 2 * x),
            r2 = query(mid + 1, right, l, r, 2 * x + 1);
  if (r1 != -1 && r2 != -1) {
    return gcd(r1, r2);
  } else if (r1 == -1) {
    return r2;
  } else {
    return r1;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n == 1) {
      cout << 1 << '\n';
    } else {
      build(0, n - 1, 1);
      int left = 0, maxx = 1, acc = 1;
      for (int i = 1; i < n; i++) {
        long long now = abs(arr[i] - arr[i - 1]);
        while (left < i && query(0, n - 1, left, i - 1, 1) == 1) {
          left++;
        }
        maxx = max(maxx, i - left + 1);
      }
      cout << maxx << '\n';
    }
  }
}

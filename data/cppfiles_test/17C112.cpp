#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
long long a[N + 5], c[N + 5], b[N + 5];
long long n, m;
long long getSum(int x) {
  long long sum = 0;
  while (x > 0) {
    sum += c[x];
    x -= (x & (-x));
  }
  return sum;
}
void add(long long x, long long val) {
  while (x <= m) {
    c[x] += val;
    x += (x & (-x));
  }
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    memset(c, 0, sizeof(c));
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    m = unique(b, b + n) - b;
    for (long long i = 0; i < n; i++) {
      a[i] = lower_bound(b, b + m, a[i]) - b + 1;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long s = getSum(a[i] - 1);
      long long l = i - getSum(a[i]);
      if (s > l) {
        ans += l;
      } else {
        ans += s;
      }
      add(a[i], 1);
    }
    cout << ans << endl;
  }
}

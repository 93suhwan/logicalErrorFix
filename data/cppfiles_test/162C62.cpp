#include <bits/stdc++.h>
using namespace std;
struct piii {
  long long first, second, th;
  bool operator<(const piii &b) {
    if (first != b.first) return first < b.first;
    if (second != b.second) return second < b.second;
    return th < b.th;
  }
};
const long long oo = 1e15;
const int maxn = 2e5 + 5;
long long a[maxn], b[maxn], c[maxn];
int m, n;
bool check(long long val) {
  for (int i = 1; i <= n; i++) {
    b[i] = a[i];
    c[i] = 0;
  }
  for (int i = n; i >= 3; i--) {
    if (b[i] + c[i] < val) return false;
    long long d = (b[i] + c[i] - val) / 3;
    d = min(d, b[i] / 3);
    b[i] -= d * 3;
    c[i - 1] += d;
    c[i - 2] += 2 * d;
  }
  for (int i = 1; i <= n; i++)
    if (b[i] + c[i] < val) return false;
  return true;
}
int main() {
  cout << setprecision(2) << fixed;
  ios::sync_with_stdio(false), cin.tie(0);
  int ntest;
  cin >> ntest;
  while (ntest--) {
    cin >> n;
    long long l = 1, r = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      r = max(r, a[i]);
    }
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (check(mid))
        l = mid + 1;
      else
        r = mid;
    }
    if (check(l)) l++;
    cout << l - 1 << '\n';
  }
  return 0;
}

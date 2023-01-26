#include <bits/stdc++.h>
using namespace std;
const long long oo = INT_MAX;
long long t, n, k, cnt, a[100005], b[100005], fr[100005];
long long build(long long poz) {
  long long auxcnt = cnt;
  if (cnt > k) {
    return oo;
  }
  for (long long i = poz + 1; i <= a[0]; i++) {
    b[i] = -1;
    for (long long c = 0; c <= 9; c++) {
      if (i == poz + 1 && c <= a[i]) {
        continue;
      }
      if (fr[c] || (!fr[c] && cnt < k)) {
        ++fr[c];
        b[i] = c;
        if (fr[c] == 1) {
          ++cnt;
        }
        break;
      }
    }
  }
  for (long long i = poz + 1; i <= a[0]; i++) {
    if (b[i] == -1) {
      continue;
    }
    --fr[b[i]];
  }
  cnt = auxcnt;
  long long val = 0;
  for (long long i = 1; i <= poz; i++) {
    val = val * 10 + a[i];
  }
  for (long long i = poz + 1; i <= a[0]; i++) {
    if (b[i] == -1) {
      return oo;
    }
    val = val * 10 + b[i];
  }
  return val;
}
void solve_test() {
  cin >> n >> k;
  for (long long i = 0; i <= 9; i++) {
    fr[i] = 0;
  }
  cnt = 0;
  long long aux = n;
  a[0] = 0;
  while (n) {
    a[++a[0]] = n % 10;
    b[a[0]] = n % 10;
    n /= 10;
  }
  reverse(a + 1, a + a[0] + 1);
  long long Min = build(0);
  for (long long i = 1; i <= a[0]; i++) {
    ++fr[a[i]];
    if (fr[a[i]] == 1) {
      ++cnt;
    }
    Min = min(Min, build(i));
  }
  cout << Min << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  for (long long test = 1; test <= t; test++) {
    solve_test();
  }
  return 0;
}

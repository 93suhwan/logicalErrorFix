#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 7;
long long n;
char a[N];
long long k;
long long x;
long long mim[N];
long long ban[N];
long long s[N];
void solve() {
  long long cnt = 0;
  string res = "";
  cin >> n >> k >> x;
  long long dak = 1;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ban[i] = 0;
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] == '*') {
      long long dem = 0;
      long long j = i;
      while (j <= n && a[j] == '*') {
        dem++;
        j++;
      }
      mim[++cnt] = (j - i) * k + 1;
      i = j - 1;
    }
  }
  long long pos = cnt + 1;
  for (long long i = cnt; i >= 1; i--) {
    if (dak >= x / mim[i]) {
      pos = i;
      break;
    }
    dak = dak * mim[i];
    s[i] = dak;
  }
  s[cnt + 1] = 1;
  for (long long i = pos; i <= cnt; i++) {
    ban[i] = x / s[i + 1] - 1;
    x = x - ban[i] * s[i + 1];
  }
  long long id = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i] == 'a') {
      cout << 'a';
    } else {
      long long j = i;
      while (j <= n && a[j] == '*') {
        j++;
      }
      id++;
      for (long long t = 1; t <= ban[id]; t++) {
        cout << 'b';
      }
      i = j - 1;
    }
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    solve();
  }
}

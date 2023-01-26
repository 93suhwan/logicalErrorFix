#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5;
long long n;
string s;
long long a[N][6];
long long t[N];
long long ans, k, tmp, pos, cnt;
void inp() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> s;
    k = s.length();
    for (long long j = 0; j <= k - 1; ++j) {
      a[i][(long long)(s[j] - 'a')]++;
    }
    for (long long j = 0; j <= 4; ++j) {
      a[i][j] = 2 * a[i][j] - k;
    }
  }
}
bool cmp(long long x, long long y) { return x > y; }
long long process(long long c) {
  tmp = 0;
  pos = 0;
  cnt = 0;
  for (long long i = 1; i <= n; ++i) {
    t[i] = a[i][c];
  }
  sort(t + 1, t + 1 + n, cmp);
  do {
    tmp += t[++pos];
    if (tmp <= 0) {
      break;
    }
    cnt++;
  } while (tmp > 0 && pos < n);
  return cnt;
}
void init() {
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j <= 4; ++j) {
      a[i][j] = 0;
    }
  }
}
void show() {
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 0; j <= 4; ++j) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc;
  cin >> tc;
  while (tc--) {
    init();
    inp();
    for (long long i = 0; i <= 4; ++i) {
      ans = max(ans, process(i));
    }
    cout << ans << '\n';
    ans = 0;
  }
  return 0;
}

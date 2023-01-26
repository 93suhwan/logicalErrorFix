#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 100;
double x[maxn], y[maxn];
long long n;
long long a[maxn];
char c[maxn];
map<char, long long> mp;
struct node {
  long long id, val;
} b[maxn], d[maxn];
bool cmp(node a, node b) { return a.val < b.val; }
bool cmp1(node a, node b) { return a.val > b.val; }
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    for (long long i = 1; i <= n; i++) cin >> c[i];
    long long cnt1 = 0, cnt = 0;
    for (long long i = 1; i <= n; i++) {
      if (c[i] == 'B') {
        b[++cnt1].id = i;
        b[cnt1].val = a[i];
      } else {
        d[++cnt].id = i;
        d[cnt].val = a[i];
      }
    }
    long long flag = 1;
    sort(b + 1, b + 1 + cnt1, cmp);
    sort(d + 1, d + 1 + cnt, cmp1);
    for (long long i = 1; i <= cnt; i++) {
      if (d[i].val > n - i + 1) flag = 0;
    }
    for (long long i = 1; i <= cnt1; i++) {
      if (b[i].val < i) flag = 0;
    }
    if (!flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}

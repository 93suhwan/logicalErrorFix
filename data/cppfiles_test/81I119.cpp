#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ksm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret;
}
const int maxn = 3e5 + 5;
int t, n, m, a[maxn], ans[maxn], d[maxn << 2], sqt, cur;
char s[maxn];
deque<int> dq;
struct node {
  int l, r, id;
} q[maxn];
void add(int x, int ok) {
  if (ok) {
    if (dq.size() && dq.front() == x)
      dq.pop_front();
    else
      dq.push_front(x);
  } else {
    if (dq.size() && dq.back() == x)
      dq.pop_back();
    else
      dq.push_back(x);
  }
}
void del(int x, int ok) {
  if (ok) {
    if (dq.size() && dq.front() == x)
      dq.pop_front();
    else
      dq.push_front(x);
  } else {
    if (dq.size() && dq.back() == x)
      dq.pop_back();
    else
      dq.push_back(x);
  }
}
bool cmp(node a, node b) {
  if (a.l / sqt == b.l / sqt) return a.r < b.r;
  return a.l < b.l;
}
int main() {
  cin >> t;
  while (t--) {
    scanf("%d %d", &n, &m);
    cur = 0;
    while (dq.size()) dq.pop_back();
    sqt = sqrt(n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++)
      if (s[i] == '+')
        a[i] = 1;
      else
        a[i] = -1;
    for (int i = 1; i <= m; i++) {
      scanf("%d %d", &q[i].l, &q[i].r);
      q[i].id = i;
    }
    sort(q + 1, q + 1 + m, cmp);
    int L = 1, R = 0;
    for (int i = 1; i <= m; i++) {
      while (R < q[i].r) add(a[++R], 1);
      while (L > q[i].l) add(a[--L], 0);
      while (L < q[i].l) del(a[L++], 0);
      while (R > q[i].r) del(a[R--], 1);
      if (dq.size() % 2 != 0)
        ans[q[i].id] = 1;
      else if (dq.size())
        ans[q[i].id] = 2;
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  }
  return 0;
}

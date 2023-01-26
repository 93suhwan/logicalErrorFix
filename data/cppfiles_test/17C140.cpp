#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5 + 5;
int T, n, t[Maxn * 4], m;
long long ans;
struct Node {
  long long num;
  int ini, seq;
} a[Maxn];
bool cmp1(const Node &a, const Node &b) { return a.num < b.num; }
bool cmp2(const Node &a, const Node &b) { return a.ini < b.ini; }
inline int lowbit(int x) { return x & -x; }
void add(int x) {
  while (x <= m) {
    t[x]++;
    x += lowbit(x);
  }
}
long long query(int l, int r) {
  long long sumr = 0, suml = 0;
  while (r) {
    sumr += t[r];
    r -= lowbit(r);
  }
  while (l) {
    suml += t[l];
    l -= lowbit(l);
  }
  return sumr - suml;
}
int main() {
  cin >> T;
  while (T--) {
    cin >> n;
    memset(t, 0, sizeof(t));
    ans = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i].num, a[i].ini = i;
    sort(a + 1, a + 1 + n, cmp1);
    a[1].seq = 1;
    for (int i = 2; i <= n; ++i)
      a[i].seq = a[i - 1].seq + (a[i].num != a[i - 1].num);
    m = a[n].seq;
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i <= n; ++i) {
      long long l = query(0, a[i].seq - 1), r = query(a[i].seq, m);
      if (l < r)
        ans += l;
      else
        ans += r;
      add(a[i].seq);
    }
    cout << ans << "\n";
  }
  return 0;
}

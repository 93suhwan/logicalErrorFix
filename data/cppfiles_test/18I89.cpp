#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
int dir[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long ksm(long long a, long long n, long long mod) {
  long long t = 1;
  for (; n; n >>= 1, (a *= a) %= mod)
    if (n & 1) (t *= a) %= mod;
  return t;
}
const int N = 100 + 5;
struct Nod {
  int l, r;
} arr[N], tmp;
vector<Nod> res;
int cnt[N << 1];
vector<int> v;
bool cmp(Nod n1, Nod n2) { return n1.l < n2.l; }
int n, k;
int add(int x) { return x % (2 * n) + 1; }
int sub(int x) {
  x = x - 1 + 2 * n;
  return (x - 1) % (2 * n) + 1;
}
int solve(int l, int r, int x) {
  for (int i = l; i <= r; i++)
    if ((i - 1) % (2 * n) + 1 == x) return 1;
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    v.clear();
    res.clear();
    memset(cnt, 0, sizeof(cnt));
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
      cin >> arr[i].l >> arr[i].r;
      if (arr[i].l > arr[i].r) swap(arr[i].l, arr[i].r);
      cnt[arr[i].l] = 1;
      cnt[arr[i].r] = 1;
      res.push_back(arr[i]);
    }
    for (int i = 1; i <= 2 * n; i++)
      if (!cnt[i]) v.push_back(i);
    for (int i = 0; i < v.size() / 2; i++) {
      tmp.l = v[i];
      tmp.r = v[i + v.size() / 2];
      res.push_back(tmp);
    }
    sort(res.begin(), res.end(), cmp);
    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
      int l1, r1, l2, r2;
      l1 = add(res[i].l);
      r1 = sub(res[i].r);
      l2 = add(res[i].r);
      r2 = sub(res[i].l);
      if (r2 < l2) r2 += n * 2;
      for (int j = 0; j < res.size(); j++) {
        if (j == i) continue;
        if (solve(l1, r1, res[j].l) && solve(l2, r2, res[j].r)) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

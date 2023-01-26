#include <bits/stdc++.h>
using namespace std;
mt19937 mrand(random_device{}());
const long long mod = 998244353;
int rnd(int x) { return mrand() % x; }
long long powm(long long m, long long k) {
  long long res = 1, t = m;
  while (k) {
    if (k & 1) res = res * t % mod;
    t = t * t % mod;
    k >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 2e5 + 10;
int n, m;
int t;
int ans[N];
struct node {
  int v, r, p;
} a[N];
string s;
bool cmp(node a, node b) { return a.r < b.r; }
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].v, a[i].p = i;
    cin >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        a[i].r = 0;
      else
        a[i].r = 1;
    }
    sort(a, a + n, cmp);
    int l = 0, r = 0;
    while (a[r].r == 0) r++;
    int idx = r;
    while (l < idx) {
      if (a[l].v > idx) {
        while (a[r].v > idx) ans[a[r].p] = a[r].v, r++;
        ans[a[l].p] = a[r].v, ans[a[r].p] = a[l].v;
        l++, r++;
      } else
        ans[a[l].p] = a[l].v, l++;
    }
    while (r < n) {
      ans[a[r].p] = a[r].v, r++;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    puts("");
  }
  return 0;
}

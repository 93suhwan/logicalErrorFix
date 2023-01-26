#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int n, m;
long long c[N];
long long lowbit(long long x) { return x & (-x); }
void updata(long long i, int k) {
  while (i <= m) {
    c[i] += k;
    i += lowbit(i);
  }
}
long long get_sum(long long i) {
  long long res = 0;
  while (i) {
    res += c[i];
    i -= lowbit(i);
  }
  return res;
}
int main() {
  int _;
  scanf("%d", &_);
  while (_--) {
    scanf("%d %d", &n, &m);
    vector<int> a(m + 1), b(m + 1), res(m + 1), all;
    map<int, vector<int>> pos;
    for (int i = 1; i <= m; ++i) c[i] = 0;
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &a[i]);
      pos[a[i]].push_back(i);
      b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    int now = 1;
    for (int i = 1; i <= m; ++i) {
      reverse(pos[b[i]].begin(), pos[b[i]].end());
      for (auto w : pos[b[i]]) {
        res[w] = now;
        now++;
      }
      while (b[i] == b[i + 1]) i++;
    }
    for (int i = 1; i <= m; ++i) all.push_back(res[i]);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    long long ans = 0;
    for (int i = m; i >= 1; --i) {
      int cur = lower_bound(all.begin(), all.end(), res[i]) - all.begin();
      updata(cur + 1, 1);
      ans += i - get_sum(cur + 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}

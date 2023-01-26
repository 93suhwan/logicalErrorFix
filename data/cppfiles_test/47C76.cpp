#include <bits/stdc++.h>
long long q_pow(long long x, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = x * ret % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
long long getbit(long long now) {
  int cnt = 0;
  while (now) {
    cnt++;
    now -= (now) & (-now);
  }
  return cnt;
}
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
using namespace std;
const long long maxn = 3e5 + 10;
const long long maxm = 200 + 2;
const long long INF = 0x3f3f3f3f;
const long long IINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void mul(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
long long num[maxn];
long long andnum[maxn];
long long ornum[maxn];
long long ans[maxn];
long long and_opt(int i, int j) {
  fflush(stdout);
  cout << "and " << i << " " << j << endl;
  long long tmp;
  scanf("%lld", &tmp);
  return tmp;
}
long long or_opt(int i, int j) {
  fflush(stdout);
  cout << "or " << i << " " << j << endl;
  long long tmp;
  scanf("%lld", &tmp);
  return tmp;
}
void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    andnum[i] = and_opt(1, i);
    ornum[i] = or_opt(1, i);
    num[i] = andnum[i] + ornum[i];
  }
  long long a23 = and_opt(2, 3) + or_opt(2, 3);
  ans[1] = num[2] + num[3] - a23;
  ans[1] /= 2;
  for (int i = 2; i <= n; i++) {
    ans[i] = num[i] - ans[1];
  }
  sort(ans + 1, ans + n + 1);
  fflush(stdout);
  cout << "finish " << ans[k] << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

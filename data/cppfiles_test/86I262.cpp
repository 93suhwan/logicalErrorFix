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
const long long maxn = 1e5 + 10;
const long long INF = 0x3f3f3f3f;
const long long IINF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const long long mod = 998244353;
void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
void mul(long long &x, long long y) {
  x -= y;
  if (x < 0) x += mod;
}
vector<int> vec[2];
char num[2][maxn];
void solve() {
  vec[0].clear();
  vec[1].clear();
  int n;
  cin >> n;
  cin >> (num[0] + 1);
  cin >> (num[1] + 1);
  for (int i = 1; i <= n; i++) {
    num[0][i] -= '0';
    num[1][i] -= '0';
  }
  for (int i = 1; i <= n; i++) {
    if (num[0][i] == num[1][i])
      vec[num[0][i]].emplace_back(i);
    else {
      vec[num[0][i]].emplace_back(i);
      vec[num[1][i]].emplace_back(i);
    }
  }
  if (vec[0].size() == 0) {
    cout << 0 << "\n";
    return;
  }
  if (vec[1].size() == 0) {
    cout << n << "\n";
    return;
  }
  int ans = 0;
  int cnt0 = 0;
  int cnt1 = 0;
  while (cnt0 < vec[0].size() and cnt1 < vec[1].size()) {
    int now = max(vec[0][cnt0], vec[1][cnt1]);
    while (vec[0][cnt0] < now and cnt0 < vec[0].size()) cnt0++;
    while (vec[1][cnt1] < now and cnt1 < vec[1].size()) cnt1++;
    ans += 2;
    if (vec[0][cnt0] == now) cnt0++;
    if (vec[1][cnt1] == now) cnt1++;
  }
  if (*vec[0].rbegin() > *vec[1].rbegin())
    ans += abs(*vec[0].rbegin() - *vec[1].rbegin());
  cout << ans << "\n";
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

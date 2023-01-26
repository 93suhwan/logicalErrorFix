#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 19;
const int maxm = 1e6 + 19;
const int inf = 0x3f3f3f3f;
const long long mod = 998244353;
const double eps = 1e-10;
int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
unsigned long long x, y;
int b[64], a[64];
bool ok;
map<unsigned long long, bool> m;
pair<unsigned long long, unsigned long long> trans(unsigned long long t) {
  t <<= 1;
  long long maxnum = 0;
  for (long long i = 0; i <= 63; i++) {
    if (t & (1LL << i))
      b[i] = 1, maxnum = max(maxnum, i);
    else
      b[i] = 0;
    a[i] = b[i];
  }
  a[0] = 1;
  reverse(b, b + maxnum + 1);
  reverse(a, a + maxnum + 1);
  pair<unsigned long long, unsigned long long> miao;
  unsigned long long tmp1 = 0, tmp2 = 0;
  for (long long i = 0; i <= maxnum; i++) {
    if (b[i]) tmp1 |= (1LL << i);
    if (a[i]) tmp2 |= (1LL << i);
  }
  miao.first = tmp1;
  miao.second = tmp2;
  return miao;
}
void bfs(unsigned long long p) {
  queue<unsigned long long> q;
  q.push(p);
  m[p] = true;
  while (!q.empty()) {
    unsigned long long t = q.front();
    q.pop();
    pair<unsigned long long, unsigned long long> miao = trans(t);
    if (!m.count(miao.first)) {
      m[miao.first] = true;
      if (miao.first == y) {
        ok = true;
        return;
      }
      q.push(miao.first);
    }
    if (!m.count(miao.second)) {
      m[miao.second] = true;
      if (miao.second == y) {
        ok = true;
        return;
      }
      q.push(miao.second);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> x >> y;
  if (x == y) ok = true;
  bfs(x);
  if (ok)
    cout << "YES";
  else
    cout << "NO";
  return ~~(0 - 0);
}

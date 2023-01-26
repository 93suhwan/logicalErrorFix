#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (x % 998244353 == 0) return 0;
  long long int pow = 1;
  while (n) {
    if (n & 1) pow = (pow * x) % 998244353;
    n = n >> 1;
    x = (x * x) % 998244353;
  }
  return pow;
}
void ntt(vector<int> &p, bool inv) {
  int n = p.size();
  assert((n & (-n)) == n);
  assert(((998244353 - 1) & (n - 1)) == 0);
  for (int i = 1, j = 0; i < n; i++) {
    int bit = (n >> 1);
    for (; bit & j; bit >>= 1) {
      j = j ^ bit;
    }
    j = j | bit;
    if (i < j) swap(p[i], p[j]);
  }
  const int highest = (998244353 - 1) & (1 - 998244353);
  const int primitive = 3;
  const int root = power(primitive, (998244353 - 1) / n);
  const int invRoot = power(root, 998244353 - 2);
  vector<int> precompw;
  int curw = inv ? root : invRoot;
  for (;;) {
    precompw.push_back(curw);
    curw = (((long long int)curw) * curw) % 998244353;
    if (curw == 1) break;
  }
  for (int len = 2; len <= n; len <<= 1) {
    int w = precompw.back();
    precompw.pop_back();
    for (int i = 0; i < n; i += len) {
      int curw = 1;
      for (int j = 0; j < len / 2; j++) {
        int k = i + j;
        int x = p[k];
        int y = (((long long int)p[k + len / 2]) * curw) % 998244353;
        int tmp1 = x + y;
        int tmp2 = x - y;
        p[k] = tmp1 < 998244353 ? tmp1 : tmp1 - 998244353;
        p[k + len / 2] = tmp2 >= 0 ? tmp2 : tmp2 + 998244353;
        curw = (((long long int)w) * curw) % 998244353;
      }
    }
  }
  if (inv) {
    int invOfN = power(n, 998244353 - 2);
    for (int i = 0; i < n; i++) {
      p[i] = (((long long int)p[i]) * invOfN) % 998244353;
    }
  }
}
vector<int> mult(vector<int> a, vector<int> b) {
  int n1 = a.size();
  int n2 = b.size();
  int tmp = max(n1, n2);
  int n = 1;
  while (n < tmp) n <<= 1;
  n <<= 1;
  a.resize(n, 0);
  b.resize(n, 0);
  ntt(a, false);
  ntt(b, false);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = (((long long int)a[i]) * b[i]) % 998244353;
  }
  ntt(c, true);
  return c;
}
void solve(int ttt) {
  int n;
  cin >> n;
  vector<int> deg(n, 0);
  for (long long int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++;
    deg[b]++;
  }
  priority_queue<pair<int, vector<int> *>> pq;
  vector<int> *root = new vector<int>({deg[0], 1});
  pq.push(make_pair(-2, root));
  for (int i = 1; i < n; i++) {
    vector<int> *tmp = new vector<int>({deg[i] - 1, 1});
    pq.push(make_pair(-2, tmp));
  }
  while (pq.size() > 1) {
    auto tmp1 = pq.top();
    pq.pop();
    auto tmp2 = pq.top();
    pq.pop();
    vector<int> *c = new vector<int>(mult(*(tmp1.second), *(tmp2.second)));
    pq.push(make_pair(tmp1.first + tmp2.first, c));
    delete tmp1.second;
    delete tmp2.second;
  }
  long long int res = 0;
  vector<int> ans = *(pq.top().second);
  vector<long long int> fact(n + 1);
  fact[0] = 1;
  for (long long int i = 0; i < n; i++) {
    fact[i + 1] = (fact[i] * (i + 1)) % 998244353;
  }
  for (int i = 0; i <= n; i++) {
    int c = (i & 1) ^ (n & 1);
    if (!c) {
      res += (fact[i] * ans[i]) % 998244353;
    } else
      res -= (fact[i] * ans[i]) % 998244353;
  }
  cout << (res % 998244353 + 998244353) % 998244353 << "\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  for (long long int i = 0; i < ttt; i++) solve(i);
}

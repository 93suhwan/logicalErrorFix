#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long N = 1e6 + 5;
const long long M = 1e9 + 7;
const long long INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3fll;
const double pi = acos(-1.0);
long long read() {
  long long a = 0;
  long long d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
bool num[N];
long long mi[N];
long long prime[N];
long long cnt;
long long lft[N];
long long a[N];
char sen[N];
vector<long long> q[N];
void init() {
  num[0] = num[1] = true;
  for (long long i = 2; i < N; i++) {
    if (!num[i]) {
      prime[cnt++] = i;
      mi[i] = i;
    }
    for (long long j = 0; j < cnt && prime[j] * i < N; j++) {
      num[prime[j] * i] = true;
      mi[prime[j] * i] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
}
void add(long long i) {
  lft[i] = i;
  long long x = a[i];
  while (x != 1) {
    long long y = mi[x];
    q[y].push_back(i);
    x /= y;
  }
}
void del(long long i) {
  lft[i] = i;
  long long x = a[i];
  while (x != 1) {
    long long y = mi[x];
    if (q[y].empty())
      lft[i] = 0;
    else {
      lft[i] = min(lft[i], q[y].back());
      q[y].pop_back();
    }
    x /= y;
  }
}
signed main() {
  init();
  long long n = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  scanf("%s", sen + 1);
  for (long long i = 1; i <= n; i++) {
    if (sen[i] == '*')
      add(i);
    else
      del(i);
  }
  long long ans = 0;
  stack<long long> stk;
  stk.push(n + 1);
  lft[n + 1] = 0;
  for (long long i = n; i >= 1; i--) {
    while (!stk.empty() && lft[stk.top()] >= lft[i]) stk.pop();
    if (lft[i] == i) ans += stk.top() - i;
    stk.push(i);
  }
  cout << ans;
  return 0;
}

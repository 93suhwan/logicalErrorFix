#include <bits/stdc++.h>
const int N = 1000005;
int n, t;
inline void read(int &x) {
  register char ch = 0;
  register bool w = 0;
  for (x = 0; !std::isdigit(ch); w |= ch == '-', ch = getchar())
    ;
  for (; std::isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  (w) && (x = -x);
  return;
}
bool not_prime[N + 5];
int prime[N], count, minp[N + 5];
void init() {
  not_prime[1] = 1;
  for (int i = 2; i <= N; ++i) {
    if (!not_prime[i]) prime[++count] = i, minp[i] = i;
    for (int j = 1; j <= count && i * prime[j] <= N; ++j) {
      register int tmp = i * prime[j];
      not_prime[tmp] = 1;
      minp[tmp] = prime[j];
      if (!(i % prime[j])) break;
    }
  }
}
char ch[N];
int ai[N], nxt[N], top;
std::vector<int> stk[N];
void add(int val, int loc) {
  while (val > 1) {
    int now = minp[val];
    val /= minp[val];
    stk[now].push_back(loc);
  }
  nxt[loc] = loc;
}
void del(int val, int loc) {
  nxt[loc] = loc;
  while (val > 1) {
    int now = minp[val];
    val /= minp[val];
    if (stk[now].empty()) {
      nxt[loc] = 0;
      break;
    }
    nxt[loc] = std::min(nxt[loc], stk[now].back());
    stk[now].pop_back();
  }
}
int main() {
  init();
  read(n);
  for (int i = 1; i <= n; ++i) read(ai[i]);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; ++i) {
    if (ch[i] == '*')
      add(ai[i], i);
    else
      del(ai[i], i);
  }
  static std::pair<int, int> S[N];
  long long ans = 0;
  for (int i = n; i >= 1; --i) {
    while (top && S[top].first >= i) --top;
    if (nxt[i] < i) {
      while (top && S[top].first >= nxt[i]) --top;
      if (nxt[i] < i) S[++top] = std::make_pair(nxt[i], i);
      continue;
    }
    int loc = 0;
    if (top)
      loc = S[top].second - 1;
    else
      loc = n;
    if (loc >= i) ans += loc - i + 1;
  }
  printf("%lld\n", ans);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = false;
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  if (f) x = -x;
}
template <typename T, typename... Arg>
inline void read(T &x, Arg &...args) {
  read(x);
  read(args...);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 1e6 + 100;
int n, a[N];
char c[N];
int pr[N];
vector<int> v[N];
stack<int> s;
signed main() {
  for (int i = 2; i < N; i++)
    if (!pr[i])
      for (int j = 1; i * j < N; j++) pr[i * j] = i;
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  fgets(c + 1, 998244353, stdin);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    s.push(i);
    while (a[i] > 1) {
      int j = pr[a[i]];
      a[i] /= j;
      if (c[i] == '*')
        v[j].push_back(i);
      else {
        while (s.size() && (!v[j].size() || s.top() > v[j].back())) s.pop();
        if (v[j].size()) v[j].pop_back();
      }
    }
    ans += s.size();
  }
  write(ans);
}

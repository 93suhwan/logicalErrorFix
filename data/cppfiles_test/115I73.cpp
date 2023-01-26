#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long P = 998244353LL;
int n, m, qn;
namespace Fread {
const int L = 1 << 15;
char buffer[L], *S, *T;
inline char Getchar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T) return EOF;
  }
  return *S++;
}
template <class T>
inline void read(T &X) {
  char ch;
  T op = 1;
  for (ch = Getchar(); ch > '9' || ch < '0'; ch = Getchar())
    if (ch == '-') op = -1;
  for (X = 0; ch >= '0' && ch <= '9'; ch = Getchar())
    X = (X << 1) + (X << 3) + ch - '0';
  X *= op;
}
}  // namespace Fread
using Fread::read;
namespace Sub1 {
int s[2][2], cnt, con[2][2];
vector<vector<int>> ans;
inline void prework() {
  for (int a = 0; a < 2; a++)
    for (int b = 0; b < 2; b++)
      for (int c = 0; c < 2; c++)
        for (int d = 0; d < 2; d++)
          if (a + b + c + d == 2) {
            vector<int> cur = {a, b, c, d};
            ans.emplace_back(cur);
          }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) s[i][j] = -1;
}
inline bool chkSingle(int x, int y, int c) {
  assert(c != -1);
  if (s[x][y] == -1)
    return true;
  else
    return s[x][y] == c;
}
inline bool chk(int a, int b, int c, int d) {
  return chkSingle(0, 0, a) && chkSingle(0, 1, b) && chkSingle(1, 0, c) &&
         chkSingle(1, 1, d);
}
inline int calc() {
  if (cnt >= 1) return 0;
  int res = 0;
  for (int i = 0; i < ans.size(); i++) {
    if (chk(ans[i][0], ans[i][1], ans[i][2], ans[i][3])) ++res;
  }
  return res;
}
inline void solve() {
  prework();
  for (int x, y, c; qn--;) {
    read(x), read(y), read(c);
    --x, --y;
    s[x][y] = c;
    printf("%d\n", calc());
  }
}
}  // namespace Sub1
namespace Sub2 {
int conCnt, limCnt;
long long bin[N];
bool rev = false;
set<int> s[N][2];
inline void prework() {
  bin[0] = 1;
  for (int i = 1; i <= n + 1; i++) bin[i] = bin[i - 1] * 2LL % P;
}
inline int get(int x, int y) {
  set<int>::iterator it = s[y][0].find(x);
  if (it != s[y][0].end()) return 0;
  it = s[y][1].find(x);
  if (it != s[y][1].end()) return 1;
  return -1;
}
inline pair<int, int> state(int y) {
  if (s[y][0].empty() && s[y][1].empty())
    return pair<int, int>(0, 0);
  else if (!s[y][0].empty() && !s[y][1].empty())
    return pair<int, int>(0, 1);
  else
    return pair<int, int>(1, 0);
}
inline void ins(int x, int y, int c) {
  assert(get(x, y) == -1);
  assert(c != -1);
  if (!(x & 1)) c ^= 1;
  pair<int, int> st = state(y);
  limCnt -= st.first, conCnt -= st.second;
  s[y][c].insert(x);
  st = state(y);
  limCnt += st.first, conCnt += st.second;
}
inline void del(int x, int y) {
  int val = get(x, y);
  assert(val != -1);
  pair<int, int> st = state(y);
  limCnt -= st.first, conCnt -= st.second;
  s[y][val].erase(x);
  st = state(y);
  limCnt += st.first, conCnt += st.second;
}
inline void clear(int x, int y) {
  for (; !s[y][0].empty();) {
    int cur = *s[y][0].begin();
    del(cur, y);
  }
  for (; !s[y][1].empty();) {
    int cur = *s[y][1].begin();
    del(cur, y);
  }
}
inline void modify(int x, int y, int c) {
  int cur = get(x, y);
  if (cur != -1) del(x, y);
  ins(x, y, c);
}
inline long long query() {
  if (conCnt >= 1)
    return 0LL;
  else {
    if (limCnt == 0)
      return (bin[n + 1] - 2 + P) % P;
    else
      return (bin[n - limCnt + 1] - 1 + P) % P;
  }
}
inline void solve() {
  if (n < m) {
    rev = 1;
    swap(n, m);
  }
  prework();
  for (int x, y, c; qn--;) {
    read(x), read(y), read(c);
    if (rev) swap(x, y);
    if (c == -1)
      clear(x, y);
    else
      modify(x, y, c);
    printf("%lld\n", query());
  }
}
}  // namespace Sub2
int main() {
  read(n), read(m), read(qn);
  if (n == 2 && m == 2)
    Sub1::solve();
  else
    Sub2::solve();
  return 0;
}

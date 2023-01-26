#include <bits/stdc++.h>
using namespace std;
int pr[1000005], ct;
int np[1000005];
void prep() {
  for (int i = 2; i <= 1000000; i++) {
    if (!np[i]) pr[++ct] = i, np[i] = i;
    for (int j = 1; j <= ct && i * pr[j] <= 1000000; j++) {
      np[i * pr[j]] = pr[j];
      if (i % pr[j] == 0) break;
    }
  }
}
int n, m;
int CO[1000005];
inline void Read(int &s) {
  char ch = getchar();
  s = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9')
    s = (ch & 15) + (s << 1) + (s << 3), ch = getchar();
}
void reads() {
  char ch = getchar();
  while (ch != '/' && ch != '*') ch = getchar();
  for (int i = 1; i <= n; i++) CO[i] = (ch == '*' ? 1 : -1), ch = getchar();
}
int LG[1000005];
struct seg {
  int l, r;
} A[1000005];
int V[1000005];
struct node {
  int pos, val;
};
vector<node> P[1000005];
int S[1000005];
vector<int> AD[1000005];
vector<int> DL[1000005];
int sc[1000005], sp;
void work(vector<node> &W, int pi) {
  m = 0;
  if (W[0].pos != 1) A[++m] = (seg){1, W[0].pos - 1}, V[m] = 0;
  for (int i = 0, ed = W.size(); i < ed; i++) {
    node t = W[i];
    A[++m] = (seg){t.pos, t.pos}, V[m] = t.val * CO[t.pos];
    if (i + 1 == ed) {
      if (t.pos < n) A[++m] = (seg){t.pos + 1, n}, V[m] = 0;
    } else if (t.pos + 1 < W[i + 1].pos)
      A[++m] = (seg){t.pos + 1, W[i + 1].pos - 1}, V[m] = 0;
  }
  for (int i = 1; i <= m; i++) S[i] = S[i - 1] + V[i];
  S[m + 1] = -1e9;
  sc[sp = 1] = m + 1;
  for (int i = m; i >= 1; i--) {
    int si = S[i];
    while (sp && si <= S[sc[sp]]) sp--;
    AD[A[i].l].push_back(A[sc[sp] - 1].r);
    DL[A[i].r].push_back(A[sc[sp] - 1].r);
    sc[++sp] = i;
  }
}
struct heap {
  int tr[1000005], size;
  inline void push(int p) {
    tr[++size] = p;
    p = size;
    while (p > 1 && tr[p] < tr[p >> 1]) swap(tr[p], tr[p >> 1]), p >>= 1;
  }
  inline void pop() {
    tr[1] = tr[size--];
    int p = 1;
    while ((p << 1) <= size) {
      if ((p << 1 | 1) <= size) {
        if (tr[p << 1] < tr[p << 1 | 1]) {
          if (tr[p << 1] < tr[p])
            swap(tr[p << 1], tr[p]), p <<= 1;
          else
            return;
        } else {
          if (tr[p << 1 | 1] < tr[p])
            swap(tr[p << 1 | 1], tr[p]), p = p << 1 | 1;
          else
            return;
        }
      } else {
        if (tr[p << 1] < tr[p])
          swap(tr[p << 1], tr[p]), p <<= 1;
        else
          return;
      }
    }
  }
  int top() { return tr[1]; }
} HP;
int js[1000005];
bool inh[1000005];
int to[1000005];
int ori[1000005];
void solve() {
  for (int i = 1; i <= n; i++) {
    for (int j = 0, ed = AD[i].size(); j < ed; j++) {
      int t = AD[i][j];
      if (!js[t]) {
        if (!inh[t]) HP.push(t);
        ++js[t];
      } else
        ++js[t];
    }
    to[i] = HP.top();
    if (CO[i] == -1 && ori[i] > 1) to[i] = i - 1;
    for (int j = 0, ed = DL[i].size(); j < ed; j++) {
      int t = DL[i][j];
      js[t]--;
    }
    while (HP.size && !js[HP.top()]) inh[HP.top()] = 0, HP.pop();
  }
}
int main() {
  prep();
  Read(n);
  LG[0] = -1;
  for (int i = 1; i <= n; i++) LG[i] = LG[i >> 1] + 1;
  for (int i = 1, x, y, z; i <= n; i++) {
    Read(x);
    y = 0;
    ori[i] = x;
    while (x > 1) {
      z = np[x];
      while (x % z == 0) {
        ++y;
        x /= z;
      }
      P[z].push_back((node){i, y});
    }
  }
  reads();
  for (int i = 2; i <= 1000000; i++)
    if (P[i].size()) work(P[i], i);
  solve();
  long long Ans = 0;
  for (int i = 1; i <= n; i++) Ans += to[i] - i + 1;
  cout << Ans << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using namespace std;
inline int read() {
  char ch;
  bool sign = 0;
  int res = 0;
  while (!isdigit(ch = getchar()))
    if (ch == '-') sign = 1;
  while (isdigit(ch)) res = res * 10 + (ch ^ 48), ch = getchar();
  if (sign)
    return -res;
  else
    return res;
}
const int maxn = 200000 + 10;
const int maxm = 450;
const int mod = 998244353;
const int inf = 1e5;
int n, m, X[maxn], Y[maxn];
int op[maxn], k[maxn];
int addv[maxn];
int A[maxn], Mod[maxm][maxm];
vector<int> a[maxn];
int start[maxn];
inline void solve() {
  for (int i = (0); i < (m); ++i) {
    int len = X[k[i]] + Y[k[i]];
    if (len > maxm && op[i] == 1) {
      a[k[i]].pop_back();
      int last = a[k[i]].back();
      a[k[i]].pop_back();
      int j = i + X[k[i]];
      for (; j < last; j += len) {
        addv[j]++;
        addv[min(j + Y[k[i]], last)]--;
      }
    }
    if (len <= maxm) {
      if (op[i] == 1) {
        int j = i + X[k[i]];
        start[k[i]] = j;
        for (int c = (0); c < (Y[k[i]]); ++c) {
          Mod[(j + c) % len][len - 1]++;
        }
      } else {
        for (int c = (0); c < (Y[k[i]]); ++c) {
          Mod[(start[k[i]] + c) % len][len - 1]--;
        }
      }
    }
    for (int j = (2); j <= (maxm); ++j) {
      A[i] += Mod[i % j][j - 1];
    }
  }
  for (int i = (0); i < (m); ++i) {
    if (i) addv[i] += addv[i - 1];
    printf("%d\n", A[i] + addv[i]);
  }
}
int main(void) {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); ++i) scanf("%d", &(X[i])), scanf("%d", &(Y[i]));
  for (int i = (0); i < (m); ++i) {
    scanf("%d", &(op[i])), scanf("%d", &(k[i]));
    k[i]--;
    a[k[i]].push_back(i);
  }
  for (int i = (0); i < (n); ++i) {
    if (((int)(a[i]).size()) & 1) a[i].push_back(m);
    reverse((a[i]).begin(), (a[i]).end());
  }
  solve();
  return 0;
}

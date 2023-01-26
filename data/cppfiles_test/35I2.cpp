#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, a[N], pri[N], f[N], stk[N], top, lst[N];
char s[N];
long long ans;
void init() {
  for (int i = 2; i < N; ++i) {
    if (!pri[i]) pri[i] = i;
    if (i > 1000) continue;
    for (int j = i * i; j < N; j += i) pri[j] = i;
  }
}
vector<int> st[N];
void insert(int pos, int val) {
  lst[pos] = pos;
  while (val > 1) {
    st[pri[val]].push_back(pos);
    val = val / pri[val];
  }
}
void del(int pos, int val) {
  if (val == 1) {
    lst[pos] = pos;
    return;
  }
  int Min = 1e9;
  while (val) {
    int tmp = pri[val];
    if (!st[tmp].size()) {
      lst[pos] = 0;
      return;
    }
    Min = min(Min, st[tmp].back());
    st[tmp].pop_back();
    val = val / pri[val];
  }
  lst[pos] = Min;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> s + 1;
  init();
  for (int i = 1; i <= n; ++i) {
    if (s[i] == '*')
      insert(i, a[i]);
    else
      del(i, a[i]);
  }
  for (int i = n; i >= 1; --i) {
    int cnt = 1;
    while (top && lst[stk[top]] >= lst[i]) {
      cnt += f[stk[top]];
      top--;
    }
    f[i] = cnt, stk[++top] = i;
    if (lst[i] == i) ans += f[i];
  }
  cout << ans << endl;
  return 0;
}

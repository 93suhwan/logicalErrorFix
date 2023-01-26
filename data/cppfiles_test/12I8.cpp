#include <bits/stdc++.h>
template <typename T>
bool chkmin(T &a, T b) {
  return (b < a) ? a = b, 1 : 0;
}
template <typename T>
bool chkmax(T &a, T b) {
  return (b > a) ? a = b, 1 : 0;
}
long long ksm(long long a, long long b) {
  if (b == 0) return 1;
  long long ns = ksm(a, b >> 1);
  ns = ns * ns % 1000000007;
  if (b & 1) ns = ns * a % 1000000007;
  return ns;
}
using namespace std;
const int maxn = 2005;
char s[maxn][maxn];
int nr[maxn][maxn];
long long ans = 0;
int st[maxn];
vector<int> calc(vector<int> a) {
  auto chk = [&](int i, int j) { return a[i] + 1ll * (j - i) * (j - i); };
  auto ins = [&](int i, int j, int k) {
    long long cur =
        1ll * (j - i) * (a[k] - a[j]) - 1ll * (k - j) * (a[j] - a[i]);
    return cur;
  };
  int fr = 0, ed = 0;
  vector<int> res(a.size());
  for (int i = 0; i < a.size(); i++) {
    while (ed - fr >= 2 && ins(st[ed - 2], st[ed - 1], i) <= 0) ed--;
    st[ed++] = i;
    while (ed - fr >= 2 && chk(st[fr + 1], i) <= chk(st[fr], i)) fr++;
    res[i] = chk(st[fr], i);
  }
  return res;
}
void upd(vector<int> a) {
  vector<int> t = calc(a);
  reverse(a.begin(), a.end());
  vector<int> s = calc(a);
  reverse(s.begin(), s.end());
  for (int i = 0; i < t.size(); i++) {
    chkmin(t[i], s[i]);
    ans += t[i];
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i <= n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j <= m; j++) {
      if (s[i][j] == '0')
        nr[i][j] = maxn * 2;
      else
        nr[i][j] = 0;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) chkmin(nr[i][j], nr[i][j - 1] + 1);
    for (int j = m - 1; j >= 0; j--) chkmin(nr[i][j], nr[i][j + 1] + 1);
  }
  for (int j = 0; j <= m; j++) {
    vector<int> cur(n + 1);
    for (int i = 0; i <= n; i++) cur[i] = 1ll * nr[i][j] * nr[i][j];
    upd(cur);
  }
  cout << ans << endl;
  return (0 - 0);
}

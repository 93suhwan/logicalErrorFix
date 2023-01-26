#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int MAXN = 5e5 + 5;
const long long mod = 1e9 + 7;
string ans[100005];
const int INF = 0x3f3f3f3f;
int dp[MAXN][2];
int t, n, a[MAXN], b[MAXN], p[MAXN];
long long find(long long x) {
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}
bool cmp(int x, int y) { return x > y; }
int sum[MAXN];
long long ar[MAXN];
pair<pair<int, int>, pair<int, int>> pr[MAXN];
vector<string> vc;
string Ppush(int i) {
  long long pr = pow(2, i);
  return to_string(pr);
}
int answer(string n1, string n2) {
  int si1 = n1.size(), si2 = n2.size();
  int i = 0, j = 0;
  int cnt = 0;
  while (i < si1 && j < si2) {
    if (n1[i] == n2[j]) {
      i++;
      j++;
    } else {
      j++;
      cnt++;
    }
  }
  cnt += si1 - i;
  cnt += si2 - j;
  return cnt;
}
void solve() {
  int k;
  scanf("%d", &k);
  int cnt = 0;
  int ans = 1e9;
  string tt = to_string(k);
  for (int i = 0; i < 63; i++) {
    ans = min(ans, answer(vc[i], tt));
  }
  printf("%d\n", ans);
}
int main() {
  for (int i = 0; i < 63; i++) {
    vc.push_back(Ppush(i));
  }
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

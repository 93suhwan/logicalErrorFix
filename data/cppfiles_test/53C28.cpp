#include <bits/stdc++.h>
const double eps = 1e-15;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
using namespace std;
vector<int> v[101];
int vis[maxn], n;
char s[maxn], p;
void solve() {
  set<int> st;
  scanf("%d", &n);
  getchar(), p = getchar();
  scanf("%s", s + 1);
  int ok = 1;
  for (int i = 1; i <= n; i++)
    if (s[i] != p) ok = 0;
  if (ok) return void(puts("0"));
  if (s[n] == p) {
    cout << 1 << endl << n << endl;
    return;
  }
  int len = n / 2 + 1;
  for (int i = len; i < n; i++) {
    if (s[i] == p) {
      printf("1 %d\n", i);
      return;
    }
  }
  cout << 2 << endl << n - 1 << " " << n << endl;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}

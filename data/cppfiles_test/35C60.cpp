#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n, top, mx;
long long ans;
int a[maxn], stk[maxn];
vector<int> p[maxn], v[maxn];
string s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), mx = max(mx, a[i]);
  for (int i = 2; i <= mx; i++)
    if (v[i].empty())
      for (int j = i; j <= mx; j += i) {
        int k = j;
        while (k % i == 0) k /= i, v[j].push_back(i);
      }
  cin >> s, s = " " + s;
  for (int i = 1; i <= n; i++) {
    stk[++top] = i;
    if (s[i] == '*')
      for (int j = 0; j < v[a[i]].size(); j++) p[v[a[i]][j]].push_back(i);
    if (s[i] == '/')
      for (int j = 0; j < v[a[i]].size(); j++) {
        if (p[v[a[i]][j]].size() == 0) {
          top = 0;
          break;
        }
        while (top && stk[top] > p[v[a[i]][j]].back()) top--;
        p[v[a[i]][j]].pop_back();
      }
    ans += top;
  }
  printf("%lld\n", ans);
  return 0;
}

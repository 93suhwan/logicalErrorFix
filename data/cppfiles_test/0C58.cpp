#include <bits/stdc++.h>
using namespace std;
pair<string, int> str[1000005];
bool cmp(const pair<string, int> &p, const pair<string, int> &q) {
  for (int i = 0; i < p.first.size(); i++) {
    if (p.first[i] != q.first[i]) {
      if (i % 2 == 0)
        return p.first[i] < q.first[i];
      else
        return p.first[i] > q.first[i];
    }
  }
  return false;
}
void solve() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    char c[1000005];
    scanf("%s", c);
    str[i] = make_pair(string(c), i);
  }
  sort(str, str + n, cmp);
  for (int i = 0; i < n; i++) printf("%d ", str[i].second + 1);
}
int main() {
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}

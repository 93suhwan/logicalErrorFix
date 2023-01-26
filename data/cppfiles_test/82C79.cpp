#include <bits/stdc++.h>
using namespace std;
const int oo = 3e5 + 7;
unordered_map<int, vector<int>> values[2];
int t, n, q, a[oo], p[oo];
vector<int> ans;
int psum(int l, int r) { return p[r] - (l ? p[l - 1] : 0); }
int first(vector<int>& list, int val) {
  int l = 0, r = list.size();
  while (l < r) {
    int s = (l + r) / 2;
    if (list[s] >= val)
      r = s;
    else
      l = s + 1;
  }
  if (l == list.size()) return n * 2;
  return list[l];
}
void problem(int l, int r) {
  int sum = psum(l, r);
  if (sum == 0) return;
  if (sum % 2 == 0) {
    ans.push_back(r);
    problem(l, r - 1);
    return;
  }
  int pl = p[l] - a[l];
  int vals[2] = {pl + (sum + 1) / 2 - 1, pl + (sum - 1) / 2 + 1};
  for (int i = 0; i < 2; i++) {
    int pans = first(values[i][vals[i]], l);
    if (pans <= r) {
      ans.push_back(pans);
      return;
    }
  }
  throw 69;
}
char ss[oo];
void solve() {
  scanf("%d%d", &n, &q);
  scanf("%s", ss);
  for (int i = 0; i < n; i++)
    a[i] = (ss[i] == '+' ? 1 : -1) * (i % 2 == 0 ? -1 : 1);
  p[0] = a[0];
  for (int i = 1; i < n; i++) p[i] = p[i - 1] + a[i];
  for (int i = 0; i < n; i++) values[(a[i] + 1) / 2][p[i]].push_back(i);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    problem(l, r);
    printf("%d\n", ans.size());
    for (int e : ans) printf("%d ", e + 1);
    printf("\n");
    ans.clear();
  }
  values[0].clear();
  values[1].clear();
}
int main() {
  scanf("%d", &t);
  while (t--) solve();
}

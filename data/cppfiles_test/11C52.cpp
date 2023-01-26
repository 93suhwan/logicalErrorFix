#include <bits/stdc++.h>
using namespace std;
int n, ans, tmp;
vector<int> v[200005];
map<int, int> x[800005];
int f1(int a, int b, int l, int r, int i) {
  if (a == l && b == r) {
    auto it = x[i].upper_bound(tmp);
    if (it == x[i].begin()) return 0;
    it--;
    return it->second;
  }
  int mi = (l + r) / 2;
  if (b <= mi) return f1(a, b, l, mi, i * 2);
  if (a >= mi) return f1(a, b, mi, r, i * 2 + 1);
  return max(f1(a, mi, l, mi, i * 2), f1(mi, b, mi, r, i * 2 + 1));
}
void f2(int a, int b, int l, int r, int i) {
  bool g = 0;
  auto it = x[i].lower_bound(tmp);
  if (it != x[i].begin()) {
    it--;
    if (it->second >= b) g = 1;
    it++;
  }
  if (it != x[i].end() && it->first == tmp && it->second >= b) g = 1;
  if (!g) {
    auto ib = it;
    while (ib != x[i].end() && b >= ib->second) ib++;
    if (it != ib) it = x[i].erase(it, ib);
    x[i].insert(it, {tmp, b});
  }
  if (a == l && a + 1 == r) return;
  int mi = (l + r) / 2;
  if (a < mi)
    f2(a, b, l, mi, i * 2);
  else
    f2(a, b, mi, r, i * 2 + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int ttmp;
    scanf("%d", &ttmp);
    v[ttmp].push_back(i);
  }
  for (int i = 1; i <= 200000; i++) {
    reverse(v[i].begin(), v[i].end());
    for (int j : v[i]) {
      if (j < i - 1) break;
      tmp = j - i + 1;
      int add = j ? f1(0, j, 0, n, 1) + 1 : 1;
      ans = max(ans, add);
      f2(j, add, 0, n, 1);
    }
  }
  printf("%d\n", ans);
}

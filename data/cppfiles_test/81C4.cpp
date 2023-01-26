#include <bits/stdc++.h>
using namespace std;
struct ura {
  int a, b;
};
bool cmp(ura a, ura b) {
  if (max(a.a, a.b) == max(b.a, b.b)) return min(a.a, a.b) < min(b.a, b.b);
  return max(a.a, a.b) < max(b.a, b.b);
}
ura v[500005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int m, q, t, s = 0, n, d, i, k;
  cin >> n >> d;
  for (i = 1; i <= n; ++i) cin >> v[i].a >> v[i].b;
  sort(v + 1, v + n + 1, cmp);
  for (i = 1; i <= n; ++i) {
    if (d <= v[i].a) {
      ++s;
      d = max(d, v[i].b);
    }
  }
  cout << s;
  return 0;
}

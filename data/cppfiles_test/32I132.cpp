#include <bits/stdc++.h>
using namespace std;
struct bala {
  int val, pot, num;
} la, p;
int n, a, maxx, v[8200], ans, f[8200][5001];
vector<int> vec[5001];
queue<bala> q;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a);
    vec[a].push_back(i);
    maxx = max(maxx, a);
    if (v[a] == 0) {
      v[a] = 1, ans++;
      p.pot = i;
      p.num = p.val = a;
      q.push(p);
    }
  }
  while (q.size()) {
    p = q.front();
    q.pop();
    for (int i = 1; i <= maxx; i++) {
      if (i <= p.num) continue;
      int poi =
          lower_bound(vec[i].begin(), vec[i].end(), p.pot) - vec[i].begin();
      if (poi == vec[i].size()) continue;
      la.val = p.val ^ i;
      la.pot = vec[i][poi];
      la.num = i;
      q.push(la);
      if (v[la.val] == 0) v[la.val] = 1, ans++;
    }
  }
  if (!v[0]) {
    v[0] = 1;
    ans++;
  }
  cout << ans << endl;
  for (int i = 0; i <= 8199; i++) {
    if (v[i]) printf("%d ", i);
  }
}

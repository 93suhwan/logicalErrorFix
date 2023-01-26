#include <bits/stdc++.h>
using namespace std;
int read() {
  char c;
  int w = 1;
  while ((c = getchar()) > '9' || c < '0')
    if (c == '-') w = -1;
  int ans = c - '0';
  while ((c = getchar()) >= '0' && c <= '9')
    ans = (ans << 1) + (ans << 3) + c - '0';
  return ans * w;
}
int n, m, k;
vector<int> shu, hang;
map<int, int> s, h;
const int xx = 6e5 + 5;
struct nod {
  int x, y;
} e0[xx], e1[xx];
bool cmp1(nod x, nod y) { return x.x < y.x; }
bool cmp2(nod x, nod y) { return x.y < y.y; }
map<int, int> mp;
int main() {
  int T = read();
  while (T--) {
    s.clear(), h.clear();
    shu.clear(), hang.clear();
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) shu.push_back(read()), s[shu[i - 1]] = 1;
    sort(shu.begin(), shu.end());
    for (int i = 1; i <= m; i++) hang.push_back(read()), h[hang[i - 1]] = 1;
    sort(hang.begin(), hang.end());
    int tot0 = 0, tot1 = 0;
    for (int i = 1; i <= k; i++) {
      int x = read(), y = read();
      if (s.find(x) != s.end() && h.find(y) != h.end()) continue;
      if (h.find(y) != h.end())
        e0[++tot0].x = x, e0[tot0].y = y;
      else
        e1[++tot1].x = x, e1[tot1].y = y;
    }
    sort(e0 + 1, e0 + tot0 + 1, cmp1);
    int l = 1, tshu = -1;
    long long ans = 0, sum = 0;
    mp.clear();
    for (int i = 1; i <= tot0; i++) {
      mp[e0[i].y]++;
      sum++;
      while (tshu + 1 < shu.size() && shu[tshu + 1] < e0[i].x) tshu++;
      if (tshu != -1) {
        while (l < i && e0[l].x < shu[tshu]) mp[e0[l].y]--, l++, sum--;
      }
      ans += sum - mp[e0[i].y];
    }
    sum = 0;
    int thang = -1;
    l = 1;
    sort(e1 + 1, e1 + tot1 + 1, cmp2);
    mp.clear();
    for (int i = 1; i <= tot1; i++) {
      mp[e1[i].x]++;
      sum++;
      while (thang + 1 < hang.size() && hang[thang + 1] < e1[i].y) thang++;
      if (thang != -1) {
        while (l < i && e1[l].y < hang[thang]) mp[e1[l].x]--, l++, sum--;
      }
      ans += sum - mp[e1[i].x];
    }
    cout << ans << "\n";
  }
  return 0;
}

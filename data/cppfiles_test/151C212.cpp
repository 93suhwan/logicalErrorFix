#include <bits/stdc++.h>
using namespace std;
int q;
const int N = 500090;
int pa[N], co[N], ch[N], val[N];
int get(int x) {
  if (pa[x] == x) return x;
  return pa[x] = get(pa[x]);
}
int main() {
  cin >> q;
  int n = 0;
  memset(ch, -1, sizeof ch);
  memset(co, -1, sizeof co);
  for (int i = 0; i < q; i++) {
    int t, x, y;
    cin >> t >> x;
    if (t == 1) {
      if (ch[x] == -1) ch[x] = i;
      pa[i] = ch[x];
      co[i] = x;
      n++;
      val[i] = 1;
      continue;
    }
    cin >> y;
    int z = ch[x];
    if (z == -1) continue;
    ch[x] = -1;
    co[z] = y;
    if (ch[y] != -1) pa[ch[y]] = z;
    ch[y] = z;
  }
  for (int i = 0; i < q; i++) {
    if (val[i] == 0) continue;
    cout << co[get(i)] << " ";
  }
}

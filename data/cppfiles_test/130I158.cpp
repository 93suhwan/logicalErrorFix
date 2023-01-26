#include <bits/stdc++.h>
void qry(int x, int y, int z) {
  std::cout << "? " << x << ' ' << y << ' ' << z << '\n';
  std::cout.flush();
}
void sol() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1, -1), tmp, res(n + 1, -1);
  bool vis[2] = {false, false};
  int imp = -1, crw = -1;
  int flag;
  for (int i = 3; i <= n; ++i) {
    qry(i - 2, i - 1, i);
    std::cin >> a[i];
    if (a[i] == 1)
      imp = i;
    else
      crw = i;
    if (crw != -1 && imp != -1) {
      flag = i;
      break;
    }
  }
  int is0, is1;
  if (imp < crw) {
    is1 = imp - 2;
    is0 = crw;
  } else {
    is1 = imp;
    is0 = crw - 2;
  }
  res[is0] = 0;
  res[is1] = 1;
  int ans = 1;
  for (int i : {1, 2, 3})
    if (res[i] == -1) {
      qry(i, is0, is1);
      std::cin >> res[i];
    }
  int thiz = a[3];
  for (int i : {1, 2, 3}) {
    if (res[i] != thiz) {
      thiz = i;
      break;
    }
  }
  for (int i = (thiz - 1) / 3 * 3; i < flag / 3 * 3; i += 3) {
    for (int now : {i / 3 * 3, i / 3 * 3 + 1, i / 3 * 3 + 2})
      if (now != i) {
        res[i] = a[3];
      }
    a[i] = !a[3];
  }
  for (int i = flag - 2; i <= n; ++i)
    if (i != is0 && i != is1 && res[i] == -1) {
      tmp.push_back(i);
    }
  for (int e : tmp) {
    qry(is0, is1, e);
    std::cin >> res[e];
    if (!res[e]) ++ans;
  }
  std::cout << "! " << ans;
  for (int i = 1; i <= n; ++i) {
    if (!res[i]) std::cout << ' ' << i;
  }
  std::cout << '\n';
  std::cout.flush();
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}

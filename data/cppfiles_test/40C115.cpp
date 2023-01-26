#include <bits/stdc++.h>
int n, m;
std::vector<std::vector<int> > gr;
std::vector<int> par;
std::vector<bool> vis;
std::vector<int> lev;
void dfsgr(int v) {
  vis[v] = true;
  for (auto& ch : (gr[v])) {
    if (vis[ch]) continue;
    lev[ch] = lev[v] + 1;
    par[ch] = v;
    dfsgr(ch);
  }
}
int lca(int a, int b) {
  if (lev[a] > lev[b]) std::swap(a, b);
  while (lev[b] != lev[a]) b = par[b];
  while (a != b) {
    a = par[a];
    b = par[b];
  }
  return a;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> n >> m;
  gr.resize(n);
  vis.resize(n);
  par.resize(n, -1);
  lev.resize(n);
  for (int i = 0; i < (m); ++i) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  dfsgr(0);
  int q;
  std::cin >> q;
  std::vector<int> dd(n);
  std::vector<std::vector<int> > paths;
  for (int _ = 0; _ < (q); ++_) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    int lc = lca(a, b);
    int pos = a;
    std::vector<int> pth;
    while (pos != lc) {
      dd[pos] ^= 1;
      pth.push_back(pos);
      pos = par[pos];
    }
    pth.push_back(lc);
    std::vector<int> nd;
    pos = b;
    while (pos != lc) {
      dd[pos] ^= 1;
      nd.push_back(pos);
      pos = par[pos];
    }
    while (((int)(nd).size())) pth.push_back(nd.back()), nd.pop_back();
    paths.push_back(std::move(pth));
  }
  bool good = true;
  for (int i = 0; i < (n); ++i) {
    if (dd[i]) good = false;
  }
  if (good) {
    std::cout << "YES\n";
    for (auto& p : (paths)) {
      std::cout << ((int)(p).size()) << "\n";
      for (auto& i : (p)) std::cout << i + 1 << " ";
      std::cout << "\n";
    }
  } else {
    std::cout << "NO\n";
    std::vector<std::vector<int> > ed(n);
    for (int i = 0; i < (n); ++i)
      if (dd[i]) {
        ed[i].push_back(par[i]);
        ed[par[i]].push_back(i);
      }
    std::fill(vis.begin(), vis.end(), false);
    int xd = 0;
    std::function<int(int)> dfs = [&](int v) {
      vis[v] = true;
      int mam = 0;
      for (auto& ch : (ed[v]))
        if (!vis[ch]) {
          dfs(ch);
          mam++;
        }
      xd += mam / 2;
      return mam % 2;
    };
    int ans = 0;
    for (int i = 0; i < (n); ++i)
      if (!vis[i]) {
        xd = 0;
        if (dfs(i)) xd++;
        ans += xd;
      }
    std::cout << ans << "\n";
  }
  return 0;
}

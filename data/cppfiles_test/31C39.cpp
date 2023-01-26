#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
using namespace std;
const int INF = 1e9 + 7;
const int mod = 31607;
const int N = 1e6 + 7;
struct przedz {
  int lewy = INF;
  int prawy = -INF;
  int mini = INF;
  int id_lewy = -1;
  int id_prawy = -1;
  int id = -1;
  int dl = 1;
};
przedz merge(przedz lewy, przedz prawy) {
  przedz ret;
  ret.lewy = min(lewy.lewy, lewy.dl + prawy.lewy);
  ret.prawy = max(lewy.prawy, lewy.dl + prawy.prawy);
  ret.mini = min({lewy.mini, prawy.mini, lewy.dl + prawy.lewy - lewy.prawy});
  ret.dl = lewy.dl * 2;
  ret.id_lewy = lewy.id;
  ret.id_prawy = prawy.id;
  ret.id = lewy.id / 2;
  return ret;
}
vector<przedz> tree;
int T, n, k;
int gray(int x) { return x ^ (x >> 1); }
int rev(int x) {
  int ret = 0;
  for (int i = 0; i < k; i++)
    if (x & (1 << i)) ret |= (1 << (k - 1 - i));
  return ret;
}
void solve() {
  cin >> n >> k;
  T = (1 << k);
  tree.resize(T + T);
  vector<int> ans(T);
  vector<int> mam(T);
  vector<int> tab(n);
  for (int i = 0; i < n; i++) {
    cin >> tab[i];
    mam[tab[i]] = true;
  }
  for (int i = 0; i < T; i++) {
    tree[T + i].id = T + i;
    if (mam[i]) {
      tree[T + i].lewy = 0;
      tree[T + i].prawy = 0;
    }
  }
  for (int i = T - 1; i >= 1; i--)
    tree[i] = merge(tree[i * 2], tree[i * 2 + 1]);
  ans[0] = tree[1].mini;
  for (int i = 1; i < T; i++) {
    int bit = gray(i) ^ gray(i - 1);
    for (int j = bit; j < bit * 2; j++) swap(tree[j].id_lewy, tree[j].id_prawy);
    for (int j = bit * 2 - 1; j >= 1; j--) {
      tree[j] = merge(tree[tree[j].id_lewy], tree[tree[j].id_prawy]);
    }
    ans[rev(gray(i))] = tree[1].mini;
  }
  for (auto& u : ans) cout << u << ' ';
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test = 1;
  for (int i = 0; i < test; i++) solve();
}

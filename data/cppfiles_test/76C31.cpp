#include <bits/stdc++.h>
using namespace std;
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<int, int, custom_hash> G[200005];
int n, m, arr[200005];
bool verify(int v[]) {
  int cnt = 0;
  for (int i = 0; i < 5; ++i)
    for (int k = i + 1; k < 5; ++k) cnt += G[v[i]][v[k]];
  if (cnt == 10 || cnt == 0) return true;
  return false;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    G[u][v] = G[v][u] = 1;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) arr[i] = i;
  while (cnt <= 1000000) {
    for (int i = 0; i < 5; ++i) swap(arr[n - i], arr[rng() % (n - i) + 1]);
    int a[5];
    for (int i = 0; i < 5; ++i) a[i] = arr[n - i];
    if (verify(a) == true) {
      for (int i = 0; i < 5; ++i) cout << a[i] << " ";
      return 0;
    }
    ++cnt;
  }
  cout << "-1";
  return 0;
}

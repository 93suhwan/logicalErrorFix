#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
const int A = 200500;
int parent[A];
int rk[A];
int timer[A];
void make_set(int v, int tm) {
  parent[v] = v;
  rk[v] = 0;
  timer[v] = tm;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rk[a] < rk[b]) swap(a, b);
    parent[b] = a;
    if (rk[a] == rk[b]) ++rk[a];
    timer[a] = min(timer[a], timer[b]);
  }
}
int main() {
  int ta;
  scanf("%d", &ta);
  for (int ifa = 0; ifa < ta; ifa++) {
    int n, k;
    scanf("%d %d", &n, &k);
    map<int, std::vector<std::pair<int, int> > > x, y;
    for (int i = 0; i < n; i++) {
      int a, b, tm;
      scanf("%d %d %d", &a, &b, &tm);
      make_set(i, tm);
      x[a].push_back(make_pair(b, i));
      y[b].push_back(make_pair(a, i));
    }
    for (auto v : x) {
      sort((v.second).begin(), (v.second).end());
      for (int i = 1; i < v.second.size(); i++) {
        if (v.second[i].first - v.second[i - 1].first <= k)
          union_sets(v.second[i].second, v.second[i - 1].second);
      }
    }
    for (auto v : y) {
      sort((v.second).begin(), (v.second).end());
      for (int i = 1; i < v.second.size(); i++) {
        if (v.second[i].first - v.second[i - 1].first <= k)
          union_sets(v.second[i].second, v.second[i - 1].second);
      }
    }
    std::vector<int> boom;
    for (int i = 0; i < n; i++)
      if (i == find_set(i)) boom.push_back(timer[i]);
    sort((boom).begin(), (boom).end());
    int ans = boom.size() - 1;
    ans = min(ans, boom.back());
    for (int i = 0; i < boom.size(); i++) {
      ans = min(ans, max((int)boom.size() - i - 2, boom[i]));
    }
    printf("%d\n", ans);
  }
}

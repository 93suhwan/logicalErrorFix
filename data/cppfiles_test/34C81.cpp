#include <bits/stdc++.h>
using namespace std;
std::mt19937 rnd(
    (int)std::chrono::steady_clock::now().time_since_epoch().count());
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 1000000;
const int NBIT = 13;
const int MAXA = 5000;
int n;
int a[MAXN];
vector<int> ans;
int best[1 << NBIT];
vector<int> opt[MAXA + 1];
void solve() {
  for (int i = (0); i < (1 << NBIT); ++i) best[i] = INT_MAX;
  auto relax = [&](int at, int mx) {
    if (mx >= best[at]) return;
    for (int i = (mx + 1); i <= (min(best[at], MAXA)); ++i)
      opt[i].push_back(at);
    best[at] = mx;
  };
  relax(0, -1);
  for (int i = (0); i < (n); ++i) {
    int cur = a[i];
    while (((int)(opt[cur]).size()) > 0) {
      int at = opt[cur].back();
      opt[cur].pop_back();
      assert(best[at] < cur);
      relax(at ^ cur, cur);
    }
  }
  ans.clear();
  for (int i = (0); i < (1 << NBIT); ++i)
    if (best[i] != INT_MAX) ans.push_back(i);
}
void run() {
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d", &a[i]);
  solve();
  printf("%d\n", ((int)(ans).size()));
  for (int i = (0); i < (((int)(ans).size())); ++i) {
    if (i != 0) printf(" ");
    printf("%d", ans[i]);
  }
  puts("");
}
int main() {
  run();
  return 0;
}

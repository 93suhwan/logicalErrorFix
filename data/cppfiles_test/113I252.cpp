#include <bits/stdc++.h>
using namespace std;
int64_t INF64 = int64_t(9e18) + 5;
int INF = int(1e9) + 5;
void solve() {
  int N, M;
  cin >> N;
  vector<int64_t> heroes(N);
  for (auto &h : heroes) cin >> h;
  sort(heroes.begin(), heroes.end());
  int64_t total_power = accumulate(heroes.begin(), heroes.end(), 0L);
  auto binary_search = [&](int64_t target) -> int64_t {
    int L = 0, R = N;
    while (R > L) {
      int64_t mid = L + (R - L) / 2;
      if (heroes[mid] < target)
        L = mid + 1;
      else
        R = mid;
    }
    return L;
  };
  cin >> M;
  while (M-- > 0) {
    int64_t armour, power;
    cin >> armour >> power;
    int idx = binary_search(armour);
    int64_t ans = INF64, rest = 0;
    int64_t coin_need = 0;
    if (idx < N) {
      rest = total_power - heroes[idx];
      coin_need = max(power - rest, (int64_t)0);
      ans = min(ans, coin_need);
    }
    if (idx != 0) {
      rest = total_power - heroes[idx - 1];
      coin_need = max(power - rest, (int64_t)0);
      coin_need += armour - heroes[idx - 1];
      ans = min(ans, coin_need);
    }
    cout << ans << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int tescases = 1;
  while (tescases-- > 0) solve();
}

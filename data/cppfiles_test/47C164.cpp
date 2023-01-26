#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
const int N = 2e5 + 5;
int n, k, x[N];
vector<int> pos, neg;
void solve() {
  cin >> n >> k;
  pos.clear();
  neg.clear();
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    if (x[i] > 0) {
      pos.emplace_back(x[i]);
    } else if (x[i] < 0) {
      neg.emplace_back(x[i]);
    }
  }
  sort(begin(pos), end(pos));
  sort(begin(neg), end(neg), greater<int>());
  ll ans = 0;
  int mx_pos = 0, mx_neg = 0;
  while (!pos.empty()) {
    ans += 2LL * pos.back();
    mx_pos = max(mx_pos, pos.back());
    for (int j = 0; j < k && !pos.empty(); ++j) {
      pos.pop_back();
    }
  }
  while (!neg.empty()) {
    ans -= 2LL * neg.back();
    mx_neg = max(mx_neg, -neg.back());
    for (int j = 0; j < k && !neg.empty(); ++j) {
      neg.pop_back();
    }
  }
  ans -= max(mx_pos, mx_neg);
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}

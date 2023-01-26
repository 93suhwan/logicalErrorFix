#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int inf = 1e9 + 10;
constexpr ll INF = (ll)4e18 + 10;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
template <typename T>
using MaxHeap = priority_queue<T>;
template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
inline bool chmax(T &a, T b) {
  return ((a < b) ? (a = b, true) : (false));
}
template <typename T>
inline bool chmin(T &a, T b) {
  return ((a > b) ? (a = b, true) : (false));
}
void solve() {
  string s;
  cin >> s;
  string t = s;
  reverse((t).begin(), (t).end());
  int num = 0;
  vector<int> cnt(26);
  string order;
  for (auto c : t) {
    if (cnt[c - 'a'] == 0) {
      ++num;
      order += c;
    }
    ++cnt[c - 'a'];
  }
  int n = (int)(order).size(), p = 0;
  for (int i = (0); i < (int)(n); ++i) {
    if (cnt[order[i] - 'a'] % (n - i)) {
      cout << -1 << endl;
      return;
    }
    p += cnt[order[i] - 'a'] / (n - i);
  }
  string start;
  for (int i = (0); i < (int)(p); ++i) start += s[i];
  reverse((order).begin(), (order).end());
  string x, y = start;
  for (int i = (0); i < (int)(num); ++i) {
    x += y;
    string z;
    for (auto c : y) {
      if (c == order[i]) continue;
      z += c;
    }
    y = z;
  }
  if (x != s) {
    cout << -1 << endl;
    return;
  }
  cout << start << " " << order << endl;
  return;
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

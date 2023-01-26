#include <bits/stdc++.h>
using namespace std;
void printi(vector<int> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
void printl(vector<long long> t) {
  for (auto &x : t) cout << x;
  cout << '\n';
}
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int n, m;
pair<long long, long long> a[maxn], range[maxn], b[maxn];
long long sum;
inline long long getinter(pair<long long, long long> x,
                          pair<long long, long long> y) {
  if (y.first <= x.first && x.first <= y.second) return x.first;
  if (y.second <= x.first && x.second <= y.second) return x.second;
  if (x.first <= y.first && y.first <= x.second) return y.first;
  if (x.second <= y.first && y.second <= x.second) return y.second;
}
void solve() {
  cin >> n >> m;
  sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    sum += a[i].second - a[i].first;
    range[i] = {a[i].first >= m ? -m : m - a[i].first * 2,
                a[i].second >= m ? m : a[i].second * 2 - m};
  }
  b[n + 1] = {0, 0};
  for (int i = n; i >= 1; i--)
    b[i] = {b[i + 1].first + range[i].first, b[i + 1].second + range[i].second};
  long long target, nxt;
  if (b[1].first <= sum && sum <= b[1].second)
    target = sum + ((sum + b[1].first) % 2 == 0 ? 0 : 1);
  else
    target = abs(b[1].first - sum) < abs(b[1].second - sum) ? b[1].first
                                                            : b[1].second;
  cout << abs(sum - target) << '\n';
  for (int i = 1; i <= n; i++) {
    pair<long long, long long> t = {target - range[i].second,
                                    target - range[i].first};
    nxt = getinter(t, b[i + 1]);
    cout << (m - (target - nxt)) / 2 << " " << (m + (target - nxt)) / 2 << '\n';
    target = nxt;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}

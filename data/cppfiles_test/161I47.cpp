#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
void print(T &a) {
  for (auto &x : a) cout << x << " ";
  cout << "\n";
}
const int mod = 1e9 + 7;
void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  sort((a).begin(), (a).end(), [&](pair<int, int> p1, pair<int, int> p2) {
    return ((p1.second - p1.first) > (p2.second - p2.first));
  });
  for (int i = 0; i < (n); i++) {
    if (a[i].second == a[i].first) {
      cout << a[i].first << " " << a[i].first << " " << a[i].first << "\n";
      continue;
    }
    int idx = i + 1;
    while (idx < n) {
      if (a[idx].first == a[i].first) break;
      idx++;
    }
    if ((a[idx].first == a[i].first)) {
      cout << a[i] << " " << a[idx].second + 1 << "\n";
      continue;
    }
    idx = i + 1;
    while (idx < n) {
      if (a[idx].second == a[i].second) break;
      idx++;
    }
    if ((a[idx].second == a[i].second)) {
      cout << a[i] << " " << a[idx].first - 1 << "\n";
      continue;
    }
    assert(0);
  }
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  int t = 1, t1 = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop1 - start1);
  return 0;
}

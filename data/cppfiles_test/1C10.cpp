#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long double PI = acos(-1.0);
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<long double, long double>> a;
  cout.precision(15);
  for (int i = 0; i < n; ++i) {
    long long x, y;
    cin >> x >> y;
    if (x == 0 && y == 0) {
      --k;
    } else {
      long double r = sqrt(x * x + y * y);
      long double phi = atan2(y, x);
      a.push_back({r, phi});
    }
  }
  if (k <= 0) {
    cout << "0\n";
    return 0;
  }
  auto solve = [&](long double R) {
    vector<pair<long double, int>> events;
    for (const auto& [d, phi] : a) {
      if (d > 2 * R) {
        continue;
      }
      long double alpha = acos(d / (2 * R));
      events.push_back({phi - alpha, +1});
      events.push_back({phi + alpha, -1});
      events.push_back({2 * PI + phi - alpha, +1});
      events.push_back({2 * PI + phi + alpha, -1});
    }
    sort((events).begin(), (events).end());
    int ans = 0;
    int balance = 0;
    for (auto [x, type] : events) {
      balance += type;
      ans = max(ans, balance);
    }
    return ans;
  };
  double low = 0, high = 3e5, mid;
  for (int it = 0; it < 50; ++it) {
    mid = (low + high) / 2;
    if (solve(mid) < k) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << high << '\n';
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
bool comp1(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first - p1.second > p2.first - p2.second;
}
void swap2(pair<long long, long long> p[], int n) {
  for (int i = 0; i < n; i++) {
    swap(p[i].first, p[i].second);
  }
}
void solve() {
  long long n, m;
  cin >> n >> m;
  pair<long long, long long> p[n];
  long long addX = 0;
  long long addY = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    addX += p[i].first;
    addY += p[i].second;
  }
  int flag = 0;
  if (addX < addY) {
    flag = 1;
    swap2(p, n);
  }
  vector<pair<long long, long long>> v;
  long long store = m;
  for (int i = 0; i < n; i++) {
    m = store;
    long long take = min(m, p[i].first);
    m -= take;
    p[i].first -= take;
    long long take2 = 0;
    if (m > 0) {
      take2 = m;
    }
    p[i].second -= take2;
    v.push_back({take, take2});
  }
  addX = 0;
  addY = 0;
  for (int i = 0; i < n; i++) {
    addX += p[i].first;
    addY += p[i].second;
  }
  long long ans = addX - addY;
  if (ans < 0) {
    for (int i = 0; i < n; i++) {
      long long rem = p[i].second;
      long long canTake = v[i].first;
      long long increase = 2 * min(rem, canTake);
      if (ans + increase <= 1) {
        ans += increase;
        v[i].first -= min(rem, canTake);
        v[i].second += min(rem, canTake);
      } else {
        long long need = (1 - ans) / 2;
        ans += need * 2;
        v[i].first -= need;
        v[i].second += need;
      }
    }
  }
  if (flag) {
    for (int i = 0; i < v.size(); i++) {
      swap(v[i].first, v[i].second);
    }
  }
  cout << abs(ans) << " " << '\n';
  for (int i = 0; i < v.size(); i++) {
    cout << v[i].first << " " << v[i].second << '\n';
    ;
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long tc = 1;
  cin >> tc;
  for (long long i = 1; i <= tc; i++) {
    solve();
  }
}

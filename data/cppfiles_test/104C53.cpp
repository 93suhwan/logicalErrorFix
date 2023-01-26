#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using umii = unordered_map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
inline void __run_test() {
  int n, m;
  cin >> n >> m;
  vpii dishes;
  auto convert = [&](pii x) {
    int take = min(x.first, m);
    int temp = m - take;
    x.first -= take;
    x.second -= temp;
    return x.first - x.second;
  };
  vpll ranges;
  ranges.push_back({0, 0});
  long long left = 0, right = 0;
  long long current;
  for (int i = 0; i < (n); i++) {
    int a, b;
    cin >> a >> b;
    dishes.push_back({a, b});
    pii now = {convert({a, b}), -convert({b, a})};
    left += (long long)now.first;
    right += (long long)now.second;
    ranges.push_back({left, right});
  }
  if (right < 0LL)
    current = -right;
  else if (left > 0LL)
    current = left;
  else if (right & 1LL)
    current = 1;
  else
    current = 0;
  ranges.pop_back();
  vpii res;
  cout << current << "\n";
  for (int i = (n)-1; i >= 0; i--) {
    long long r = min<long long>(dishes[i].first, m);
    long long l = max<long long>(0LL, m - dishes[i].second);
    while (l < r) {
      long long mid = (l + r) >> 1;
      long long previ =
          current - dishes[i].first + mid + dishes[i].second - (m - mid);
      if (previ > ranges[i].second)
        r = mid - 1;
      else if (previ < ranges[i].first)
        l = mid + 1;
      else {
        l = mid;
        break;
      }
    }
    res.push_back({l, m - l});
    current = current - dishes[i].first + l + dishes[i].second - (m - l);
  }
  reverse((res).begin(), (res).end());
  for (int i = 0; i < (n); i++)
    cout << res[i].first << " " << res[i].second << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __tests;
  cin >> __tests;
  while (__tests--) __run_test();
}

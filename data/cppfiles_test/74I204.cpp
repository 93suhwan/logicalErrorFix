#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename A, typename B>
istream &operator>>(istream &in, pair<A, B> &a) {
  in >> a.first >> a.second;
  return in;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const string no = "No";
const string yes = "Yes";
void solve() {
  long long k;
  cin >> k;
  vector<pair<long long, vector<long long>>> v(k);
  vector<long long> mx(k);
  for (long long i = 0; i < k; i++) {
    long long x;
    cin >> x;
    v[i].first = i;
    v[i].second = vector<long long>(x);
    cin >> v[i].second;
  };
  long long s = 0, e = 1e16;
  long long ans = 1e18;
  auto check = [&](long long mid) -> bool {
    vector<long long> left(k);
    long long h = mid;
    for (long long i = 0; i < k; i++) {
      left[i] = (long long)(v[i].second).size();
      v[i].first = i;
      for (long long j = 0; j < (long long)(v[i].second).size(); j++) {
        if (v[i].second[j] >= h) break;
        left[i]--;
      }
    }
    sort(v.begin(), v.end(),
         [&](pair<long long, vector<long long>> &a,
             pair<long long, vector<long long>> &b) {
           return left[a.first] < left[b.first];
         });
    h = mid;
    bool check = true;
    for (long long i = 0; i < k; i++) {
      for (long long j = 0; j < (long long)(v[i].second).size(); j++) {
        if (v[i].second[j] >= h) check = false;
        h++;
      }
    }
    return check;
  };
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  assert(ans != 1e18);
  cout << ans << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    ;
    solve();
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long int mod = (long long int)(998244353);
const long long int mod2 = (long long int)1e9 + 7;
long long int test = 1;
vector<long long int> read(int n) {
  vector<long long int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  return v;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void solve() {
  long long int i, j, k, m, n, cnt = 0, ans = 0, sum = 0;
  cin >> n >> k;
  vector<long long int> v = read(n);
  sort(v.begin(), v.end());
  vector<long long int> neg, pos;
  for (int i = 0; i < n; ++i) {
    if (v[i] >= 0) {
      pos.push_back(v[i]);
    } else {
      neg.push_back(v[i]);
    }
  }
  neg.push_back(0);
  pos.push_back(0);
  sort(pos.rbegin(), pos.rend());
  sort(neg.begin(), neg.end());
  for (int i = 0; i < pos.size(); i += k) {
    ans += pos[i] * 2;
  }
  for (int i = 0; i < neg.size(); i += k) {
    ans += abs(neg[i] * 2);
  }
  cout << ans - max(pos[0], -neg[0]) << "\n";
  test++;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int i = 1;
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}

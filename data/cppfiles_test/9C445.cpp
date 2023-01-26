#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
using namespace std;
long long mod = 1000000007;
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
void Solution() {
  string s;
  cin >> s;
  unordered_map<char, int> st;
  for (auto x : s) {
    st[x]++;
  }
  long long ans = 0;
  for (auto x : st) {
    if (x.second <= 2) {
      ans += x.second;
    } else {
      ans += 2;
    }
  }
  cout << ans / 2 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T;
  cin >> T;
  while (T != 0) {
    Solution();
    T--;
  }
  return 0;
}

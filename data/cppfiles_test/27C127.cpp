#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long LMAX = 1e18;
const long long MAX = 2e5 + 5;
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
  string str1, str2;
  cin >> str1 >> str2;
  long long j = str2.length() - 1;
  long long i = str1.length() - 1;
  while (i >= 0 && j >= 0) {
    if (str1[i] == str2[j]) {
      i--;
      j--;
    } else {
      i = i - 2;
    }
  }
  if (j == -1) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

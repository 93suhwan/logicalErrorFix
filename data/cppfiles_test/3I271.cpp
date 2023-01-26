#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9;
const long long NN = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;
template <typename T, typename T1>
T maxn(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T minn(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int convert(string second) {
  long long int ans = 0;
  reverse(second.begin(), second.end());
  while ((int)second.size()) {
    ans *= 10;
    ans += second.back() - '0';
    second.pop_back();
  }
  return ans;
}
void solve() {
  string second;
  cin >> second;
  long long int ans = 0;
  long long int un = 0, xx = 0;
  for (auto z : second) {
    if (z == '_') un = 1;
    if (z == 'X') xx = 1;
  }
  if (xx & un) {
    for (int(i) = (0); (i) < (10); (i)++) {
      for (int(j) = (0); (j) < (10); (j)++) {
        string ss = second;
        for (int(k) = (0); (k) < ((int)second.size()); (k)++) {
          if (ss[k] == '_')
            ss[k] = char(i + '0');
          else if (ss[k] == 'X')
            ss[k] = char(j + '0');
        }
        long long int x = convert(ss);
        if (x % 25 == 0) {
          if (((int)ss.size() > 1 && ss[0] != '0') || (int)ss.size() == 1)
            ans++;
        }
      }
    }
  } else {
    if (xx) {
      for (int(j) = (0); (j) < (10); (j)++) {
        string ss = second;
        for (int(k) = (0); (k) < ((int)second.size()); (k)++) {
          if (ss[k] == 'X') ss[k] = char(j + '0');
        }
        long long int x = convert(ss);
        if (x % 25 == 0) {
          if (((int)ss.size() > 1 && ss[0] != '0') || (int)ss.size() == 1)
            ans++;
        }
      }
    } else if (un) {
      for (int(j) = (0); (j) < (10); (j)++) {
        string ss = second;
        for (int(k) = (0); (k) < ((int)second.size()); (k)++) {
          if (ss[k] == '_') ss[k] = char(j + '0');
        }
        long long int x = convert(ss);
        if (x % 25 == 0) {
          if (((int)ss.size() > 1 && ss[0] != '0') || (int)ss.size() == 1)
            ans++;
        }
      }
    } else {
      if (convert(second) % 25 == 0) {
        if (((int)second.size() > 1 && second[0] != '0') ||
            (int)second.size() == 1)
          ans++;
      }
    }
  }
  cout << ans << "\n";
}
signed main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int testcase = 1;
  while (testcase--) solve();
  return 0;
}

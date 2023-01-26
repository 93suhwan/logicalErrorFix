#include <bits/stdc++.h>
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ","
       << " ";
  err(++it, args...);
  cout << "\n";
}
bool checkbit(long long mask, long long bit) { return mask & (1ll << bit); }
int setbit(long long mask, long long bit) { return mask | (1ll << bit); }
int clearbit(long long mask, long long bit) { return mask & ~(1ll << bit); }
int togglebit(long long mask, long long bit) { return mask ^ (1ll << bit); }
int bitno(long long mask) { return (long long)__builtin_popcount(mask); }
const int fx[] = {+1, -1, +0, +0};
const int fy[] = {+0, +0, +1, -1};
const long long maX = 1e6 + 10;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long test;
  cin >> test;
  while (test--) {
    string str;
    cin >> str;
    long long n = str.size();
    if (n == 1) {
      if (str[0] == '0')
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
      continue;
    }
    long long cc = 0;
    for (long long i = 0; i + 1 < n; i++) {
      if (str[i] == str[i + 1])
        continue;
      else {
        if (str[i] == '0') cc++;
      }
    }
    if (n > 2 && str[n - 1] == '0' && str[n - 2] == '0') {
      cc++;
    }
    cout << min(cc, 2ll) << "\n";
  }
  return 0;
}

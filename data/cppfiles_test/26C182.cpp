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
    long long n;
    cin >> n;
    long long cc = 1;
    for (long long i = 3; i <= 2 * n; i++) {
      cc *= i;
      cc %= 1000000007;
    }
    cout << cc << "\n";
  }
  return 0;
}

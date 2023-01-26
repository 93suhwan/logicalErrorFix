#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> holes;
long long _2[64];
long long masked(long long mask) {
  long long result = 0;
  for (int i = 0; i < 30; i++) {
    if (mask & _2[i]) {
      result = result + (_2[holes[i]]);
    }
  }
  return result;
}
int main() {
  _2[0] = 1;
  for (int i = 1; i <= 62; i++) {
    _2[i] = _2[i - 1] * 2;
  }
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if (n > m) {
      cout << "0\n";
      continue;
    }
    holes.clear();
    for (int i = 0; i < 61; i++) {
      if (_2[i] & n)
        continue;
      else
        holes.push_back(i);
      if (holes.size() == 30) break;
    }
    long long l = 0;
    long long r = _2[30] + 5;
    long long ans = -1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      if (masked(mid) + n > m) {
        ans = masked(mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

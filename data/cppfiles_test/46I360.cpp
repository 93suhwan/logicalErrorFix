#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int>& c, int n) {
  long long res = 0;
  for (int i = 0; i + 1 < n; i += 2) {
    int s = c[i];
    int mc = 0;
    bool fail = false;
    for (int j = i + 1; j < n && !fail; j += 2) {
      if (j > i + 1) {
        mc += c[j - 1];
      }
      int e = c[j];
      if (e >= mc) {
        e -= mc;
        mc = 0;
        if (j == i + 1)
          res += min(s, e);
        else
          res += min(s + 1, e + 1);
      } else {
        mc -= e;
        e = 0;
      }
      if (s < e) fail = true;
      s -= e;
    }
  }
  return res;
}
int main(int argc, const char* argv[]) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  cout << solve(c, n) << "\n";
  return 0;
}

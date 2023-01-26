#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, kk;
  cin >> n >> kk;
  int cnt = 0, tt = n - 1;
  while (tt) ++cnt, tt /= kk;
  cout << cnt << endl;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      vector<int> a, b;
      int i2 = i, j2 = j;
      while (i2 || j2)
        a.push_back(i2 % kk), b.push_back(j2 % kk), i2 /= kk, j2 /= kk;
      for (int i = int(a.size()) - 1; i >= 0; --i)
        if (a[i] != b[i]) {
          cout << i + 1 << ' ';
          break;
        }
    }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int mxn = (int)2e5 + 5;
void solve() {
  int a, b;
  cin >> a >> b;
  int n = a + b;
  int mn = 0, mx = 0;
  {
    int cura = a, curb = b;
    int cura2 = a, curb2 = b;
    int AB = 0, BA = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (cura > 0) {
          cura--;
        } else {
          curb--;
          AB++;
        }
      } else {
        if (curb > 0) {
          curb--;
        } else {
          cura--;
          AB++;
        }
      }
      if (i % 2 == 1) {
        if (cura2 > 0) {
          cura2--;
        } else {
          curb2--;
          BA++;
        }
      } else {
        if (curb2 > 0) {
          curb2--;
        } else {
          cura2--;
          BA++;
        }
      }
    }
    mn = min(AB, BA);
  }
  {
    int cura = a, curb = b;
    int cura2 = a, curb2 = b;
    int AB = 0, BA = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (curb > 0) {
          curb--;
          AB++;
        } else {
          cura--;
        }
      } else {
        if (cura > 0) {
          cura--;
          AB++;
        } else {
          curb--;
        }
      }
      if (i % 2 == 1) {
        if (curb2 > 0) {
          curb2--;
          BA++;
        } else {
          cura2--;
        }
      } else {
        if (cura2 > 0) {
          cura2--;
          BA++;
        } else {
          curb2--;
        }
      }
    }
    mx = max(AB, BA);
  }
  int inc = 1;
  if (n % 2 == 0) inc++;
  vector<int> res;
  for (int i = mn; i <= mx; i += inc) {
    res.push_back(i);
  }
  cout << (int)res.size() << "\n";
  for (int x : res) cout << x << " ";
  cout << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}

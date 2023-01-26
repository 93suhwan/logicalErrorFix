#include <bits/stdc++.h>
using namespace std;
vector<string> steps;
const long long MAX = 55;
pair<int, int> solve(int a) {
  int x = 1, y = 0;
  int win = sqrt(a);
  if (win * win != a) {
    win++;
  }
  y = win;
  int k = y * y;
  if (k == a) {
    return {x, y};
  }
  int p = (win * win - (win - 1) * (win - 1)) / 2;
  for (int i = 0; i < p; i++) {
    x++;
    k--;
    if (k == a) {
      return {x, y};
    }
  }
  for (int i = 0; i < p; i++) {
    y--;
    k--;
    if (k == a) {
      return {x, y};
    }
  }
}
signed main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cout << solve(a).second << ' ' << solve(a).first << endl;
  }
}

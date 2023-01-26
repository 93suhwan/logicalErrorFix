#include <bits/stdc++.h>
void openF(const char* file);
using namespace std;
int solve() {
  int w, h;
  cin >> w >> h;
  vector<vector<int> > dir(4);
  for (int i = 0; i < 4; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int x, y;
      cin >> x;
      dir[i].push_back(x);
    }
  }
  for (int i = 0; i < 4; i++) {
    sort(dir[i].begin(), dir[i].end());
  }
  int max = abs(dir[0][0] - dir[0].back());
  max = max > abs(dir[1][0] - dir[1].back()) ? max
                                             : abs(dir[1][0] - dir[1].back());
  int max2 = abs(dir[2][0] - dir[2].back());
  max2 = max2 > abs(dir[3][0] - dir[3].back()) ? max2
                                               : abs(dir[3][0] - dir[3].back());
  return max * h > max2 * w ? max * h : max2 * w;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << solve() << "\n";
  }
  return 0;
}
void openF(const char* file) { assert(freopen(file, "r", stdin)); }

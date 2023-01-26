#include <bits/stdc++.h>
void openF(const char* file);
using namespace std;
long long int solve() {
  long long int w, h;
  cin >> w >> h;
  vector<vector<long long int> > dir(4);
  for (long long int i = 0; i < 4; i++) {
    long long int k;
    cin >> k;
    for (long long int j = 0; j < k; j++) {
      long long int x, y;
      cin >> x;
      dir[i].push_back(x);
    }
  }
  for (long long int i = 0; i < 4; i++) {
    sort(dir[i].begin(), dir[i].end());
  }
  long long int max = abs(dir[0][0] - dir[0].back());
  max = max > abs(dir[1][0] - dir[1].back()) ? max
                                             : abs(dir[1][0] - dir[1].back());
  long long int max2 = abs(dir[2][0] - dir[2].back());
  max2 = max2 > abs(dir[3][0] - dir[3].back()) ? max2
                                               : abs(dir[3][0] - dir[3].back());
  return max * h >= max2 * w ? max * h : max2 * w;
}
int main() {
  long long int t;
  cin >> t;
  for (long long int i = 0; i < t; i++) {
    cout << solve() << "\n";
  }
  return 0;
}
void openF(const char* file) { assert(freopen(file, "r", stdin)); }

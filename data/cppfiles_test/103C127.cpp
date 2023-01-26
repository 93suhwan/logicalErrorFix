#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const unsigned gen_seed =
    std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);
int main() {
  int ta;
  scanf("%d", &ta);
  char c[1000500];
  for (int ifa = 0; ifa < ta; ifa++) {
    int n, m;
    scanf("%d %d\n", &n, &m);
    std::vector<string> a;
    for (int i = 0; i < n; i++) {
      scanf("%s", c);
      a.push_back(string(c));
    }
    std::vector<std::vector<int> > d(n, std::vector<int>(m, -1));
    int best = 0;
    std::pair<int, int> ans(1, 1);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (d[i][j] != -1) continue;
        int x = i;
        int y = j;
        std::vector<std::pair<int, int> > ord;
        ord.push_back(make_pair(x, y));
        d[x][y] = 0;
        while (1) {
          if (a[x][y] == 'U')
            x--;
          else if (a[x][y] == 'D')
            x++;
          else if (a[x][y] == 'L')
            y--;
          else if (a[x][y] == 'R')
            y++;
          if (x < 0 || x >= n || y < 0 || y >= m) {
            int last = 0;
            while (!ord.empty()) {
              d[ord.back().first][ord.back().second] = ++last;
              ord.pop_back();
            }
            break;
          } else if (d[x][y] != -1) {
            if (d[x][y] == 0) {
              int pt = 0;
              while (ord[pt] != make_pair(x, y)) pt++;
              int k = ord.size() - pt;
              for (int ia = pt; ia < ord.size(); ia++)
                d[ord[ia].first][ord[ia].second] = k;
              int last = k;
              ord.resize(pt);
              while (!ord.empty()) {
                d[ord.back().first][ord.back().second] = ++last;
                ord.pop_back();
              }
              break;
            } else {
              int last = d[x][y];
              while (!ord.empty()) {
                d[ord.back().first][ord.back().second] = ++last;
                ord.pop_back();
              }
              break;
            }
          } else {
            d[x][y] = 0;
            ord.push_back(make_pair(x, y));
          }
        }
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (d[i][j] > best) {
          best = d[i][j];
          ans = make_pair(i + 1, j + 1);
        }
      }
    }
    printf("%d %d %d\n", ans.first, ans.second, best);
  }
}

#include <bits/stdc++.h>
int T, N, M;
std::string C;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> T;
  while (T--) {
    std::cin >> N >> M;
    std::cin >> C;
    int xmin = 0, xmax = 0, ymin = 0, ymax = 0;
    int x = 0, y = 0;
    int xans, yans;
    for (int c : C) {
      int nx = x, ny = y;
      if (c == 'R') {
        ny = y + 1;
      } else if (c == 'L') {
        ny = y - 1;
      } else if (c == 'D') {
        nx = x + 1;
      } else {
        nx = x - 1;
      }
      int nxmin = std::min(xmin, nx);
      int nxmax = std::max(xmax, nx);
      int nymin = std::min(ymin, ny);
      int nymax = std::max(ymax, ny);
      if (nxmax - nxmin >= N or nymax - nymin >= M) {
        break;
      }
      x = nx;
      y = ny;
      xmin = nxmin;
      xmax = nxmax;
      ymin = nymin;
      ymax = nymax;
    }
    xans = 1 - xmin;
    yans = 1 - ymin;
    std::cout << xans << " " << yans << "\n";
  }
  return 0;
}

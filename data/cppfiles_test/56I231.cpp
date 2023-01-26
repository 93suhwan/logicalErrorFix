#include <bits/stdc++.h>
long long done;
std::string s;
long long rel;
void update(long long x, long long y) {
  if (done) return;
  std::cout << x << " " << y << std::endl;
  std::cin >> s;
  if (s == "Done") {
    done = true;
    return;
  }
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'L' || s[i] == 'R') rel ^= 1;
    if (s[i] == 'U' || s[i] == 'D') rel ^= 2;
  }
}
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  long long t;
  std::cin >> t;
  while (t--) {
    std::cout << "1 1" << std::endl;
    std::cin >> s;
    long long x = 1, y = 1;
    done = false;
    rel = 0;
    for (long long i = 0; i < 4 && (!done); i++) {
      while (!done) {
        long long nx = x, ny = y;
        long long cur = rel ^ i;
        if (cur % 2 == y % 2) ny++;
        if (cur / 2 == x % 2) nx++;
        if (nx > 7 || ny > 7) {
          if (x != 1) update(1, y);
          if (y != 1) update(1, 1);
          x = y = 1;
          break;
        }
        update(nx, ny);
        x = nx;
        y = ny;
      }
    }
  }
  return 0;
}

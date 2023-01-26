#include <bits/stdc++.h>
int mymax(int a, int b) {
  if (a > b) return a;
  return b;
}
int mymin(int a, int b) {
  if (a < b) return a;
  return b;
}
void boost() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
}
int main(void) {
  int t;
  dup2(open("test.txt", O_RDONLY), 0);
  boost();
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int ans = 0, n;
    std::cin >> n;
    if (n == 9)
      ans += 1;
    else
      ans = n / 10;
    std::cout << ans << '\n';
  }
  return (0);
}

#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::max;
using std::min;
using std::string;
int T, n = 8;
string s;
void Solve() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d %d\n", i, j), fflush(stdout);
      cin >> s;
      if (s == "Done") return;
      if (s == "Up" || s == "Up-Left" || s == "Up-Right") j = j > 1 ? 0 : 1;
      if (s == "Down" || s == "Down-Right" || s == "Down-Left") {
        printf("%d %d\n", i + 1, j), fflush(stdout);
        cin >> s;
        if (s == "Done") return;
        i++;
      }
    }
    printf("%d %d\n", i + 1, n), fflush(stdout);
    cin >> s;
    if (s == "Done") return;
  }
}
int main() {
  for (scanf("%d", &T); T--;) Solve();
  return 0;
}

#include <bits/stdc++.h>
using std::cerr;
using std::cin;
using std::max;
using std::min;
using std::string;
string s;
void Solve() {
  int i = 1, j = 1;
  for (; i <= 8; i++) {
    j = 1;
    cerr << "i"
         << "=" << (i) << "\n";
    for (; j <= 8; j++) {
      printf("%d %d\n", i, j), fflush(stdout);
      cin >> s;
      if (s == "Done") return;
      if (s == "Up" || s == "Up-Left" || s == "Up-Right")
        j = j > 1 ? 0 : 1;
      else if (s == "Down" || s == "Down-Right" || s == "Down-Left")
        break;
    }
    printf("%d %d\n", i + 1, j), fflush(stdout);
    cin >> s;
    if (s == "Done") return;
  }
}
int main() {
  int T = 0;
  for (scanf("%d", &T); T--;) Solve();
  return 0;
}

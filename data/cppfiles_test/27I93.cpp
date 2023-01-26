#include <bits/stdc++.h>
using namespace std;
int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    string second, t;
    cin >> second >> t;
    const int n = second.length();
    const int m = t.length();
    if (second.find(t) != string::npos) {
      puts("YES");
      continue;
    }
    auto valid = [&](int x, int y) {
      int p = x - y - 1;
      if (y == -1) return true;
      if (p % 2 == 0) return true;
      return false;
    };
    int j = 0;
    int past = -1;
    for (int i = 0; i < n; ++i) {
      if (j == m) break;
      if (second[i] == t[j] && valid(i, past)) {
        ++j;
        past = i;
      }
    }
    puts(j == m ? "YES" : "NO");
  }
  return 0;
}

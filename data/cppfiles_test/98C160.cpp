#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int solve() {
  auto read_string = [&]() {
    static char buffer[N];
    scanf(" %s", buffer);
    return buffer;
  };
  int n;
  scanf("%d", &n);
  string s;
  s = read_string();
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'a' and s[i + 1] == 'b') {
      return printf("%d %d", i + 1, i + 2);
    }
    if (s[i] == 'b' and s[i + 1] == 'a') {
      return printf("%d %d", i + 1, i + 2);
    }
  }
  puts("-1 -1");
  return 0;
}
int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
    puts("");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
map<char, int> e;
int main() {
  int t;
  string a, b;
  scanf("%d", &t);
  while (t--) {
    char ch;
    int i;
    int ans = 0;
    cin >> a >> b;
    for (int i = 0; i < a.length(); i++) {
      e[a[i]] = i + 1;
    }
    for (i = 1; i < b.length(); i++) {
      ans += abs(e[b[i]] - e[b[i - 1]]);
    }
    printf("%d\n", ans);
  }
  return 0;
}

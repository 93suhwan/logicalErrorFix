#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<string> v;
int main() {
  for (long long i = 1, j = 0; j < 64; j++, i <<= 1) {
    string s = to_string(i);
    v.push_back(s);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int mi = inf;
    for (string t : v) {
      int p = 0;
      int m = t.size();
      for (int i = 0; i < n; i++) {
        if (s[i] == t[p]) p++;
      }
      mi = min(mi, n + m - 2 * p);
    }
    printf("%d\n", mi);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 1000000000;
const int maxn = 100;
int T, n, m;
int main() {
  scanf("%d", &T);
  while (T--) {
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int sum = 0;
    int end = 0;
    for (int i = 0; i < n - 1; i++) {
      if (s1[i] != s2[i])
        sum += 2;
      else if (s1[i] == s2[i]) {
        if (s1[i] == '1' && (s2[i + 1] == '0' || s1[i + 1] == '0')) {
          sum += 2;
          i++;
          if (i == n - 1) end = 1;
        } else if (s1[i] == '0') {
          if (s1[i + 1] == '1' && s2[i + 1] == '1') {
            sum += 2;
            i++;
            if (i == n - 1) end = 1;
          } else {
            sum++;
          }
        }
      }
    }
    if (end == 0) {
      if (s1[n - 1] != s2[n - 1])
        sum += 2;
      else if (s1[n - 1] == s2[n - 1] && s1[n - 1] == '0')
        sum += 1;
    }
    cout << sum << endl;
  }
  return 0;
}

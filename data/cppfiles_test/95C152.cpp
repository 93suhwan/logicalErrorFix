#include <bits/stdc++.h>
using namespace std;
char s[20];
int b[20];
int bz[10];
int main() {
  bz[0] = 1;
  for (int i = 1; i <= (9); ++i) bz[i] = bz[i - 1] * 10;
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf(" %s %d", s, &n);
    int m = strlen(s);
    int sum = 0;
    for (int i = 0; i < (m); ++i) sum += s[i] - '0';
    for (int i = 0; i < (m); ++i) b[m - i - 1] = (s[i] - '0');
    while (sum < n) {
      for (int i = 1; i < m; ++i) {
        if (b[i] > 0) {
          --b[i];
          b[i - 1] += 10;
          sum += 9;
          break;
        }
      }
    }
    vector<int> v;
    for (int i = 0; i < (n - 1); ++i) {
      for (int j = m - 1; j >= 0; --j) {
        if (b[j] > 0) {
          --b[j];
          v.push_back(bz[j]);
          break;
        }
      }
    }
    int t = 0;
    for (int i = 0; i < (m); ++i) {
      t += bz[i] * b[i];
    }
    v.push_back(t);
    for (int i = 0; i < (n); ++i) printf("%d ", v[i]);
    puts("");
  }
  return 0;
}

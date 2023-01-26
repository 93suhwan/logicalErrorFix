#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, m, p[maxn];
string s[maxn];
bool cmp(int i, int j) {
  for (int k = 0; k < m; k++) {
    if (s[i][k] != s[j][k]) {
      if (k % 2 == 0)
        return s[i][k] < s[j][k];
      else
        return s[i][k] > s[j][k];
    }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    p[i] = i;
  }
  sort(p, p + n, cmp);
  for (int i = 0; i < n; i++) cout << p[i] + 1 << " ";
  return 0;
}

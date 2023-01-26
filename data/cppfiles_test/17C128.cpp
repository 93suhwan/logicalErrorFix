#include <bits/stdc++.h>
using namespace std;
int bitcnt(int n) {
  int res = 0;
  while (n) {
    res += n & 1;
    n >>= 1;
  }
  return res;
}
bool operator<(const vector<int>& v1, const vector<int>& v2) {
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    if (v1[i] > v2[i]) cnt++;
  return cnt >= 3;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<vector<int> > v(n, vector<int>(5));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < 5; j++) {
        scanf("%d", &v[i][j]);
      }
    int resid = 0;
    for (int i = 1; i < n; i++)
      if (v[resid] < v[i]) resid = i;
    bool isok = true;
    for (int i = 0; i < n; i++)
      if (i != resid && !(v[i] < v[resid])) isok = false;
    if (isok)
      printf("%d\n", resid + 1);
    else
      printf("%d\n", -1);
  }
  return 0;
}

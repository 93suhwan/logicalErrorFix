#include <bits/stdc++.h>
using namespace std;
bool check(int t) {
  int cnt = 0;
  for (int i = 1; i <= t; i++) {
    if (t % i == 0) cnt++;
  }
  return cnt != 2;
}
int main() {
  int _t;
  cin >> _t;
  for (int _ = 0; _ < (_t); ++_) {
    int n;
    cin >> n;
    vector<int> a(n);
    int S = 0;
    for (int i = 0; i < (n); ++i) {
      cin >> a[i];
      S += a[i];
    }
    vector<int> ans(n);
    for (int i = 0; i < (n); ++i) ans[i] = i;
    if (check(S)) {
    } else {
      for (int i = 0; i < (n); ++i) {
        if (check(S - a[i])) {
          ans.erase(ans.begin() + i);
          break;
        }
      }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < (ans.size()); ++i) {
      if (i != 0) printf(" ");
      printf("%d", ans[i] + 1);
    }
    printf("\n");
  }
  return 0;
}

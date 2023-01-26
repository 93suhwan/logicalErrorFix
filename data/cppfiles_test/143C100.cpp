#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int main(int argc, char **argv) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    vector<int> mp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      ++mp[ai];
    }
    ll cnt = 0;
    vector<int> stk;
    for (int i = 0; i <= n; ++i) {
      if (i > 0) {
        putchar(' ');
      }
      if (cnt != -1) {
        if (i > 0) {
          if (mp[i - 1] > 0) {
            for (int j = 0; j < mp[i - 1] - 1; ++j) {
              stk.push_back(i - 1);
            }
            cnt -= mp[i - 1];
          } else {
            if (stk.empty() || stk.back() > i - 1) {
              cnt = -1;
            } else {
              cnt += i - 1 - stk.back();
              stk.pop_back();
            }
          }
        }
      }
      if (cnt != -1) {
        cnt += mp[i];
      }
      printf("%" PRId64, cnt);
    }
    puts("");
  }
  return 0;
}

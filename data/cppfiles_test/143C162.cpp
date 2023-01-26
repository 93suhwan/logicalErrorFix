#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int main(int argc, char **argv) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      ++mp[ai];
    }
    ll cnt = 0;
    for (int i = 0; i <= n; ++i) {
      if (i > 0) {
        putchar(' ');
      }
      if (cnt != -1) {
        if (i > 0) {
          map<int, int>::iterator it = mp.lower_bound(i - 1);
          if (it == mp.end()) {
            if (mp.empty()) {
              cnt += i - 1;
            } else {
              --it;
              cnt += i - 1 - it->first;
              --it->second;
              if (it->second == 0) {
                mp.erase(it);
              }
            }
          } else {
            if (it->first == i - 1) {
              cnt -= it->second;
              --it->second;
              if (it->second == 0) {
                mp.erase(it);
              }
            } else if (it != mp.begin()) {
              --it;
              cnt += i - 1 - it->first;
              --it->second;
              if (it->second == 0) {
                mp.erase(it);
              }
            } else {
              cnt = -1;
            }
          }
        }
        if (cnt != -1) {
          map<int, int>::iterator it = mp.find(i);
          if (it != mp.end()) {
            cnt += it->second;
          }
        }
      }
      printf("%" PRId64, cnt);
    }
    puts("");
  }
  return 0;
}

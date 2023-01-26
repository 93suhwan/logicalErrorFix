#include <bits/stdc++.h>
using namespace std;
int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 0; test < (int)tests; test++) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < (int)n; i++) {
      scanf("%d", &a[i]);
    }
    string s;
    cin >> s;
    multiset<int> red, blue;
    for (int i = 0; i < (int)n; i++) {
      if (s[i] == 'B') {
        blue.insert(a[i]);
      } else {
        red.insert(a[i]);
      }
    }
    bool fail = false;
    for (int i = (int)1; i <= (int)n; i++) {
      if (!blue.empty() && *blue.begin() < i) {
        blue.erase(i - 1);
      }
      if (!blue.empty()) {
        blue.erase(blue.begin());
      } else {
        auto iter = red.upper_bound(i);
        if (iter == red.begin()) {
          fail = true;
          break;
        }
        --iter;
        red.erase(iter);
      }
    }
    if (fail) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
}

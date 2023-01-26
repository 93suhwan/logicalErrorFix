#include <bits/stdc++.h>
using namespace std;
inline int ask(const vector<int> &v) {
  printf("?");
  for (auto x : v) printf(" %d", x);
  puts("");
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}
int big[105], small[105], val[105];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = n; i >= 1; --i) {
    vector<int> v;
    if (!big[i]) {
      for (int j = 1; j <= n; j++) {
        if (j == i)
          v.push_back(1);
        else
          v.push_back(2);
      }
      int ans = ask(v);
      if (ans < i) big[i] = ans, small[ans] = i;
    }
    v.clear();
    if (!small[i]) {
      for (int j = 1; j <= n; j++) {
        if (j == i)
          v.push_back(2);
        else
          v.push_back(1);
      }
      int ans = ask(v);
      if (ans < i) small[i] = ans, big[ans] = i;
    }
  }
  int now = 0, cnt = 0;
  for (int i = 1; i <= n; i++)
    if (!big[i]) {
      now = i;
      break;
    }
  for (; now; now = small[now]) val[now] = ++cnt;
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", val[i]);
  return 0;
}

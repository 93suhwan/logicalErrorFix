#include <bits/stdc++.h>
using int64 = long long;
const int N = 45;
int n, K, cnt[N];
std::vector<int> a[10];
std::set<std::string> h[2];
void work() {
  std::cin >> n >> K;
  for (int i = 0; i < K; ++i) {
    int x;
    scanf("%d", &x);
    a[i].resize(x);
    for (int j = 0; j < x; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
    }
    if (x > 1) {
      for (auto &y : a[i]) {
        ++cnt[y];
      }
    } else {
      --i;
      --K;
    }
  }
  int cur = 0, nxt = 1;
  h[cur].clear();
  h[cur].insert(std::string(n, '?'));
  for (int k = 0; k < K; ++k) {
    h[nxt].clear();
    int sz = a[k].size();
    for (auto &s : h[cur]) {
      int c[2] = {}, r = 0;
      for (auto &x : a[k]) {
        if (s[x] != '?') {
          c[s[x] - '0']++;
        } else {
          r++;
        }
      }
      for (int i = 0; i <= r; ++i) {
        int idx = 0;
        std::string t = s;
        for (auto &x : a[k]) {
          if (idx < c[0] + i) {
            t[x] = '0';
          } else {
            t[x] = '1';
          }
          ++idx;
        }
        h[nxt].insert(t);
      }
    }
    for (auto &x : a[k]) {
      --cnt[x];
    }
    swap(h[cur], h[nxt]);
  }
  if (h[cur].size() != n + 1) {
    puts("REJECTED");
    return;
  }
  for (auto &s : h[cur]) {
    for (auto &c : s) {
      if (c == '?') {
        puts("REJECTED");
        return;
      }
    }
  }
  puts("ACCEPTED");
}
int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}

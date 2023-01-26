#include <bits/stdc++.h>
using namespace std;
template <typename Tp>
void read(Tp &num) {
  num = 0;
  auto f = 1;
  char c = getchar();
  while (!isdigit(c)) c == '-' ? f = -1 : 1, c = getchar();
  while (isdigit(c)) num = num * 10 + (c ^ 48), c = getchar();
  num *= f;
}
template <typename Tp, typename... etc>
void read(Tp &num, etc &...more) {
  read(num);
  read(more...);
}
const int MAXN = 200007;
long long n, w[MAXN], l, r;
bitset<MAXN> used;
int nowscan = 1;
string in;
queue<pair<long long, char> > res;
int main() {
  read(n);
  for (register int i = 1; i <= n; ++i) {
    read(w[i]);
  }
  cin >> in;
  sort(w + 1, w + 1 + n);
  for (register int i = 0; i < n; ++i) {
    bool now = (in[i] == 'R');
    if (!now) {
      if (l >= r) {
        while (used[nowscan]) {
          ++nowscan;
        }
        res.push(pair<long long, char>(w[nowscan++], 'L'));
      } else {
        int t = upper_bound(w + 1, w + 1 + n, r - l) - w;
        while (used[t]) {
          ++t;
          if (t > n) {
            printf("-1\n");
            return 0;
          }
        }
        used[t] = 1;
        res.push(pair<long long, char>(w[nowscan++], 'L'));
      }
    } else {
      if (l <= r) {
        while (used[nowscan]) {
          ++nowscan;
        }
        res.push(pair<long long, char>(w[nowscan++], 'R'));
      } else {
        int t = upper_bound(w + 1, w + 1 + n, r - l) - w;
        while (used[t]) {
          ++t;
          if (t > n) {
            printf("-1\n");
            return 0;
          }
        }
        used[t] = 1;
        res.push(pair<long long, char>(w[nowscan++], 'R'));
      }
    }
  }
  while (!res.empty()) {
    printf("%lld %c\n", res.front().first, res.front().second);
    res.pop();
  }
}

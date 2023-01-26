#include <bits/stdc++.h>
using namespace std;
int n;
char ch[100005];
vector<int> pos[30];
template <typename Azir>
void Read(Azir &x) {
  x = 0;
  char ch = getchar();
  int f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = x * f;
}
template <typename Azir>
void write(Azir x) {
  if (x >= 10) write(x / 10);
  putchar((char)(x % 10 + '0'));
}
template <typename Azir>
void writeln(Azir x) {
  write(x);
  puts("");
}
int main() {
  int tmp;
  scanf("%d", &tmp);
  while (tmp--) {
    scanf("%d", &n);
    scanf("%s", ch + 1);
    bool flg = 0;
    for (int i = 1; i <= 26; ++i) pos[i].clear();
    for (int i = 1; i <= n; ++i) {
      pos[ch[i] - 'a' + 1].push_back(i);
    }
    int mx = INT_MAX;
    for (int i = 1; i <= 26; ++i) {
      int l, r, cnt;
      l = 1;
      r = n;
      cnt = 0;
      while (l < r) {
        if (ch[l] == ch[r]) {
          --r;
          ++l;
          continue;
        }
        if (ch[l] - 'a' + 1 == i) {
          ++cnt;
          ++l;
          continue;
        }
        if (ch[r] - 'a' + 1 == i) {
          ++cnt;
          --r;
          continue;
        }
        if (ch[l] != ch[r]) {
          cnt = INT_MAX;
          break;
        }
      }
      mx = min(mx, cnt);
    }
    if (mx != INT_MAX)
      printf("%d\n", mx);
    else
      puts("-1");
  }
  return 0;
}

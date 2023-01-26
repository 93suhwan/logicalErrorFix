#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool chkmx(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T>
bool chkmn(T &x, T y) {
  return x > y ? x = y, true : false;
}
template <int T>
using A = array<int, T>;
const int maxn = 2000;
int n, ans[maxn + 5][maxn + 5];
char s[maxn + 5][maxn + 5];
queue<A<2>> q;
void insert(int i, int j, int k) {
  if (!i || !j || i == n + 1 || j == n + 1) return;
  if (!ans[i][j])
    ans[i][j] = k, q.push({i, j});
  else if (ans[i][j] != k)
    puts("NONE"), exit(0);
}
int main() {
  cin >> n;
  if (n & 1) return puts("NONE"), 0;
  for (int i = (1); i <= int(n); i++) cin >> s[i] + 1;
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(n); j++)
      if (s[i][j] != '.') {
        ans[i][j] = s[i][j] == 'G' ? 1 : -1;
        q.push({i, j});
      }
  while (!q.empty()) {
    A<2> u = q.front();
    q.pop();
    int c = ans[u[0]][u[1]];
    if (u[0] == 1 || u[0] == n) {
      if (u[1] & 1)
        insert(u[0], u[1] + 1, c);
      else
        insert(u[0], u[1] - 1, c);
    }
    if (u[1] == 1 || u[1] == n) {
      if (u[0] & 1)
        insert(u[0] + 1, u[1], c);
      else
        insert(u[0] - 1, u[1], c);
    }
    if (u[0] + u[1] & 1) {
      insert(u[0] + 1, u[1] + 1, -c);
      insert(u[0] - 1, u[1] - 1, -c);
    } else {
      insert(u[0] + 1, u[1] - 1, -c);
      insert(u[0] - 1, u[1] + 1, -c);
    }
  }
  for (int i = (1); i <= int(n); i++)
    for (int j = (1); j <= int(n); j++)
      if (!ans[i][j]) return puts("MULTIPLE"), 0;
  puts("UNIQUE");
  for (int i = (1); i <= int(n); i++) {
    for (int j = (1); j <= int(n); j++) putchar(ans[i][j] == 1 ? 'G' : 'S');
    putchar('\n');
  }
  return 0;
}

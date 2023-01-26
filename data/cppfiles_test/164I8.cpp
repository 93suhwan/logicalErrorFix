#include <bits/stdc++.h>
using namespace std;
const int N = 200000;
struct node {
  int left;
  int right;
};
struct node t[N + 5];
int tot, id[N + 5];
char a[N + 5];
bool col[N + 5];
char str[N + 5], dif[N + 5];
void dfs(int place) {
  if (!place) return;
  dfs(t[place].left);
  str[++tot] = a[place];
  id[place] = tot;
  dfs(t[place].right);
}
int addnum;
void print(int place) {
  if (!place) return;
  bool dup = 0;
  if (col[place] && addnum) {
    dup = 1;
    addnum--;
  }
  print(t[place].left);
  printf("%c", a[place]);
  if (col[place] && dup) printf("%c", a[place]);
  print(t[place].right);
}
int k;
bool add(int place) {
  bool ans = 0;
  if (t[place].left && k > 1) ans = add(t[place].left);
  if (ans || a[place] < dif[id[place]]) ans = 1;
  if (!ans) return 0;
  k--;
  col[place] = 1;
  if (t[place].right && k > 1) add(t[place].right);
  return 1;
}
int main() {
  int n;
  scanf("%d%d", &n, &k);
  addnum = k;
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].left, &t[i].right);
  dfs(1);
  dif[n] = str[n];
  for (int i = n - 1; i >= 1; i--) {
    if (str[i] == str[i + 1])
      dif[i] = dif[i + 1];
    else
      dif[i] = str[i + 1];
  }
  add(1);
  print(1);
  return 0;
}

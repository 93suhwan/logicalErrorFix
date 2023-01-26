#include <bits/stdc++.h>
using namespace std;
int n, m;
struct node {
  string s;
  int id;
} lt[1000010];
bool cmp(node a, node b) {
  for (int i = 0; i < a.s.length(); i++) {
    if (a.s[i] == b.s[i]) continue;
    if (i % 2)
      return a.s[i] > b.s[i];
    else
      return a.s[i] < b.s[i];
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> lt[i].s, lt[i].id = i;
  sort(lt + 1, lt + n + 1, cmp);
  for (int i = 1; i <= n; i++) cout << lt[i].id << ' ';
  return 0;
}

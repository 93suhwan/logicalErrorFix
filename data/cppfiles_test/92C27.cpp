#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int N = 200005;
char str[N] = {0};
void solve() {
  int i = 0, n = 0;
  scanf("%s", str);
  n = strlen(str);
  if (str[0] != str[n - 1]) {
    str[0] = str[n - 1];
  }
  printf("%s\n", str);
}
int main() {
  int o = 1;
  scanf("%d", &o);
  while (o--) {
    solve();
  }
  return 0;
}

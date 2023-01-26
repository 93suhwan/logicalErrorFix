#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const long long int INF = 3e16;
const int N = 200010;
int n;
int ask(vector<int> v) {
  printf("?");
  for (int i = 0; i < n; i++) printf(" %d", v[i]);
  printf("\n");
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}
int main() {
  scanf("%d", &n);
  int pivo = -1;
  for (int i = 1; i < n; i++) {
    vector<int> tmp(n);
    tmp[n - 1] = 1;
    for (int j = 0; j < n - 1; j++) {
      tmp[j] = 1 + i;
    }
    int k = ask(tmp);
    if (k == 0) {
      pivo = i;
      break;
    }
  }
  if (pivo == -1) pivo = n;
  vector<int> ans(n + 1);
  ans[n] = pivo;
  for (int i = 1; i <= n; i++) {
    if (i == pivo) continue;
    vector<int> tmp(n);
    tmp[n - 1] = (n + 1) - pivo;
    for (int j = 0; j < n - 1; j++) {
      tmp[j] = (n + 1) - i;
    }
    int k = ask(tmp);
    ans[k] = i;
  }
  printf("!");
  for (int i = 1; i <= n; i++) printf(" %d", ans[i]);
  printf("\n");
  fflush(stdout);
  return 0;
}

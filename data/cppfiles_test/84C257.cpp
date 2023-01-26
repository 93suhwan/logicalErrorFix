#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int MAX_INT = 2147483647;
const long long MAX_LL = (long long)(9e18);
const int N = 100005;
int n, m, q, ui, vi, tmp = 0, cnt = 0, l, r, mid, tmp2;
char s[N];
int k, ans = 0, sum = 0;
bool flag;
void solve(int CASE) {
  scanf("\n%d%d", &n, &k);
  if (n == 1)
    printf("%d\n", k);
  else if (n == 2) {
    printf("%d\n", k / n);
  } else
    printf("%d\n", k / (n - ((n + 1) / 2 - 1)));
  return;
}
int main() {
  int __t = 1;
  scanf("\n%d", &__t);
  for (int _T = 1; _T <= __t; _T++) {
    solve(_T);
  }
  return 0;
}

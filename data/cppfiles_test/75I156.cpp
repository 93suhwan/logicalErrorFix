#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];
int n;
int llen, rlen;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++)
    if (a[i] > a[i - 1])
      llen++;
    else
      break;
  for (int i = n; i >= 1; i--)
    if (a[i] > a[i + 1])
      rlen++;
    else
      break;
  if (llen % 2 == 1 || rlen % 2 == 1)
    cout << "Alice";
  else
    cout << "Bob" << endl;
  return 0;
}

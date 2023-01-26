#include <bits/stdc++.h>
using namespace std;
long long n;
long long ans[100000 + 10];
long long qus(long long ix, long long type) {
  cout << "?";
  for (long long i = 1; i <= n; i++) cout << " " << (ix != i ? 3 - type : type);
  cout << endl;
  fflush(stdout);
  long long ret;
  cin >> ret;
  return ret;
}
long long nxt[300];
int main() {
  cin >> n;
  long long f = 0, cur, ix = 1;
  for (long long i = 1; i <= n; i++) {
    cur = qus(i, 1);
    if (cur == 0) {
      f = i;
    } else if (cur != i) {
      nxt[cur] = i;
    }
    cur = qus(i, 2);
    if (cur == 0) {
      nxt[i] = -1;
    } else if (cur != i) {
      nxt[i] = cur;
    }
  }
  cout << "!";
  for (long long i = 1; i <= n; i++) cout << " " << ans[i];
  printf("\n");
  fflush(stdout);
  return 0;
}

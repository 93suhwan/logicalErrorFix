#include <bits/stdc++.h>
using namespace std;
multimap<long long int, long long int> mmp;
void ans() {
  long long int i, j, k, a, b, c, p, q, r, m, n, t, cnt, sum = 0, flag = 0;
  cin >> n;
  cnt = ceil(n / 3.0);
  t = cnt;
  if ((3 * cnt) - n == 1)
    cnt = cnt - 1;
  else if ((3 * cnt) - n == 2)
    t = cnt - 1;
  else
    t = cnt;
  cout << cnt << " " << t << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int k = 1;
  cin >> k;
  while (k--) {
    ans();
  }
}

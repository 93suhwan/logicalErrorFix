#include <bits/stdc++.h>
using namespace std;
long long int andQuery(long long int x, long long int y) {
  long long int val;
  cout << "and" << ' ' << x << ' ' << y << endl;
  return val;
}
long long int orQuery(long long int x, long long int y) {
  long long int val;
  cout << "or" << ' ' << x << ' ' << y << endl;
  return val;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t danger_close = clock();
  long long int n, k;
  cin >> n >> k;
  long long int s1, s2, s3, ans[n];
  s1 = andQuery(1, 2) + orQuery(1, 2);
  s2 = andQuery(2, 3) + orQuery(2, 3);
  s3 = andQuery(3, 1) + orQuery(3, 1);
  ans[0] = (s1 + s3 - s2) / 2;
  ans[1] = (s1 + s2 - s3) / 2;
  ans[2] = (s2 + s3 - s1) / 2;
  for (long long int i = 3; i < n; i++) {
    ans[i] = andQuery(1, i) + orQuery(1, i) - ans[0];
  }
  cout << "finish" << ans[k - 1] << endl;
  fprintf(stderr, "Total Time: %.3f\n",
          (double)(clock() - danger_close) / CLOCKS_PER_SEC),
      fflush(stderr);
  return 0;
}

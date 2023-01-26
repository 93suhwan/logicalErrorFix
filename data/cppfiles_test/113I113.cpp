#include <bits/stdc++.h>
using namespace std;
long long N, v[200005], M, S;
int bs(long long x) {
  int lw = 1, hi = N, last = 1;
  while (lw <= hi) {
    int mid = (lw + hi) >> 1;
    if (v[mid] <= x) {
      last = mid;
      lw = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return last;
}
int main() {
  cin >> N;
  v[0] = -2140000000;
  for (int i = 1; i <= N; i++) {
    cin >> v[i];
    S += v[i];
  }
  sort(v + 1, v + 1 + N);
  cin >> M;
  for (int i = 1; i <= M; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= v[1]) {
      cout << max(0LL, y - (S - v[1])) << endl;
      continue;
    }
    if (x >= v[N]) {
      cout << x - v[N] + max(0LL, y - (S - v[N])) << endl;
      continue;
    }
    int pos = bs(x);
    cout << min(x - v[pos] + max(0LL, y - (S - v[pos])),
                max(0LL, y - (S - v[pos + 1])))
         << endl;
  }
  return 0;
}

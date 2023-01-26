#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
int n, a[N], b[N], c[N], p[N];
vector<int> v;
int main() {
  cin >> n;
  for (int i = 1; i < N; i++) p[i] = i;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] == 2) cin >> c[i];
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] == 1)
      v.push_back(p[b[i]]);
    else if (a[i] == 2)
      p[b[i]] = p[c[i]];
  }
  for (int i = v.size() - 1; i >= 0; i--) printf("%d ", v[i]);
  return 0;
}

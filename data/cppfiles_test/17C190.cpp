#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 10;
long long n, a[N], tr[N];
vector<long long> V;
long long find(long long x) {
  long long l = 0, r = V.size() - 1;
  while (l < r) {
    long long mid = l + r >> 1;
    if (V[mid] >= x)
      r = mid;
    else
      l = mid + 1;
  }
  return r + 1;
}
vector<long long>::iterator unique(vector<long long> &a) {
  long long j = 0;
  for (long long i = 0; i < a.size(); i++)
    if (!i || a[i] != a[i - 1]) a[j++] = a[i];
  return a.begin() + j;
}
inline long long lowbit(long long x) { return x & -x; }
void add(long long x, long long y) {
  for (; x <= n; x += lowbit(x)) tr[x] += y;
}
long long calPre(long long x) {
  long long ans = 0;
  for (; x; x -= lowbit(x)) ans += tr[x];
  return ans;
}
long long calMin(long long x) {
  x = find(x);
  add(x, 1);
  return min(calPre(x - 1), calPre(n) - calPre(x));
}
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    cin >> n;
    V.clear();
    memset(tr, 0, sizeof tr);
    for (long long i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      V.push_back(a[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V), V.end());
    long long res = 0;
    for (long long i = 0; i < n; i++) res += calMin(a[i]);
    cout << res << endl;
  }
  return 0;
}

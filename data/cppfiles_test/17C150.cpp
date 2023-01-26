#include <bits/stdc++.h>
bool getbit(long long first, long long second) { return (first >> second) & 1; }
using namespace std;
const long long N = 2e5 + 5;
long long rs, test, n, a[N], b[N], BIT[N], cnt;
map<long long, long long> mp;
void upd(long long i, long long val) {
  for (; i <= n; i += i & -i) BIT[i] += val;
}
long long get(long long i) {
  long long rs = 0;
  for (; i > 0; i -= i & -i) rs += BIT[i];
  return rs;
}
long long get(long long l, long long r) { return get(r) - get(l - 1); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> test;
  while (test--) {
    memset(BIT, 0, sizeof BIT);
    mp.clear();
    cin >> n;
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    mp[b[1]] = 1;
    cnt = 1;
    for (long long i = 2; i <= n; i++)
      if (b[i] != b[i - 1]) mp[b[i]] = ++cnt;
    rs = 0;
    for (long long i = 1; i <= n; i++) {
      long long l = get(mp[a[i]] - 1);
      long long r = get(mp[a[i]] + 1, cnt);
      rs += min(l, r);
      upd(mp[a[i]], 1);
    }
    cout << rs << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;
long long ans[(1 << 23)], val[(1 << 23)];
long long n;
long long qtd[23][26] = {0};
void build(long long ind, string second) {
  long long i = 0;
  for (long long a = 0; a < 26; a++) {
    while (i < second.size() && second[i] == (char)(a + 'a'))
      i++, qtd[ind][a]++;
  }
}
void solve(long long a) {
  vector<pair<long long, long long> > ord;
  for (long long i = 0; i < n; i++) ord.push_back({-qtd[i][a], i});
  sort(begin(ord), end(ord));
  vector<long long> mask, aux;
  mask.push_back(0);
  for (auto x : ord) {
    aux.clear();
    x.first *= -1;
    for (auto y : mask) {
      aux.push_back(y | (1 << x.second));
      val[y | (1 << x.second)] =
          val[y | (1 << x.second)] * (1 + x.first) % 998244353;
    }
    for (auto y : aux) mask.push_back(y);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (long long i = 0; i < (1 << n); i++) val[i] = 1;
  string second;
  for (long long i = 0; i < n; i++) cin >> second, build(i, second);
  for (long long i = 0; i < 26; i++) solve(i);
  for (long long i = 0; i < (1 << n); ++i) {
    if (__builtin_parity(i))
      ans[i] = val[i];
    else
      ans[i] = -val[i];
  }
  ans[0] = 0;
  for (long long i = 0; i < n; ++i)
    for (long long mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) {
        ans[mask] = (ans[mask] + ans[mask ^ (1 << i)]) % 998244353;
      }
    }
  ans[0] = 1;
  long long resp = 0;
  for (long long i = 0; i < (1 << n); i++) {
    long long sum = 0, tot = 0;
    for (long long j = 0; j < n; j++)
      if ((i & (1 << j)) != 0) sum += j + 1, tot++;
    ans[i] = ans[i] * tot * sum;
    resp ^= ans[i];
  }
  cout << resp << endl;
}

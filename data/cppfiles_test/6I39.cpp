#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
template <class T, class S>
ostream &operator<<(ostream &o, const pair<T, S> &p) {
  return o << '(' << p.first << ", " << p.second << ')';
}
template <template <class, class...> class T, class... A>
typename enable_if<!is_same<T<A...>, string>(), ostream &>::type operator<<(
    ostream &o, T<A...> V) {
  o << '[';
  for (auto a : V) o << a << ", ";
  return o << ']';
}
int n, a[100010];
long long int ansg[100010], ct[100010];
vector<int> divs[100010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 1; i < (100010); ++i)
    for (int j = 1; j * j <= i; ++j)
      if (!(i % j)) {
        divs[i].push_back(j);
        if (j * j - i) divs[i].push_back(i / j);
      }
  cin >> n;
  for (int i = 1; i < (n + 1); ++i) cin >> a[i];
  for (int g = 1; g < (n + 1); ++g) {
    vector<int> v;
    for (int i = g; i <= n; i += g)
      for (int x : divs[a[i]]) v.push_back(x), ct[x]++;
    sort((v).begin(), (v).end());
    v.resize(unique((v).begin(), (v).end()) - v.begin());
    for (int x : v) ct[x] *= ct[x];
    reverse((v).begin(), (v).end());
    for (int x : v) {
      int m = 2 * x;
      while (m <= v.back()) {
        ct[x] -= ct[m];
        m += x;
      }
      ct[x] %= 1000000007;
      ansg[g] = (ansg[g] + x * ct[x]) % 1000000007;
    }
    for (int x : v) ct[x] = 0;
  }
  long long int ans = 0;
  for (int i = n; i > (0); --i) {
    for (int j = 2 * i; j <= n; j += i)
      ansg[i] = (ansg[i] + 1000000007 - ansg[j]) % 1000000007;
    ans = (ans + ansg[i] * i) % 1000000007;
  }
  cout << ans << '\n';
}

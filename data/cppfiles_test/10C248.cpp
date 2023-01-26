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
long long int a[200010], sol[200010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int tc;
  cin >> tc;
  while (tc--) {
    map<long long int, long long int> ct;
    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    vector<pair<long long int, long long int> > v;
    for (long long int i = 0; i < (n); ++i) {
      cin >> a[i];
      ct[a[i]]++;
      if (ct[a[i]] <= k) v.emplace_back(a[i], i);
      sol[i] = 0;
    }
    while (v.size() % k) v.pop_back();
    sort((v).begin(), (v).end());
    for (long long int i = 0; i < (v.size()); ++i)
      sol[v[i].second] = (i % k) + 1;
    for (long long int i = 0; i < (n); ++i) cout << sol[i] << ' ';
    cout << '\n';
  }
}

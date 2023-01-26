#include <bits/stdc++.h>
using namespace std;
int recur_depth = 0;
template <typename Ostream, typename Cont>
typename enable_if<is_same<Ostream, ostream>::value, Ostream&>::type operator<<(
    Ostream& os, const Cont& v) {
  os << "[";
  for (auto& x : v) {
    os << x << ", ";
  }
  return os << "]";
}
template <typename Ostream, typename... Ts>
Ostream& operator<<(Ostream& os, const pair<Ts...>& p) {
  return os << "{" << p.first << ", " << p.second << "}";
}
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < (int)(n); ++(i)) cin >> a[i];
  vector<char> c(n);
  for (int i = 0; i < (int)(n); ++(i)) cin >> c[i];
  vector<pair<long long, pair<long long, long long>>> b(n);
  for (int i = 0; i < (int)(n); ++(i)) {
    if (c[i] == 'R') {
      b[i] = {n - max(a[i], 1LL), {max(1LL, a[i]), n}};
    } else {
      b[i] = {min(a[i], n) - 1, {1, min(a[i], n)}};
    }
  }
  sort(std::begin(b), std::end(b));
  long long upper = n;
  long long buttom = 1;
  for (int i = 0; i < (int)(n); ++(i)) {
    auto in = b[i].second;
    if (in.first != 1) {
      if (upper >= in.first)
        upper--;
      else {
        cout << "NO\n";
        return;
      }
    } else {
      if (buttom <= in.second)
        buttom++;
      else {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}

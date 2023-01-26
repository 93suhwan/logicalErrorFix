#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <typename T>
void print(T val) {
  cout << val;
}
template <typename T1, typename... T>
void print(T1 x, T... args) {
  cout << x << ' ';
  print(args...);
}
template <typename... T>
void println(T... args) {
  print(args..., '\n');
}
template <typename T>
vector<T> readVec(int size) {
  vector<T> v(size);
  for (int i = 0; i < size; i++) {
    cin >> v[i];
  }
  return v;
}
template <typename T>
void printVec(vector<T> v) {
  for (auto it : v) {
    cout << it << ' ';
  }
  cout << '\n';
}
void pYesNo(bool x) {
  if (x)
    cout << "Yes\n";
  else
    cout << "No\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll p[18] = {0};
  p[0] = 1;
  for (int i = 1; i < 18; i++) {
    p[i] = p[i - 1] * 10;
  }
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    k++;
    auto v = readVec<int>(n);
    v.push_back(18);
    n++;
    ll ans = 0;
    for (int i = 1; i < n; i++) {
      ll d = v[i] - v[i - 1];
      ll x = p[d] - 1;
      if (x <= k) {
        k -= x;
        ans += p[v[i - 1]] * x;
      } else {
        ans += p[v[i - 1]] * k;
        break;
      }
    }
    println(ans);
  }
  return 0;
}

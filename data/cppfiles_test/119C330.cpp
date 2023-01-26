#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int inf = 0x3fffffff;
const ll INF = 0x1fffffffffffffff;
const double eps = 1e-12;
template <typename T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
void solve(int _rot) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = (int)(0); i < (int)(n); i++) cin >> a[i];
  ll sum = 0;
  for (int i = (int)(0); i < (int)(n); i++) sum += a[i];
  if (sum % n)
    puts("1");
  else
    puts("0");
}
int main() {
  int t;
  scanf("%d", &t);
  for (int rot = (int)(0); rot < (int)(t); rot++) solve(rot + 1);
  return 0;
}

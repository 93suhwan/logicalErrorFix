#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
template <typename T>
using vc = vector<T>;
template <typename T>
using vvc = vc<vc<T>>;
template <typename T>
void smax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void smin(T& a, T b) {
  a = min(a, b);
}
void f(bool b) {
  if (b)
    cout << "Alice";
  else
    cout << "Bob";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vc<int> a(n);
  for (auto& i : a) cin >> i;
  int x = 1, y = n - 2;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      x++;
    else
      break;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1])
      y--;
    else
      break;
  }
  int i = 0, j = n - 1;
  bool turn = true;
  while (i < x && j > y) {
    if (a[i] >= a[j] && (x - i) & 1 || a[i] <= a[j] && (j - y) & 1) {
      f(turn);
      return 0;
    }
    if (a[i] > a[j])
      j--;
    else if (a[i] < a[j])
      i++;
    else
      i++;
    turn ^= 1;
  }
  if (i == x)
    f((j - y) & 1);
  else
    f((x - i) & 1);
  return 0;
}

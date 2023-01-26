#include <bits/stdc++.h>
using namespace std;
inline bool valid(int x, int n) { return 0 <= x && x < n; }
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
template <typename T>
inline T pop(queue<T>& q) {
  T front = q.front();
  q.pop();
  return front;
}
template <typename T>
inline T gcd(T a, T b) {
  for (; b; a %= b, swap(a, b))
    ;
  return a;
}
template <typename T>
tuple<T, T, T> xgcd(T a, T b) {
  if (b == 0) return {1, 0, a};
  T x, y, g;
  tie(x, y, g) = xgcd(b, a % b);
  return {y, x - (a / b) * y, g};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    double x1, x2;
    int p1, p2;
    cin >> x1 >> p1 >> x2 >> p2;
    while (x1 >= 10) {
      p1++;
      x1 /= 10.0;
    }
    while (x2 >= 10) {
      p2++;
      x2 /= 10.0;
    }
    if (p1 != p2) {
      if (p1 > p2)
        cout << ">\n";
      else
        cout << "<\n";
    } else {
      if (x1 > x2)
        cout << ">\n";
      else if (x1 < x2)
        cout << "<\n";
      else
        cout << "=\n";
    }
  }
}

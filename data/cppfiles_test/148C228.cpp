#include <bits/stdc++.h>
using std::cin;
using std::cout;
long long solution() {
  long long w, h;
  long long area = 0, new_area;
  long long n, a, b, base;
  cin >> w >> h;
  for (int i = 0; i < 4; i++) {
    cin >> n >> a;
    for (int j = 1; j < n; j++) {
      cin >> b;
    }
    base = b - a;
    new_area = base * (i < 2 ? h : w);
    if (new_area > area) {
      area = new_area;
    }
  }
  return area;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solution() << "\n";
  }
  return 0;
}

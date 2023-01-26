#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  deque<int> a;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (a.empty()) {
      a.push_back(x);
    } else {
      if (a.front() > x) {
        a.push_front(x);
      } else if (a.back() < x) {
        a.push_back(x);
      } else {
        cout << (i % 2 == 0 ? "Alice" : "Bob");
        return 0;
      }
    }
  }
  cout << (n & 1 ? "Alice" : "Bob");
  return 0;
}

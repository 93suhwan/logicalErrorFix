#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> p;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int temp = 0;
    int Min = -0x3f3f3f3f;
    while (n--) {
      int a;
      cin >> a;
      p.push(a);
    }
    while (!p.empty()) {
      int now = p.top();
      p.pop();
      Min = max(Min, now + temp);
      temp -= now + temp;
    }
    cout << Min << '\n';
  }
  return 0;
}

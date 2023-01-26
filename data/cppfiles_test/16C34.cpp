#include <bits/stdc++.h>
using namespace std;
const int N = 2E5 + 10;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    scanf("%d", &n);
    priority_queue<pair<int, int>> heap;
    for (int i = 1; i <= (n); ++i) {
      int x;
      scanf("%d", &x);
      if (x) heap.push({x, i});
    }
    vector<pair<int, int>> res;
    while (heap.size() >= 2) {
      auto op1 = heap.top();
      heap.pop();
      auto op2 = heap.top();
      heap.pop();
      res.push_back({op1.second, op2.second});
      op1.first--, op2.first--;
      if (op1.first) heap.push(op1);
      if (op2.first) heap.push(op2);
    }
    printf("%u\n", res.size());
    for (auto& [a, b] : res) printf("%d %d\n", a, b);
  }
  return 0;
}

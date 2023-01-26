#include <bits/stdc++.h>
using namespace std;
struct node {
  friend bool operator<(node n1, node n2) { return n1.priority < n2.priority; }
  int priority;
  int value;
};
int main() {
  int n;
  cin >> n;
  while (n--) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
      int u;
      cin >> u;
      pq.push(u);
    }
    int j = 0, s;
    int max = -1e9;
    while (!pq.empty()) {
      if (pq.top() + j > max) {
        max = pq.top();
        s = j;
      }
      j -= pq.top() + j;
      pq.pop();
    }
    cout << max + s << endl;
  }
  return 0;
}

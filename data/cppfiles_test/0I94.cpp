#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef struct Node {
  string element;
  int id;
} node;
struct cmp {
  bool operator()(const node& x, const node& y) {
    for (int i = 0; i < m; i++) return x.element > y.element;
  }
};
priority_queue<node, vector<node>, cmp> mid;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    node shu;
    cin >> shu.element;
    shu.id = i;
    for (int j = 0; j < m; j++) {
      if (j % 2 == 1) shu.element[j] = 'Z' - shu.element[j] + 'A';
    }
    cout << shu.element << endl;
    mid.push(shu);
  }
  while (!mid.empty()) {
    cout << mid.top().id << " ";
    mid.pop();
  }
  return 0;
}

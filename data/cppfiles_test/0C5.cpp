#include <bits/stdc++.h>
using namespace std;
int n, m;
struct Node {
  string k;
  int id;
};
Node s[1000006];
bool cmp(Node a, Node b) {
  for (int i = 0; i < m; i++) {
    if (i % 2 == 0) {
      if (a.k[i] < b.k[i]) {
        return 1;
      } else if (a.k[i] > b.k[i]) {
        return 0;
      }
    } else {
      if (a.k[i] < b.k[i]) {
        return 0;
      } else if (a.k[i] > b.k[i]) {
        return 1;
      }
    }
  }
  return 1;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].k;
    s[i].id = i;
  }
  sort(s + 1, s + 1 + n, cmp);
  for (int i = 1; i <= n; i++) {
    cout << s[i].id << " ";
  }
  return 0;
}

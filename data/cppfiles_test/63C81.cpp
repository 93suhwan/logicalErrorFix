#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int parent1[1001];
int parent2[1001];
int find1(int n) {
  if (n == parent1[n]) {
    return n;
  } else {
    return parent1[n] = find1(parent1[n]);
  }
}
int find2(int n) {
  if (n == parent2[n]) {
    return n;
  } else {
    return parent2[n] = find2(parent2[n]);
  }
}
void union_set1(int a, int b) {
  a = find1(a);
  b = find1(b);
  if (a == b) {
    return;
  } else {
    parent1[a] = b;
  }
}
void union_set2(int a, int b) {
  a = find2(a);
  b = find2(b);
  if (a == b) {
    return;
  } else {
    parent2[a] = b;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    parent1[i] = i;
    parent2[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    union_set1(a, b);
  }
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    union_set2(a, b);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        if (find1(i) != find1(j) && find2(i) != find2(j)) {
          union_set1(i, j);
          union_set2(i, j);
          v.push_back({i, j});
        }
      }
    }
  }
  cout << v.size() << '\n';
  for (auto x : v) {
    cout << x.first << " " << x.second << '\n';
  }
}

#include <bits/stdc++.h>
using namespace std;
vector<int> link1(1001);
vector<int> link2(1001);
int find(vector<int>& link, int node) {
  while (node != link[node]) node = link[node];
  return node;
}
bool same(vector<int>& link, int node1, int node2) {
  return find(link, node1) == find(link, node2);
}
void unite(vector<int>& link, int& numOfSet, int n1, int n2) {
  int root1 = find(link, n1), root2 = find(link, n2);
  link[root2] = root1;
  numOfSet--;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  int numOfSet1 = n;
  int numOfSet2 = n;
  for (int i = 0; i < n; i++) link1[i + 1] = link2[i + 1] = i + 1;
  int p, q;
  for (int i = 0; i < m1; i++) {
    cin >> p >> q;
    unite(link1, numOfSet1, p, q);
  }
  for (int i = 0; i < m2; i++) {
    cin >> p >> q;
    unite(link2, numOfSet2, p, q);
  }
  cout << min(numOfSet1, numOfSet2) - 1 << endl;
  for (int i = 1; i < n + 1; i++)
    for (int j = i + 1; j < n + 1; j++)
      if (!same(link1, i, j) && !same(link2, i, j)) {
        cout << i << " " << j << endl;
        unite(link1, numOfSet1, i, j);
        unite(link2, numOfSet2, i, j);
        if (numOfSet1 == 1 || numOfSet2 == 1) return 0;
      }
  return 0;
}

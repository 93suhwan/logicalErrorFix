#include <bits/stdc++.h>
using namespace std;
void init(int p[], int tam[], int n) {
  for (int i = 0; i < n; i++) {
    p[i] = i;
    tam[i] = 1;
  }
}
int find(int p[], int tam[], int x) {
  if (p[x] == x) return x;
  return p[x] = find(p, tam, p[x]);
}
void merge(int p[], int tam[], int a, int b) {
  int setA = find(p, tam, a);
  int setB = find(p, tam, b);
  if (setA == setB) return;
  if (tam[setA] > tam[setB]) swap(setA, setB);
  p[setA] = setB;
  tam[setB] += tam[setA];
}
bool same(int p[], int tam[], int a, int b) {
  return find(p, tam, a) == find(p, tam, b);
}
int main() {
  int n, m1, m2;
  int u, v, i;
  int p[100000], p2[100000];
  int tam[100000], tam2[100000];
  cin >> n >> m1 >> m2;
  init(p, tam, n);
  init(p2, tam2, n);
  for (i = 0; i < m1; i++) {
    cin >> u >> v;
    merge(p, tam, u - 1, v - 1);
  }
  for (i = 0; i < m2; i++) {
    cin >> u >> v;
    merge(p2, tam2, u - 1, v - 1);
  }
  int resp = 0;
  set<int> conj;
  vector<pair<int, int>> edgs;
  bool nope;
  conj.insert(0);
  for (i = 1; i < n; i++) {
    nope = true;
    for (int c : conj) {
      if (same(p, tam, i, c)) continue;
      if (!same(p2, tam2, i, c)) {
        edgs.push_back({c + 1, i + 1});
        merge(p, tam, i, c);
        merge(p2, tam2, i, c);
        nope = false;
        resp++;
        break;
      }
    }
    if (nope) conj.insert(i);
  }
  cout << resp << endl;
  for (i = 0; i < resp; i++) {
    cout << edgs[i].first << " " << edgs[i].second << endl;
  }
}

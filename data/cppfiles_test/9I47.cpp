#include <bits/stdc++.h>
using namespace std;
struct Tree {
  int val;
  Tree* right = NULL;
  Tree* left = NULL;
};
long long int b_expo(long long x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  int a;
  queue<int> adj[m + 1];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 1; j < m + 1; j++) {
      cin >> a;
      if (a == 1) {
        adj[j].push(1);
      } else if (a == 3) {
        adj[j].push(-1);
      } else
        adj[j].push(0);
    }
  }
  for (long long int i = 0; i < k; i++) {
    cin >> a;
    if (adj[a].size() == 0) {
      cout << a << " ";
    } else {
      int id = a;
      while (adj[id].size() != 0) {
        int nxt = adj[id].front();
        adj[id].pop();
        id += nxt;
      }
      cout << id << " ";
    }
  }
  cout << endl;
}
int main() {
  solve();
  return 0;
}

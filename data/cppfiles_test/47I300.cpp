#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn], n;
int get(int a, int b, int c) {
  if (c) {
    cout << "or";
  } else {
    cout << "and";
  }
  cout << " " << a << " " << b << endl;
  int x;
  cin >> x;
  return x;
}
int f(int a, int b, int c, int d) {
  a = (a ^ (a & b));
  a |= c;
  a |= d;
  return a;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  set<pair<int, int>> s;
  int aAb = get(1, 2, 0);
  int aOb = get(1, 2, 1);
  int aAc = get(1, 3, 0);
  int aOc = get(1, 3, 1);
  int bAc = get(2, 3, 0);
  int bOc = get(2, 3, 1);
  s.insert({f(aOb, bOc, aAc, aAb), 1});
  int x = (*s.begin()).first;
  s.insert({f(aOb, aOc, bAc, aAb), 2});
  s.insert({f(aOc, aOb, aAc, bAc), 3});
  for (int i = 4; i <= n; i++) {
    int y = get(1, i, 1) - x + get(1, i, 0);
    s.insert({i, y});
  }
  auto it = s.begin();
  for (int i = 0; i < k - 1; i++) {
    it++;
  }
  cout << "finish " << (*it).first << endl;
  return 0;
}

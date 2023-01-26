#include <bits/stdc++.h>
using namespace std;
int sgn(int x) {
  if (x < 0) return -1;
  return 1;
}
int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    if (abs(a - b) > 1 || a + b > n - 2) {
      cout << -1 << endl;
      continue;
    }
    vector<int> A;
    A.push_back(0);
    if (a >= b) {
      for (int i = 1; i <= a; i++) {
        A.push_back(i);
        A.push_back(-i);
      }
      if (a == b) {
        A.push_back(a + 1);
      }
    } else if (a < b) {
      for (int i = 1; i <= b; i++) {
        A.push_back(-i);
        A.push_back(i);
      }
    }
    int dir = 1;
    if (A.size() >= 2) {
      dir = sgn(A[A.size() - 1] - A[A.size() - 2]);
    }
    while (A.size() < n) {
      A.push_back(A.back() + dir);
    }
    set<int> uniq;
    for (int a : A) {
      uniq.insert(a);
    }
    map<int, int> ids;
    for (int x : uniq) {
      int sz = ids.size();
      ids[x] = sz + 1;
    }
    if (A.size() != n) {
      cout << -1 << endl;
      continue;
    }
    for (int& a : A) {
      a = ids[a];
    }
    for (int i = 1; i <= n - 2; i++) {
      a -= (A[i] > max(A[i - 1], A[i + 1]));
      b -= (A[i] < min(A[i - 1], A[i + 1]));
    }
    if (a != 0 || b != 0) {
      cout << -1 << endl;
      continue;
    }
    for (int& a : A) {
      printf("%d ", a);
    }
    cout << endl;
  }
}

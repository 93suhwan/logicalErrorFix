#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> A(n);
    set<int> s;
    for (int i = 0; i < (int)(n); i++) {
      cin >> A[i];
      A[i]--;
      s.insert(A[i]);
    }
    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }
    if (n == 2) {
      if (A[0] <= A[1])
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      continue;
    }
    if (s.size() != n) {
      cout << "YES" << endl;
      continue;
    }
    vector<int> B(n);
    int cnt = 0;
    for (int i = 0; i < (int)(n); i++) {
      if (B[A[i]]) continue;
      int now = A[i];
      B[now] = 1;
      int tmp = 1;
      while (1) {
        if (B[A[now]]) break;
        tmp++;
        now = A[now];
        B[now] = 1;
      }
      cnt += tmp - 1;
    }
    if (cnt % 2 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

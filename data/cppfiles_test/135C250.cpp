#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> A, vector<int> B, int n) {
  for (int i = 0; i < n; i++) {
    if (A[i] != B[i]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> A;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      A.push_back(a);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for (int i = 0; i < n - (2 * k); i++) {
      ans += A[i];
    }
    map<int, int> B;
    for (int i = n - (2 * k); i < n; i++) {
      B[A[i]]++;
    }
    priority_queue<pair<int, int> > C;
    map<int, int>::iterator it;
    for (it = B.begin(); it != B.end(); it++) {
      C.push({it->second, it->first});
    }
    int a, b, c, d;
    while (C.size() > 1) {
      a = C.top().first;
      b = C.top().second;
      C.pop();
      c = C.top().first;
      d = C.top().second;
      C.pop();
      a--;
      c--;
      if (a != 0) {
        C.push({a, b});
      }
      if (c != 0) {
        C.push({c, d});
      }
    }
    if (C.size() == 1) {
      ans += (C.top().first / 2);
    }
    cout << ans << endl;
  }
}

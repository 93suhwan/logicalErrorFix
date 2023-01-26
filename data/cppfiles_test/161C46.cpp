#include <bits/stdc++.h>
using namespace std;
void pa(bool f) { f == 1 ? cout << "YES\n" : cout << "NO\n"; }
void solvetc() {
  int n;
  cin >> n;
  vector<pair<int, int> > A(n);
  map<pair<int, int>, bool> pre;
  for (int i = 0; i < n; i++) {
    cin >> A[i].first >> A[i].second;
    pre[A[i]] = 1;
  }
  for (int i = 0; i < n; i++) {
    if (A[i].first == A[i].second)
      cout << A[i].first << " " << A[i].second << " " << A[i].first << "\n";
    else {
      for (int j = A[i].first; j <= A[i].second; j++) {
        if (j == A[i].first && pre[{A[i].first + 1, A[i].second}]) {
          cout << A[i].first << " " << A[i].second << " " << j << "\n";
          break;
        } else if (j == A[i].second && pre[{A[i].first, A[i].second - 1}]) {
          cout << A[i].first << " " << A[i].second << " " << j << "\n";
          break;
        } else if (pre[{A[i].first, j - 1}] && pre[{j + 1, A[i].second}]) {
          cout << A[i].first << " " << A[i].second << " " << j << "\n";
          break;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solvetc();
  return 0;
}

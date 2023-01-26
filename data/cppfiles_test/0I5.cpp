#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
using namespace std;
bool compare(pair<string, int>& A, pair<string, int>& B) {
  int k = A.first.size();
  bool flag = true;
  for (int i = 0; i < k; i++) {
    if ((i + 1) % 2) {
      if (A.first[i] > B.first[i]) {
        flag = false;
        break;
      }
    } else {
      if (A.first[i] < B.first[i]) {
        flag = false;
        break;
      }
    }
  }
  if (A.first == B.first) {
    if (A.second < B.second) {
      return true;
    } else {
      return false;
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<string, int>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i].first;
    A[i].second = i + 1;
  }
  sort(A.begin(), A.end(), compare);
  for (auto it : A) {
    cout << it.second << " ";
  }
  cout << "\n";
  return 0;
}

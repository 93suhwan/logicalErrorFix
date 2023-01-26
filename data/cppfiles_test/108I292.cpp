#include <bits/stdc++.h>
using namespace std;
void solve(long long int test_case) {
  long long int n, x;
  cin >> n;
  vector<pair<long long int, long long int>> A, B;
  vector<long long int> ans(n, 0);
  long long int MAX_index = 0, MAX_index1 = 0, MAX = INT_MIN;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    A.push_back({x, i});
    if (MAX < x) {
      MAX = x;
      MAX_index = i;
    }
  }
  ans[MAX_index] = 1;
  MAX = INT_MIN;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    B.push_back({x, i});
    if (MAX < x) {
      MAX = x;
      MAX_index1 = i;
    }
  }
  ans[MAX_index1] = 1;
  set<long long int> sA, sB;
  if (MAX_index == MAX_index1) {
    for (long long int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    return;
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sA.insert(A[n - 1].first);
  sB.insert(B[n - 1].first);
  long long int iter = n - 2;
  vector<long long int> indices;
  for (; iter >= 0; iter--) {
    if (sA.empty() && sB.empty()) {
      break;
    } else {
      if (sB.find(A[iter].first) != sB.end()) {
        indices.push_back(A[iter].second);
        sB.erase(A[iter].first);
      }
      if (sA.find(B[iter].first) != sB.end()) {
        indices.push_back(B[iter].second);
        sA.erase(B[iter].first);
      }
    }
  }
  for (long long int i = 0; i < indices.size(); i++) {
    ans[indices[i]] = 1;
  }
  for (long long int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  cin >> T;
  for (long long int t = 1; t <= T; t++) solve(t);
  return 0;
}

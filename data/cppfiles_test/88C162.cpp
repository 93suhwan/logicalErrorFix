#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  bool solve(vector<int>& A) {
    int n = A.size();
    if (!!!(n & 1)) {
      return true;
    }
    for (int i = 0; i + 1 < n; ++i) {
      if (A[i] >= A[i + 1]) {
        return true;
      }
    }
    return false;
  }
};
int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Solution sol;
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    if (sol.solve(A)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

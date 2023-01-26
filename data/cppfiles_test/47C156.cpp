#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T-- > 0) {
    int N, k;
    cin >> N >> k;
    vector<int> A;
    for (int i = 0; i < N; i++) {
      int v;
      cin >> v;
      A.push_back(v);
    }
    sort(A.begin(), A.end());
    vector<int> pos_no;
    for (int i = N - 1; i >= 0; i--) {
      if (A[i] > 0) {
        pos_no.push_back(A[i]);
        A.pop_back();
      } else {
        break;
      }
    }
    int j = 0;
    long long int ans = 0;
    while (j < pos_no.size()) {
      ans = ans + 2 * pos_no[j];
      if (j + k < pos_no.size()) {
        j = j + k;
      } else {
        j = j + k;
        break;
      }
    }
    if (j < pos_no.size()) {
      ans = ans + 2 * pos_no[j];
    }
    int b = 0;
    while (b < A.size()) {
      ans = ans + 2 * abs(A[b]);
      if (b + k < A.size()) {
        b = b + k;
      } else {
        b = b + k;
        break;
      }
    }
    if (b < A.size()) {
      ans = ans + 2 * abs(A[b]);
    }
    int sub = 0;
    if (A.size() != 0 && pos_no.size() != 0) {
      sub = max(abs(A[0]), pos_no[0]);
    } else if (A.size() == 0) {
      sub = pos_no[0];
    } else if (pos_no.size() == 0) {
      sub = abs(A[0]);
    } else {
      sub = 0;
    }
    ans = ans - sub;
    cout << ans << endl;
  }
  return 0;
}

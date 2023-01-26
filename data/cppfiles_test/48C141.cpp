#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int A[N];
    map<int, set<int> > M;
    bool res = false;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      M[A[i]].insert(i);
      if (M[A[i]].size() > 1) {
        res = true;
      }
    }
    if (res) {
      cout << "YES\n";
      continue;
    }
    for (int i = N - 1; i >= 2; i--) {
      auto itr = M.rbegin();
      int ele = (*itr).first;
      if (ele == A[i]) {
        if ((*itr).second.size() == 1) {
          M.erase(ele);
        } else {
          (*itr).second.erase(i);
        }
        continue;
      }
      int i1, i2, i3;
      auto itr2 = (*itr).second.begin();
      if ((*itr2) == 0) {
        i1 = 0;
        i2 = 1;
        i3 = i;
        int x = A[i1], y = A[i2], z = A[i3];
        if (M[x].size() == 1) {
          M.erase(x);
        } else {
          M[x].erase(i1);
        }
        M[z].insert(i2);
        M[z].erase(i3);
        M[y].erase(i2);
        M[y].insert(i1);
        swap(A[i2], A[i3]);
        swap(A[i1], A[i3]);
      } else {
        i1 = 0;
        i2 = *((*itr).second.begin());
        i3 = i;
        int x = A[i1], y = A[i2], z = A[i3];
        M[z].erase(i3);
        M[z].insert(i1);
        M[x].insert(i2);
        M[x].erase(i1);
        if (M[y].size() == 1) {
          M.erase(y);
        } else {
          M[y].erase(i2);
        }
        swap(A[i2], A[i3]);
        swap(A[i1], A[i2]);
      }
    }
    if (A[0] <= A[1]) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}

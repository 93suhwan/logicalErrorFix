#include <bits/stdc++.h>
using namespace std;
bool MySort(pair<int, int>& A, pair<int, int>& B) {
  int Diff1 = abs(A.second - A.first);
  int Diff2 = abs(B.second - B.first);
  if (Diff1 == Diff2) {
    return A.first < B.first;
  } else
    return Diff1 < Diff2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<pair<int, int>> V;
    set<int> Set;
    for (int i = 1; i <= N; i++) {
      Set.insert(i);
      int L, R;
      cin >> L >> R;
      V.push_back({L, R});
    }
    sort(V.begin(), V.end(), MySort);
    for (auto X : V) {
      cout << X.first << " " << X.second << " ";
      auto Ans = lower_bound(Set.begin(), Set.end(), X.first);
      Set.erase(Ans);
      cout << *Ans << "\n";
    }
  }
  return 0;
}

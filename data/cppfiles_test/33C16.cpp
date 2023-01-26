#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int& a : A) cin >> a;
  int N = 1024;
  int MAX = numeric_limits<int>::max();
  vector<int> B(N, MAX);
  B[0] = 0;
  for (int a : A) {
    for (int j = 0; j < N; ++j) {
      if (B[j] >= a) continue;
      B[j ^ a] = min(B[j ^ a], a);
    }
  }
  vector<int> C;
  for (int i = 0; i < N; ++i) {
    if (B[i] == MAX) continue;
    C.push_back(i);
  }
  cout << C.size() << endl;
  copy(C.begin(), C.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}

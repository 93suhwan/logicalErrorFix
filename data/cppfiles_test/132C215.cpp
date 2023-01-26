#include <bits/stdc++.h>
using namespace std;
const long long INF = 1ll << 32;
void fast_stream() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  fast_stream();
  int t;
  cin >> t;
  while (t--) {
    map<int, int> make_pair;
    int A[7];
    for (int i = 0; i < 7; i++) {
      cin >> A[i];
      make_pair[A[i]] = 1;
    }
    sort(A, A + 7);
    cout << A[0] << " " << A[1] << " " << A[6] - A[0] - A[1] << endl;
  }
  return 0;
}

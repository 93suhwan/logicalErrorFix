#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long res;
  int T;
  cin >> T;
  while (T--) {
    res = 1LL;
    int N;
    cin >> N;
    int A;
    int onec = 0, zeroc = 0;
    for (int i = 0; i < N; i++) {
      cin >> A;
      if (A == 1)
        onec++;
      else if (A == 0)
        zeroc++;
    }
    cout << (res << zeroc) * (long long)onec << endl;
  }
  return 0;
}

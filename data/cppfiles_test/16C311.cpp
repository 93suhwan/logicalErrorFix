#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string T = S;
    sort(T.begin(), T.end());
    int Ans = 0;
    for (int i = 0; i < N; i++) {
      if (T[i] != S[i]) Ans++;
    }
    cout << Ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    string S;
    cin >> N >> S;
    string T = S;
    sort(T.begin(), T.end());
    int ans = 0;
    for (int i = 0; i < (int)S.size(); ++i)
      if (S[i] != T[i]) ++ans;
    cout << ans << '\n';
  }
}

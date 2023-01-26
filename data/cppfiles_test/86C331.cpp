#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool chk[100010];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    fill(chk + 1, chk + N + 1, 0);
    string A, B;
    cin >> A >> B;
    A = '*' + A, B = '*' + B;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
      if (A[i] == '0' && B[i] == '0') {
        if (A[i - 1] == '1' && B[i - 1] == '1' && !chk[i - 1]) {
          cnt += 2;
          chk[i] = true;
        } else
          cnt++;
      } else if (A[i] == '1' && B[i] == '1') {
        if (A[i - 1] == '0' && B[i - 1] == '0' && !chk[i - 1]) {
          cnt++;
          chk[i] = true;
        }
      } else
        cnt += 2;
    }
    cout << cnt << "\n";
  }
  return 0;
}

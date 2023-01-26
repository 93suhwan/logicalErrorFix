#include <bits/stdc++.h>
using namespace std;
const int N = 64;
const long long int INF = 1e18 + 100;
long long int pow2[N];
string pow2Str[N];
void pre() {
  pow2[0] = 1;
  pow2Str[0] = to_string(pow2[0]);
  for (int i = 1; i < N; i++) {
    pow2[i] = pow2[i - 1] * 2;
    pow2Str[i] = to_string(pow2[i]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pre();
  int T;
  cin >> T;
  while (T--) {
    string n;
    cin >> n;
    int siz = n.size();
    long long int idx = 0;
    long long int places = 0;
    long long int res = INF;
    for (int i = 0; i < N; i++) {
      idx = places = 0;
      int m = pow2Str[i].size();
      for (int j = 0; j < siz; j++) {
        if (idx >= m) {
          places++;
        } else {
          if (n[j] == pow2Str[i][idx]) {
            idx++;
          } else {
            places++;
          }
        }
      }
      res = min(res, places - idx + m);
    }
    cout << res << endl;
  }
  return 0;
}

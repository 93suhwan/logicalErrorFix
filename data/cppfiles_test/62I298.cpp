#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e17;
const int N = 10005;
bool x[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    for (long long i = (1); i < (n + 1); i++) {
      cin >> x[i];
    }
    int j = 0;
    for (long long i = (1); i < (n); i++) {
      if (x[i] == 0 and x[i + 1] == 1) {
        j = i;
        break;
      }
    }
    for (long long i = (1); i < (j + 1); i++) {
      cout << i << " ";
    }
    cout << n + 1 << " ";
    for (long long i = (j + 1); i < (n + 1); i++) {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}

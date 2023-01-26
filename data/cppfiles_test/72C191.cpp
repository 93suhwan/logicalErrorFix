#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e+3 + 8;
string cal(int j, const string &n, int dist, const int &k, string nw) {
  if (dist > k) {
    return "";
  }
  if ((nw.substr(0, j)) < (n.substr(0, j))) {
    return "";
  }
  if (j >= ((int)(n).size())) {
    return nw;
  }
  for (char c = '0'; c <= '9'; c++) {
    bool found = false;
    nw[j] = c;
    for (int i = 0; i < j; i++) {
      if (nw[i] == c) {
        found = true;
        break;
      }
    }
    string ch = cal(j + 1, n, dist + (found == false), k, nw);
    if (((int)(ch).size())) return ch;
  }
  return "";
}
void MAIN(long long tc) {
  string n;
  long long k;
  cin >> n >> k;
  string ans = cal(0, n, 0, k, string(((int)(n).size()), '0'));
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed;
  cout << setprecision(10);
  int test__cases = 1;
  cin >> test__cases;
  for (int i = 1; i <= test__cases; i++) {
    MAIN(i);
  }
}

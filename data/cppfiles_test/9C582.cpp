#include <bits/stdc++.h>
using namespace std;
void solve(string &cad) {
  vector<int> arr(26, 0);
  for (int i = 0; i < cad.size(); i++) {
    arr[(cad[i] - 'a')]++;
  }
  int rep1 = 0, rep2 = 0;
  for (auto x : arr) {
    if (x > 1) {
      rep2++;
    } else if (x > 0) {
      rep1++;
    }
  }
  cout << rep2 + rep1 / 2 << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n;
  cin >> n;
  while (n--) {
    string cad;
    cin >> cad;
    solve(cad);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long arr[2];
void func() {
  arr[0] = 0;
  arr[1] = 0;
  string s;
  cin >> s;
  for (long long i = 0; i < s.size(); i++) {
    arr[s[i] - '0']++;
  }
  if (arr[0] == 0) {
    cout << 0 << "\n";
  } else if (arr[0] == 1) {
    cout << 1 << "\n";
  } else {
    if (arr[1] == 0) {
      cout << 1 << "\n";
    } else {
      cout << 2 << "\n";
    }
  }
}
void fastio(string finp = "", string fout = "") {
  if (fopen(finp.c_str(), "r")) {
    freopen(finp.c_str(), "r", stdin);
    freopen(fout.c_str(), "w", stdout);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  bool multitest = 1;
  long long testcases = 1;
  if (multitest) {
    cin >> testcases;
  }
  while (testcases) {
    testcases--;
    func();
  }
  return 0;
}

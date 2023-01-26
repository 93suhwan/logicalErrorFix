#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int uc = unique(s.begin(), s.end()) - s.begin();
    int c = s.size();
    int k = (c - ((c - uc) * 2)) / 2 + (c - uc);
    if (uc == 1 && c != 1) k = 1;
    cout << k << "\n";
  }
  return 0;
}

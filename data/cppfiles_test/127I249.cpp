#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s >> t;
    long long int count = 0;
    for (int i = 0; i < t.size(); i++) {
      if (t[i] == 'a' or t[i] == 'b' or t[i] == 'c') count++;
    }
    if (count >= 1) {
      sort(s.begin(), s.end());
      cout << s << "\n";
      ;
    }
  }
  return 0;
}

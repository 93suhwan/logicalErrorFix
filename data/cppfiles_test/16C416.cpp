#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int c = 0;
    string s = "";
    cin >> s;
    string h = s;
    sort(h.begin(), h.end());
    for (int j = 0; j < n; j++)
      if (h.at(j) != s.at(j)) c++;
    cout << c << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    float red = 0;
    string s;
    cin >> s;
    int d, frq[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      ++frq[s[i] - 'a'];
    }
    for (char i = 0; i < 26; i++) {
      if (frq[i] >= 2)
        red++;
      else if (frq[i] == 1)
        red += .5;
    }
    d = red;
    cout << d << "\n";
  }
}

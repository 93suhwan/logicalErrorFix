#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, alphabet;
    int time = 0;
    cin >> alphabet >> s;
    for (int i = 1; i < s.size(); i++) {
      time += abs(find(alphabet.begin(), alphabet.end(), s[i - 1]) -
                  find(alphabet.begin(), alphabet.end(), s[i]));
    }
    cout << time << endl;
  }
  return 0;
}

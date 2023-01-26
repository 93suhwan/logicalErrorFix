#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  string s;
  while (t--) {
    cin >> s;
    if (s == "EN") {
      cout << "NO";
    } else if (s == "NN") {
      cout << "NO";
    } else if (s == "NE") {
      cout << "NO";
    } else if (s == "NNE") {
      cout << "NO";
    } else {
      cout << "YES";
    }
    cout << endl;
  }
}

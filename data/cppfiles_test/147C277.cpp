#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string seq;
    cin >> seq;
    int count = 0;
    for (int i = 0; i < seq.length(); i++)
      if (seq[i] == 'N') count++;
    if (count == 1)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  }
}

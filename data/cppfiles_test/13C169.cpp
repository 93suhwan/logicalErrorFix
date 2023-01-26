#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> umap;
    for (char ch : s) {
      umap[ch]++;
    }
    if (umap['A'] + umap['C'] == umap['B']) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  long long int t;
  cin >> t;
  while (t--) {
    string S, T, X;
    cin >> S >> T;
    int arr[26] = {};
    for (auto i = S.begin(); i < S.end(); ++i) {
      arr[*i - 'a']++;
    }
    if (T != "abc" || arr[0] == 0 || arr[1] == 0 || arr[2] == 0) {
      for (int i = 0; i < 26; ++i) {
        int x = arr[i];
        while (x--) {
          X.push_back(i + 'a');
        }
      }
      cout << X << endl;
    } else {
      for (int j = 0; j < 26; ++j) {
        int i = j;
        if (j == 1) {
          i = 2;
        }
        if (j == 2) {
          i = 1;
        }
        int x = arr[i];
        while (x--) {
          X.push_back(i + 'a');
        }
      }
      cout << X << endl;
    }
  }
  return 0;
}

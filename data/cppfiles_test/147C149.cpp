#include <bits/stdc++.h>
using namespace std;
int codefo;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> codefo;
  while (codefo--) {
    string S;
    cin >> S;
    int cnt = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == 'N') cnt++;
    }
    if (cnt == 1)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}

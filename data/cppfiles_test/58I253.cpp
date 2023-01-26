#include <bits/stdc++.h>
using namespace std;
int mina = 0x3f3f3f3f;
long long int maxa = 0;
const int N = 1e5 + 7;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    string s, x;
    cin >> s >> x;
    char arra[2][500];
    vector<pair<long long int, long long int>> p;
    for (long long int i = 0; i < n; i++) {
      arra[0][i] = s[i];
    }
    for (long long int i = 0; i < n; i++) {
      arra[1][i] = x[i];
    }
    for (long long int i = 0; i < n; i++) {
      for (long long int j = 0; j < 2; j++) {
        if (arra[j][i] == '0') {
          p.push_back({j, i});
        }
      }
    }
    long long int A = p[0].first;
    long long int B = p[0].second;
    bool ans = true;
    for (long long int i = 1; i < n; i++) {
      long long int a1 = p[i].first;
      long long int a2 = p[i].second;
      if (abs(A - a1) > 1 && abs(B - a2) > 1) {
        ans = false;
        break;
      }
      A = a1;
      B = a2;
    }
    if (ans == true) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 1e18;
bool inc(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first < p2.first;
}
bool dec(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first > p2.first;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int test_case;
  cin >> test_case;
  while (test_case--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        for (int j = 0; j < n; j++) {
          cout << "()";
        }
        cout << "\n";
      } else {
        for (int j = 1; j < n; j++) {
          if (j == i) {
            cout << "(())";
          } else {
            cout << "()";
          }
        }
        cout << "\n";
      }
    }
  }
}

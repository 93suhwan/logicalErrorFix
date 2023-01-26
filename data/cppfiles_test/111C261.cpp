#include <bits/stdc++.h>
using namespace std;
void run() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ;
}
int main() {
  run();
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
      for (long long int j = i + 1; j < n; j++) {
        cout << "()";
      }
      for (long long int j = n - i - 1; j < n; j++) {
        cout << "(";
      }
      for (long long int j = n - i - 1; j < n; j++) {
        cout << ")";
      }
      cout << endl;
    }
  }
}

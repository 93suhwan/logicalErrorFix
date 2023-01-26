#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    long long ab = 0;
    long long n = a.size();
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == 'a' && a[i + 1] == 'b') {
        ab++;
      }
      if (a[i + 1] == 'a' && a[i] == 'b') {
        ab--;
      }
    }
    string ansA = a, ansB = a;
    if (ab < 0) {
      long long A = 0, B = 0;
      for (int i = n - 1; i >= 0 && a[i] == 'a'; --i) {
        A++;
        ansA[i] = 'b';
      }
      for (int i = 0; i < n && a[i] == 'b'; ++i) {
        B++;
        ansB[i] = 'a';
      }
      if (A < B) {
        cout << ansA << endl;
      } else {
        cout << ansB << endl;
      }
    } else if (ab > 0) {
      long long A = 0, B = 0;
      for (int i = n - 1; i >= 0 && a[i] == 'b'; --i) {
        A++;
        ansA[i] = 'a';
      }
      for (int i = 0; i < n && a[i] == 'a'; ++i) {
        B++;
        ansB[i] = 'b';
      }
      if (A < B) {
        cout << ansA << endl;
      } else {
        cout << ansB << endl;
      }
    } else {
      cout << a << endl;
    }
  }
}

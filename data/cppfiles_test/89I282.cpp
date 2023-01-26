#include <bits/stdc++.h>
using namespace std;
bool prime(long long int n) {
  bool b = true;
  for (long long int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      b = false;
      break;
    }
  }
  if (b)
    return true;
  else
    return false;
}
void o_connor() {
  long long int n;
  cin >> n;
  vector<long long int> a(n), v;
  for (long long int i = 0; i < (n); ++i) cin >> a[i];
  vector<long long int> er, non_er;
  for (long long int i = 0; i < (n); ++i) {
    if (a[i] % (i + 2) == 0)
      non_er.push_back(i);
    else
      er.push_back(i);
  }
  long long int x = er.size(), y = non_er.size();
  long long int i = x - 1, j = y - 1;
  while (i >= 0 && j >= 0) {
    if (er[i] > non_er[j]) {
      i--;
      continue;
    } else {
      if (a[non_er[j]] % (non_er[j] + 1) == 0) {
        i--;
      } else {
        j--;
      }
    }
  }
  if (j < 0) {
    cout << "YES";
    return;
  }
  cout << "NO";
  return;
}
int main() {
  int tsc = 1;
  cin >> tsc;
  while (tsc--) {
    o_connor();
    cout << "\n";
  }
  return 0;
}

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
vector<long long int> t;
void o_connor() {
  long long int n;
  cin >> n;
  vector<long long int> a(n), v;
  for (long long int i = 0; i < (n); ++i) cin >> a[i];
  for (long long int i = 0; i < (n); ++i) {
    bool b = true;
    for (long long int j = 0; j < ((int)((t).size())); ++j) {
      if (t[j] <= i + 2) {
        if (a[i] % t[j] != 0) {
          b = false;
          break;
        }
      } else
        break;
    }
    if (b) {
      cout << "NO";
      return;
    }
  }
  cout << "YES";
  return;
}
int main() {
  int tsc = 1;
  cin >> tsc;
  for (long long int i = 2; i < (100000 + 1); ++i) {
    if (prime(i)) t.push_back(i);
  }
  while (tsc--) {
    o_connor();
    cout << "\n";
  }
  return 0;
}

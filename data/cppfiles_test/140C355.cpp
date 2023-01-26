#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> arr;
    for (int i = 1; i * i <= n; i++) {
      arr.insert(i * i);
    }
    for (int i = 1; i * i * i <= n; i++) {
      arr.insert(i * i * i);
    }
    cout << arr.size() << endl;
  }
  return 0;
}

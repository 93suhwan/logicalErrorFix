#include <bits/stdc++.h>
using namespace std;
bool isPrime(int num) {
  if (num == 2) return true;
  if (num % 2 == 0) return false;
  if (num == 1) return false;
  for (int i = 3; i * i <= num; i++) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  int testCases;
  cin >> testCases;
  while (testCases--) {
    int n, m;
    cin >> n >> m;
    int a, b, c;
    map<int, int> blocker;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      blocker[b] = 1;
    }
    int notBlocker = 1;
    for (int i = 1; i <= n; i++) {
      if (!blocker[i]) {
        notBlocker = i;
        break;
      }
    }
    for (int j = 1; j <= n; j++) {
      if (j == notBlocker) continue;
      cout << notBlocker << " " << j << endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e7 + 10;
long long factory[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
long long visited[MAXN] = {0};
int a[MAXN];
long long quick_m(long long a, long long b, long long p) {
  long long res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}
bool Cantor(int str[], int n) {
  long long result = 0;
  for (int i = 0; i < n; i++) {
    int counted = 0;
    for (int j = i + 1; j < n; j++) {
      if (str[i] > str[j]) {
        counted++;
      }
    }
    result += counted * factory[n - i - 1];
  }
  if (!visited[result]) {
    visited[result] = 1;
    return 1;
  }
  return 0;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    int sum = 1;
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      if (a[i] == 1) {
        ans = 0;
        if (flag == 1) {
          sum += 5;
        } else if (flag == 0) {
          sum += 1;
          flag = 1;
        }
      } else if (a[i] == 0) {
        flag = 0;
        ans++;
      }
      if (ans == 2) {
        sum = -1;
        break;
      }
    }
    cout << sum << endl;
  }
  return 0;
}

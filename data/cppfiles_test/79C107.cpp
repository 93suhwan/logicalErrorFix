#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int a[N];
int n, m;
char s[N];
bool not_prime(int x) {
  for (int j = 2; j * j <= x; ++j) {
    if (x % j == 0) return 1;
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    vector<int> v;
    scanf("%d%s", &n, s);
    bool l = 0;
    int tmp;
    for (int i = 0; i < n; ++i) {
      a[i] = s[i] - '0';
      if (not_prime(a[i]) || a[i] == 1) {
        l = 1;
        tmp = a[i];
        break;
      }
      v.push_back(a[i]);
    }
    if (l) {
      printf("1\n%d\n", tmp);
      continue;
    }
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        if (not_prime(v[i] * 10 + v[j])) {
          l = 1;
          tmp = v[i] * 10 + v[j];
        }
      }
    }
    if (l) {
      printf("2\n%d\n", tmp);
      continue;
    }
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        for (int k = j + 1; k < v.size(); ++k) {
          if (not_prime(v[i] * 100 + v[j] * 10 + v[k])) {
            l = 1;
            tmp = v[i] * 100 + v[j] * 10 + v[k];
          }
        }
      }
    }
    if (l) {
      printf("3\n%d\n", tmp);
      continue;
    }
    printf("-1\n");
  }
  return 0;
}

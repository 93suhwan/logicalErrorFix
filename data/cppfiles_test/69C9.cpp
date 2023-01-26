#include <bits/stdc++.h>
using namespace std;
template <class T>
void printVector(T begin, T end) {
  for (auto i = begin; i != end; i++) {
    cout << *i << ' ';
  }
  cout << endl;
}
long long readLL() {
  long long x;
  cin >> x;
  return x;
}
int readInt() {
  int x;
  cin >> x;
  return x;
}
vector<long long> v;
int calc(long long pw, long long n) {
  vector<int> a, b;
  int res = 0;
  while (pw) {
    a.push_back(pw % 10);
    pw /= 10;
  }
  while (n) {
    b.push_back(n % 10);
    n /= 10;
  }
  while (a.size() && b.size()) {
    if (a.back() == b.back()) {
      a.pop_back();
      b.pop_back();
    } else {
      b.pop_back();
      res++;
    }
  }
  return res + a.size() + b.size();
}
int main() {
  long long pw = 1;
  for (int i = 0; i <= 60; i++) {
    v.push_back(pw);
    pw *= 2;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int res = 100;
    for (int i = 0; i <= 60; i++) {
      res = min(res, calc(v[i], n));
    }
    printf("%d\n", res);
  }
  return 0;
}

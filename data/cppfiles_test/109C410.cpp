#include <bits/stdc++.h>
using namespace std;
int* GetBigInteger(string str) {
  int x = str.size(), a = 0;
  int* arr = new int[str.size()];
  while (a != x) {
    arr[a] = str[a] - '0';
    a++;
  }
  return arr;
}
int main() {
  vector<int> v;
  int n, oper;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j, count, sum;
    string d;
    sum = 0;
    cin >> j;
    long long digit;
    cin >> d;
    int* arr = GetBigInteger(d);
    count = j;
    for (int i = 0; i < j; i++) {
      sum += arr[i];
      if (arr[i] > 0 && i != j - 1) {
        sum += 1;
      }
    }
    v.push_back(sum);
  }
  for (int i = 0; i < v.size(); i++) {
    cout << '\n' << v[i];
  }
}

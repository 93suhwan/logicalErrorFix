#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> answers(n + 1);
  answers[1] = 1;
  long long summa = answers[1];
  for (int i = 2; i <= n; ++i) {
    answers[i] = summa;
    for (int j = 2; j * j < i; ++j) {
      if (i / j > j) {
        answers[i] += answers[i / j];
        answers[i] %= m;
      }
    }
    for (int j = 1; j * j <= i; ++j) {
      int first = (i / (j + 1)) + 1;
      int second = (i / j);
      long long counts = second - first + 1;
      answers[i] += counts * answers[j];
      answers[i] %= m;
    }
    summa += answers[i];
    summa %= m;
  }
  cout << answers[n] << endl;
}

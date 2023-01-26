#include <bits/stdc++.h>
using namespace std;
static int arr[10000];
int middleOf(int n) {
  if (n % 2 == 0) return n / 2;
  return (n + 1) / 2;
}
int main() {
  int N, n, s, mid, median;
  cin >> N;
  for (int counter = 0; counter < N; ++counter) {
    cin >> n >> s;
    mid = middleOf(n);
    int temp = n - mid + 1;
    if (temp == 0)
      cout << s;
    else {
      median = static_cast<int>(s / temp);
      cout << median;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long arr[1001];
int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  for (int i = 0; i < N; i++) {
    long long answer = arr[i] / 10;
    if (arr[i] % 10 == 9) answer++;
    cout << answer << endl;
  }
}

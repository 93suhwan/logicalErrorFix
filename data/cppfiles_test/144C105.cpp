#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const double PI = 3.141592653589793238462643383279;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T;
  cin >> T;
  for (long long testcase = 0; testcase < T; ++testcase) {
    long long N, M, K;
    cin >> N >> M >> K;
    long long big_table_num = N % M;
    long long move_num = big_table_num * ((N + M - 1) / M);
    long long diff = 0;
    for (long long itr = 0; itr < K; ++itr) {
      long long now = diff;
      for (long long i = 0; i < M; ++i) {
        if (i < big_table_num) {
          cout << (N + M - 1) / M << " ";
          for (long long j = 0; j < (N + M - 1) / M; ++j) {
            cout << now + 1 << " ";
            now += 1;
            now %= N;
          }
        } else {
          cout << N / M << " ";
          for (long long j = 0; j < (N) / M; ++j) {
            cout << now + 1 << " ";
            now += 1;
            now %= N;
          }
        }
        cout << "\n";
      }
      diff += move_num;
      diff %= N;
    }
  }
}

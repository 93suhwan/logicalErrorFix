#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
void run_case() {
  int N, K;
  cin >> N >> K;
  auto and_query = [&](int i, int j) -> int {
    int res;
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    cin >> res;
    return res;
  };
  auto or_query = [&](int i, int j) -> int {
    int res;
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    cin >> res;
    return res;
  };
  int and_ab = and_query(0, 1);
  int or_ab = or_query(0, 1);
  int xor_ab = or_ab ^ and_ab;
  int and_ac = and_query(0, 2);
  int or_ac = or_query(0, 2);
  int xor_ac = or_ac ^ and_ac;
  int and_bc = and_query(1, 2);
  int or_bc = or_query(1, 2);
  int xor_bc = or_bc ^ and_bc;
  int a = or_ab + and_ab + or_ac + and_ac - (or_bc + and_bc);
  int b = xor_ab ^ a, c = xor_ac ^ a;
  vector<int> A(N);
  A[0] = a, A[1] = b, A[2] = c;
  for (int i = 3; i < N; i++) {
    int x = and_query(0, i);
    int y = or_query(0, i);
    int z = x ^ y;
    A[i] = A[0] ^ z;
  }
  sort(A.begin(), A.end());
  cout << "finish " << A[K - 1] << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tests = 1;
  while (tests-- > 0) {
    run_case();
  }
  return 0;
}

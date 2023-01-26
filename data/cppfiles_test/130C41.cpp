#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 10;
int n;
int true_pos, false_pos;
bool is_impostor[MAXN];
bool get_request(int i, int j, int k) {
  if (i == j || j == k || i == k) exit(-1);
  bool ret;
  cout << "? " << i << " " << j << " " << k << endl;
  fflush(stdout);
  cin >> ret;
  return ret;
}
void get_true_false() {
  for (int i = 1; i <= n; i += 3) {
    bool tmp_A, tmp_B;
    if (is_impostor[i] ^ is_impostor[(i + 3) % n]) {
      tmp_A = get_request(i + 1, i + 2, (i + 3) % n);
      tmp_B = get_request(i + 2, (i + 3) % n, (i + 4) % n);
      if (is_impostor[i] ^ tmp_A) {
        if (is_impostor[i]) {
          true_pos = i;
          false_pos = (i + 3) % n;
        } else {
          true_pos = (i + 3) % n;
          false_pos = i;
        }
      } else if (tmp_A ^ tmp_B) {
        if (tmp_A) {
          true_pos = i + 1;
          false_pos = (i + 4) % n;
        } else {
          true_pos = (i + 4) % n;
          false_pos = i + 1;
        }
      } else {
        if (tmp_B) {
          true_pos = i + 2;
          false_pos = (i == n - 5 ? i + 5 : (i + 5) % n);
        } else {
          true_pos = (i == n - 5 ? i + 5 : (i + 5) % n);
          false_pos = i + 2;
        }
      }
      break;
    }
  }
}
bool is_known(int x) {
  return (true_pos >= x && true_pos <= x + 2) ||
         (false_pos >= x && false_pos <= x + 2);
}
void print_ans() {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) cnt += !is_impostor[i];
  cout << "! " << cnt << " ";
  for (int i = 1; i <= n; ++i) {
    if (!is_impostor[i]) cout << i << " ";
  }
  cout << endl;
  fflush(stdout);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i += 3) {
      is_impostor[i] = is_impostor[i + 1] = is_impostor[i + 2] =
          get_request(i, i + 1, i + 2);
    }
    get_true_false();
    is_impostor[true_pos] = true;
    is_impostor[false_pos] = false;
    for (int i = 1; i <= n; i += 3) {
      if (is_known(i)) {
        if (i != true_pos && i != false_pos)
          is_impostor[i] = get_request(false_pos, true_pos, i);
        if (i + 1 != true_pos && i + 1 != false_pos)
          is_impostor[i + 1] = get_request(false_pos, true_pos, i + 1);
        if (i + 2 != true_pos && i + 2 != false_pos)
          is_impostor[i + 2] = get_request(false_pos, true_pos, i + 2);
      } else {
        if (is_impostor[i]) {
          if (get_request(false_pos, i, i + 1)) {
            is_impostor[i] = is_impostor[i + 1] = true;
            is_impostor[i + 2] = get_request(false_pos, true_pos, i + 2);
          } else {
            is_impostor[i + 2] = true;
            is_impostor[i] = get_request(false_pos, true_pos, i);
            is_impostor[i + 1] = !is_impostor[i];
          }
        } else {
          if (!get_request(true_pos, i, i + 1)) {
            is_impostor[i] = is_impostor[i + 1] = false;
            is_impostor[i + 2] = get_request(false_pos, true_pos, i + 2);
          } else {
            is_impostor[i + 2] = false;
            is_impostor[i] = get_request(false_pos, true_pos, i);
            is_impostor[i + 1] = !is_impostor[i];
          }
        }
      }
    }
    print_ans();
  }
  return 0;
}

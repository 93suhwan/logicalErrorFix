#include <bits/stdc++.h>

using namespace std;

void solve() {
    int s, n;
    cin >> s >> n;

    if (s % 9 >= n) {
        while (--n) {
            for (int d = 1'000'000'000; d > 0; d /= 10) {
                if (s >= d) {
                    s -= d;
                    cout << d << ' ';
                    break;
                }
            }
        }

        cout << s;
    } else {
        vector<int> digits(10);
        for (int i = 9, d = 1'000'000'000; i >= 0; i--, d /= 10) {
            digits[i] = s / d;
            s -= digits[i] * d;
        }

        int m = n;
        m -= accumulate(digits.begin(), digits.end(), 0);
        for (int i = 1; i < 10 && m > 0; i++) {
            while (m > 0 && digits[i] > 0) {
                digits[i]--;
                digits[i - 1] += 10;
                m -= 9;
            }
        }

        int t = 0;
        for (int i = 9, d = 1'000'000'000; i >= 0; i--, d /= 10) {
            while (n > 1 && digits[i] > 0) {
                digits[i]--;
                n--;
                cout << d << ' ';
            }

            if (n == 1) {
                t += digits[i] * d;
            }
        }
        cout << t;
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}

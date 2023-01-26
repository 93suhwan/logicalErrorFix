#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<int>> L(n, std::vector<int>(m)), U(L);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'X') {
                L[i][j] = j + 1;
                U[i][j] = i + 1;
                continue;
            }
            L[i][j] = j;
            U[i][j] = i;
            if (j > 0) {
                L[i][j] = std::min(L[i][j], L[i][j - 1]);
                U[i][j] = std::min(U[i][j], U[i][j - 1]);
            }
            if (i > 0) {
                L[i][j] = std::min(L[i][j], L[i - 1][j]);
                U[i][j] = std::min(U[i][j], U[i - 1][j]);
            }
        }
    }

    int LG = std::__lg(m) + 1;
    std::vector<std::vector<int>> st(m, std::vector<int>(LG));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '.' && U[i][j] > 0) {
                st[j][0] = std::max(st[j][0], L[i][j]);
            }
        }
    }
    for (int j = 1; j < LG; ++j) {
        for (int i = 0; i + (1 << j) <= m; ++i) {
            st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        --l;
        int t = std::__lg(r - l);
        if (l >= std::max(st[l][t], st[r - (1 << t)][t])) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

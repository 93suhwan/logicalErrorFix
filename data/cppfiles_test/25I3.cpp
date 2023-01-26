#include <bits/stdc++.h>

#define I inline
#define fi first
#define se second
#define LL long long
#define mp make_pair
#define reg register int
#define pii pair<int,int>
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define fd(i, a, b) for(reg i = a; i >= b; i--)
#define ULL unsigned long long
#define cr const reg&
using namespace std;
const int inf = 2147483647;
const int mod = 998244353;
const int N = 1e6 + 1;

I int _max(cr x, cr y) {return x > y ? x : y;}
I int _min(cr x, cr y) {return x < y ? x : y;}
I LL read() {
	LL x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
	return x * f;
}
I void ptt(LL x) {if(x >= 10) ptt(x / 10); putchar(x % 10 + '0');}
I void put(LL x) {x < 0 ? putchar('-'), ptt(-x) : ptt(x);}
I void pr1(LL x) {put(x), putchar(' ');}
I void pr2(LL x) {put(x), puts("");}

I int pow_mod(reg a, reg k) {reg ans = 1; for(; k; k >>= 1, a = (LL)a * a % mod) if(k & 1) ans = (LL)ans * a % mod; return ans;}

int n, m, ans;
namespace Poly {
	int w[131073], R[131073]; ULL p[131073];
	int a[131073], b[131073], h[131073], d0[131073], d1[131073];
	
	I int Pre(cr n) {
		reg len = 1; for(; len <= n; len <<= 1);
		for(reg i = 1; i < (len << 1); i <<= 1) {
			reg s = 1, wn = pow_mod(3, (mod - 1) / (i << 1));
			fo(j, 0, i - 1) w[i + j] = s, s = (LL)s * wn % mod;
		} return len;
	}
	
	I int gao(int x) {return x < 0 ? x + mod : x;}
	I void DFT(int y[], cr len) {
		fo(i, 0, len - 1) p[R[i]] = gao(y[i]);
		int b;
		for(reg i = 1; i < len; i <<= 1) for(reg j = 0; j < len; j += i << 1)
			fo(k, 0, i - 1) b = p[i + j + k] * w[i + k] % mod, p[i + j + k] = p[j + k] + mod - b, p[j + k] += b;
		fo(i, 0, len - 1) y[i] = p[i] % mod;
	}
	I void IDFT(int y[], cr len) {
		reverse(y + 1, y + len); DFT(y, len); reg hh = pow_mod(len, mod - 2);
		fo(i, 0, len - 1) y[i] = (LL)y[i] * hh % mod;
	}
	I void clear(int a[], cr len) {memset(a + len, 0, sizeof(a[0]) * len);}
	I void clear(int a[], cr s, cr t) {if(s >= t) return ; memset(a + s, 0, sizeof(a[0]) * (t - s));}
	I void cpy(int a[], int b[], cr len) {memcpy(a, b, sizeof(a[0]) * len), memset(a + len, 0, sizeof(a[0]) * len);}
	I void getinv(int a[], int b[], cr len) {
		if(len == 1) {b[0] = pow_mod(a[0], mod - 2), b[1] = 0; return ;}
		getinv(a, b, len >> 1); cpy(h, a, len), clear(b, len);
		fo(i, 0, (len << 1) - 1) R[i] = (R[i >> 1] >> 1) | ((i & 1) ? len : 0);
		DFT(h, len << 1), DFT(b, len << 1);
		fo(i, 0, (len << 1) - 1) b[i] = (2 - (LL)b[i] * h[i]) % mod * b[i] % mod;
		IDFT(b, len << 1); clear(b, len);
	}
	
	I void solve(cr v, cr len) {
		if(v == 1) {
			fo(i, 0, len - 1) a[i] = 1;
			ans = 1;
			return ;
		} solve(v >> 1, len);
		memset(d0, 0, sizeof(int) * (len << 1));
		memset(d1, 0, sizeof(int) * (len << 1));
		fo(i, 0, len - 1) (i & 1 ? d1 : d0)[i] = a[i];
		if(v & 1) d1[1]++, d1[1] = d1[1] >= mod ? d1[1] - mod : d1[1];
		memset(a, 0, sizeof(int) * (len << 1));
		fo(i, 0, len - 1) a[i] = d1[i] ? mod - d1[i] : 0;
		a[0]++, a[0] = a[0] >= mod ? a[0] - mod : a[0];
		getinv(a, b, len);
		if(v == m || !(n & 1)) {
			reg sum = 0;
			for(int i = 1; i <= n; i += 2) sum = (sum + (LL)b[n - i] * d1[i] % mod * i) % mod;
			if(!(n & 1)) ans = (ans + 2LL * sum) % mod;
			else ans = sum;
			if(v == m) return ;
		} DFT(d0, len << 1);
		fo(i, 0, (len << 1) - 1) d0[i] = (LL)d0[i] * d0[i] % mod;
		IDFT(d0, len << 1); clear(d0, len);
		DFT(d0, len << 1), DFT(b, len << 1);
		fo(i, 0, (len << 1) - 1) a[i] = (LL)b[i] * d0[i] % mod;
		IDFT(a, len << 1);
		fo(i, 0, len - 1) a[i] = a[i] + d1[i], a[i] = a[i] >= mod ? a[i] - mod : a[i];
		if(v & 1) a[1] ? a[1]-- : a[1] = mod - 1;
	}
}

int main() {
	n = read(), m = read();
	reg len = Poly::Pre(n);
	Poly:: solve(m, len);
	pr2(ans < 0 ? ans + mod : ans);
	return 0;
}
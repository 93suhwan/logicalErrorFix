#include<bits/stdc++.h>
#include<ctime>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long LL;
const LL p = 1e9 + 7;
const LL N = 10;
const LL M = 10;
const LL ispSize = 10;
const LL primeSize = 10;
const LL matSize = 150;
const double pi = 3.141592653589;

//mathematics
template <class T> T __lcm(T lcmA, T lcmB) { return lcmA / __gcd(lcmA, lcmB) * lcmB; }
template <class T> void exgcd(T E_A, T E_B, T &E_X, T &E_Y) {
	if (!E_B) E_X = 1, E_Y = 0;
	else exgcd(E_B, E_A % E_B, E_Y, E_X), E_Y -= E_A / E_B * E_X;
}
template <class T> T Exgcd(T E_A, T E_B, T &E_X, T &E_Y) {
	if (!E_B) {
		E_X = 1, E_Y = 0; return E_A;
	}
	else {
		T res = Exgcd(E_B, E_A % E_B, E_Y, E_X); E_Y -= E_A / E_B * E_X;
		return res;
	}
}
template <class T> T niyuan(T NY_a, T NY_p) {
	LL NY_x, NY_y; exgcd(NY_a, NY_p, NY_x, NY_y); 
	return (NY_x % NY_p + NY_p) % NY_p; 
}
template <class T> T FastMul(T FMa, T FMb, T FMp) {
	return (FMa*FMb-(LL)(FMa/(long double)FMp*FMb+1e-3)*FMp+FMp)%FMp;
}
template <class T> T modadd(T MA, T MB) { return ((MA % p) + (MB % p)) % p; }
template <class T> T modmul(T MA, T MB) { return ((MA % p) * (MB % p)) % p; }
bool Bcmp(const LL &AAA, const LL &BBB) { return AAA > BBB; }
LL prime_cnt = 0; LL isp[ispSize], prime[primeSize];
void GetPrime(int GPn){
	for (LL i = 1; i <= GPn; ++i) isp[i] = 1; 
	isp[1] = 0;
	for (LL i = 2; i <= GPn; ++i){
		if (isp[i]) prime[++prime_cnt] = i;
		for (LL j = 1; j <= prime_cnt && i * prime[j] <= GPn; ++j) {
			isp[i * prime[j]] = 0; if (i % prime[j] == 0) break;
		}
	}
}
LL inv[N], fact[N];
inline void getFact(LL COUNT, LL MOD) {
	fact[0] = 1;
	for (int i = 1; i <= COUNT; ++i) fact[i]=(fact[i-1]*i)%MOD;
}
inline void getInv(LL MOD){
	inv[1] = 1;
	for (int i = 2; i < MOD; ++i) inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
}
inline LL C(LL Cn, LL Cm, LL Cp){
	return (Cn<Cm)?0:fact[Cn]*inv[fact[Cm]]%Cp*inv[fact[Cn-Cm]]%Cp;
}
inline LL lucas(LL Ln, LL Lm, LL Lp){
	return (Lm==0)?(1%Lp):lucas(Ln/Lp,Lm/Lp,Lp)*C(Ln%Lp,Lm%Lp,Lp)%Lp;
}
struct mat
{
	LL matA[matSize][matSize];
	inline mat() { memset(matA, 0, sizeof(matA)); }
	inline mat operator - (const mat &MAT_T) const {
		mat MAT_RES;
		for (int i = 0; i < matSize; ++i) for (int j = 0; j < matSize; ++j)
			MAT_RES.matA[i][j] = (matA[i][j] - MAT_T.matA[i][j]) % p;
		return MAT_RES;
	}
	inline mat operator + (const mat &MAT_T) const {
		mat MAT_RES;
		for (int i = 0; i < matSize; ++i) for (int j = 0; j < matSize; ++j)
			MAT_RES.matA[i][j] = (matA[i][j] + MAT_T.matA[i][j]) % p;
		return MAT_RES;
	}
	inline mat operator * (const mat &MAT_T) const {
		mat MAT_RES; int MAT_R;
		for (int i = 0; i < matSize; ++i) for (int k = 0; k < matSize; ++k){
			MAT_R = matA[i][k];
			for (int j = 0; j < matSize; ++j)
				MAT_RES.matA[i][j]+=MAT_T.matA[k][j]*MAT_R, MAT_RES.matA[i][j]%=p;
		}
		return MAT_RES;
	}
	inline mat operator ^ (LL MAT_X) const {
		mat MAT_RES, MAT_BAS;
		for (int i = 0; i < matSize; ++i) MAT_RES.matA[i][i] = 1;
		for (int i = 0; i < matSize; ++i) for (int j = 0; j < matSize; ++j)
			MAT_BAS.matA[i][j] = matA[i][j] % p;
		while (MAT_X) {
			if (MAT_X&1)MAT_RES=MAT_RES*MAT_BAS; 
			MAT_BAS=MAT_BAS*MAT_BAS; MAT_X>>=1;
		}
		return MAT_RES;
	}
};
template <class T> T FPW(T FPWa, T FPWb) {
	T FPWbs = FPWa, FPWres = 1;
	while (FPWb > 0) { 
		if (FPWb & 1) FPWres = modmul(FPWres, FPWbs); 
		FPWbs = modmul(FPWbs, FPWbs); FPWb >>= 1;
	}
	return FPWres;
}
inline LL read() {
	LL x = 0, y = 1; char c = getchar(); 
	while (c > '9' || c < '0') { if (c == '-') y = -1; c = getchar(); }
	while (c>='0'&&c<='9') { x=x*10+c-'0';c=getchar(); } return x*y;
}
inline LL mread() {
	LL res=0; char ch=getchar(); while (!isdigit(ch) and ch != EOF) ch=getchar();
	while (isdigit(ch)) { res=(res<<3)+(res<<1)+(ch-'0');res%=p;ch=getchar(); }
	return res;
}
typedef LL pb_ds_type;
typedef tree<pb_ds_type, null_type, less<pb_ds_type>, rb_tree_tag, 
			tree_order_statistics_node_update> ordered_set;

//----------------------------------------------------------------------
//UPDATE THE SIZE OF N, M, ispSize, primeSize, matSize!!!

LL n;
LL a[100050];

void main2()
{
	n = read();
	for (LL i = 1; i <= n; ++i)
	{
		a[i] = read();
	}
	if (n & 1)
	{
		for (LL i = 1; i <= n - 3; i += 2)
		{
			printf("%lld %lld ", -a[i + 1], a[i]);
		}
		printf("%lld %lld %lld\n", -(a[n - 1] + a[n]), a[n - 2], a[n - 2]);
	}
	else
	{
		for (LL i = 1; i <= n - 1; i += 2)
		{
			printf("%lld %lld ", -a[i + 1], a[i]);
		}
		printf("\n");
	}
	return;
}
LL T;
int main()
{
	//int c1=clock();
	T = read();
	//T = 1;
	for (LL t = 1; t <= T; ++t)
	{
		main2();
	}
	//cerr << "Time Used :" << clock() - c1 << "ms" << endl;
	return 0;
}
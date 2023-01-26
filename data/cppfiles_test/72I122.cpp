#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<time.h>
#include<set>
using namespace std;
#define rg register
#define ll long long
#define ull unsigned long long
#define lowbit(i) i&(-i)
#define pb(x) push_back(x)
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=110,mod=998244353;
int a,b,n;
int main(){
    a=__gcd(a,n);
}

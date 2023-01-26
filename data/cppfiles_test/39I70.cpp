#include<locale.h>　　　　//定义本地化函数
#include <math.h>　　　　　//定义数学函数
#include <stdio.h>　　　　//定义输入／输出函数
#include<stdlib.h>　　　　//定义杂项函数及内存分配函数
#include <string.h>　　　　//字符串处理
#include<time.h>　　　　　//定义关于时间的函数
#include <wchar.h>　　　　//宽字符处理及输入／输出
#include <wctype.h>　　　　//宽字符分类
#include <algorithm>　　　 //STL通用算法
#include <bitset>　　　　　//STL位集容器
#include <cctype>
#include <cerrno>
#include <clocale>
#include <cmath>
#include <complex>　　　　 //复数类
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>　　　　　 //STL双端队列容器
#include <exception>　　　 //异常处理类
#include <fstream>
#include <functional>　　　//STL定义运算函数（代替运算符）
#include <limits>
#include <list>　　　　　　//STL线性列表容器
#include <map>　　　　　　 //STL 映射容器
#include <iomanip>
#include <ios>　　　　　　//基本输入／输出支持
#include<iosfwd>　　　　　//输入／输出系统使用的前置声明
#include <iostream>
#include <istream>　　　　 //基本输入流
#include <ostream>　　　　 //基本输出流
#include <queue>　　　　　 //STL队列容器
#include <set>　　　　　　 //STL 集合容器
#include <sstream>　　　　//基于字符串的流
#include <stack>　　　　　 //STL堆栈容器　　　　
#include <stdexcept>　　　 //标准异常类
#include <streambuf>　　　//底层输入／输出支持
#include <string>　　　　　//字符串类
#include <utility>　　　　 //STL通用模板类
#include <vector>　　　　　//STL动态数组容器
#include <cwchar>
#include <cwctype>
using namespace std;
#define inf 0x3f3f3f3f
#define endl '\n'
#define finf -0x3f3f3f3f
#define scNO printf("NO\n");
#define scNo printf("No\n");
#define scno printf("no\n");
#define sc0 printf("0\n");
#define sc1 printf("1\n");
#define	scf1 printf("-1\n");
#define	scz1 printf("1\n");
#define scYES printf("YES\n");
#define scyes printf("yes\n");
#define scYes printf("Yes\n");
#define scyes printf("yes\n");
#define ll long long
#define bug(a)  cout<<"*"<<a<<"*"<<endl;
#define bugg(a,b)  cout<<"*"<<a<<"*"<<b<<endl;
#define buggg(a,b,c)  cout<<a<<"*"<<b<<"*"<<c<<endl;
#define bugggg(a,b,c,d)   cout<<a<<"*"<<b<<"*"<<c<<"*"<<d<<endl;
#define bug1  cout<<"*******************************************"<<endl;
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define dec(x,y,z) for(int x=y;x>=z;x--)
#define cn cout<<endl;
const long N = 200000;
long prime[N] = { 0 }, num_prime = 0;
int isNotPrime[N] = { 1, 1 };
int   read()  //read quickly
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    return x * f;
}
void sushushai(int  m)
{
    for (long i = 2; i < m; i++)
    {
        if (!isNotPrime[i])
            prime[num_prime++] = i;
        for (long j = 0; j < num_prime && i * prime[j] < N; j++)
        {
            isNotPrime[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
        }
    }
}

void cheng(int* a, int c)		//High precision multiplication
{
    int jw = 0;
    for (int i = 1; i <= 1000; i++)
    {
        a[i] = a[i] * c + jw;
        jw = a[i] / 10;
        a[i] %= 10;
    }
}
int cl(int x, int n) //High precision Division
{
    int s = 0, i = 0, w[101];
    while (x >= 1)
    {
        w[++i] = x % n;
        x = x / n;
    }
    for (int j = i; j >= 1; j--)
        s = s * 10 + w[j];
    return s;
}
void pplus(int* a, int* c) //High precision addition
{
    int jw = 0;
    for (int i = 1; i <= 1000; i++)
    {
        c[i] += a[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }
}
long long A(int n, int m) //(n)*(n-1)*(n-2)*....(n-m)
{
    long long ret = 1;
    for (int i = 0; i < m; ++i)
    {
        ret *= (n - i);
        // ret%=mod;
    }
    return ret;
}

int c(int m, int n) //c(5,1)==c(5,4)
{
    int a = 1, b = 1;
    n = min(n, m - n);
    if (n == 0)
        return 1;
    for (int i = m; i >= m - n + 1; i--)
        a = a * i;
    for (int i = 1; i <= n; i++)
        b = b * i;
    return a / b;
}


long long quickpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a;
        }
        a = a*a;
        b >>=1;
    }
    return ret;
}
long long quickpowmod(long long a, long long b,long long modd) {
    long long ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a%modd;
        }
        a = a * a%modd;
        b >>=1;
    }
    return ret;
}
const int MAXN = 200005;
const long long mod = 1e9 + 7;
/*************I***************M**********qwq-qwq-qwq-qwq-qwq-qwq-qwq*******************************************************/
/*************L************** Q*************OVO-OVO-OVO-OVO-OVO-OVO-OVO***********************************************/
/************ O************** J***************QAQ-QAQ-QAQ-QAQ-QAQ-QAQ-QAQ********************************************/
/*************V************** D****************Orz-Orz-Orz-Orz-Orz-Orz-Orz-Orz-Orz***** ************************************/
/*************Y************** O**************************************************************** ************************* *******/
/*************O*************  Y******************WyqWyqWyqWyq ********************** ******************** ***************/
/*************U**************O******************yyyy******************************************** ************* ********** ***/
/*************3************** U******************ZzzzZzzzZzzz~~******************************************** **************/
/*************0************** B******************************************************************************** ************/
/*************0************** E********************************************************************************** *********/
/*************0************** S********Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds*********** ********* /
/*************0************** T********Ljjunyyds-Ljunyyds-Ljjunyyds-Ljjunyyds-Ljunyyds-Ljunyyds********** ********/
/*************T************************longyyds-longyyds-longyyds-longyyds-longyyds-longyyds*****************/
/************* i************************Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds-Zkssyyds*****************/
/*************m**************** *******Ljjunyyds-Ljunyyds-Ljjunyyds-Ljjunyyds-Ljunyyds-Ljunyyds**************/
/*************e*************************longyyds-longyyds-longyyds-longyyds-longyyds-longyyds************/
/*************s***************************************************************************************END******/

const int maxn=2e5+10;
int main()
{
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    	int wight,h,x1,x2,y1,y2,Wight,Hight;
    	cin>>Wight>>Hight>>x1>>y1>>x2>>y2>>wight>>h;
    	int xx=abs(x1-x2),yy=abs(y1-y2);
    	if(xx+wight<=Wight|| yy+h<=Hight){
    		int ans=1e9;
    		if(xx+wight<=Wight){
    			ans=min(ans,wight-x1);
    			ans=min(ans,x2-(Wight-wight));
			}
			if(yy+h<=Hight){
				ans=min(ans,h-y1);
    			ans=min(ans,y2-(Hight-h));
			}
			if(ans<0)
                ans=0;
			else
                cout<<ans<<".000000000"<<endl;
		}
		else{
			cout<<-1<<endl;
		}

    }
    return 0;
}

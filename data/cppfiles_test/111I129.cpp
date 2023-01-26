/*
                  قال تعالى
قَالَ يَا قَوْمِ أَرَأَيْتُمْ إِن كُنتُ عَلَىٰ بَيِّنَةٍ مِّن رَّبِّي وَرَزَقَنِي مِنْهُ رِزْقًا حَسَنًا ۚ
وَمَا أُرِيدُ أَنْ أُخَالِفَكُمْ إِلَىٰ مَا أَنْهَاكُمْ عَنْهُ ۚ إِنْ أُرِيدُ إِلَّا الْإِصْلَاحَ مَا اسْتَطَعْتُ ۚ
      وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ
*/
//============================================================================
// Name        : ahmednserEl-Din.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// s.replace(s.find("EGYPT") , 5 , " ");
  /*int cntr = count(s.begin(), s.end(), 'a');
   s.replace(0 ,5, "Mohamed ");*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <bitset>
#include <array>
#include <deque>
#include <utility>
#include <stack>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <ctime>
#include <valarray>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define Fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define du double
#define ld long double
#define ull unsigned long long
#define en endl
#define pb push_back
#define pf push_front
#define po pop_back
#define _pq priority_queue
#define F first
#define S second
#define pi acos(-1)
#define be(s) (s).begin() , (s).end()
#define eu(s) s.erase(unique(be(s)),s.end())
#define fs(n) fixed<<setprecision(n)
#define clr(x , v , l) memset(x , v , sizeof(x))
#define loop(n) for(int i = 0; i < n; i++)
#define cin_arr(arr,n) loop(n)cin >> arr[i];
#define cout_arr(arr,n) loop(n)cout << arr[i] << ' ';
#define test_cases int t;cin>>t;while(t--)
#define trans_tolower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define trans_toupper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define txt freopen("input.txt", "rt", stdin);freopen("output.txt", "wt", stdout);
#define mod 1000000007
bool b[100003]={};
using namespace std;
ll gcd(ll a, ll b)
{
 if (a == 0) return b;
 gcd(b%a , a);
}
ll lcm(ll a, ll b)
{
    return (a * b / __gcd(a, b));
}
ll fact (ll j)
{
    if(j <= 1 )
        return 1;
    return j * fact(j-1);
}
long long combina (long long n, long long r)
{
    return fact(n)/(fact(r)*fact(n-r));

}
bool fun_prime(int num)
{
    for(int i = 2; i <= sqrt(num);i++)
        if(num %  i == 0 || num <= 1)
        	return false;
    return true;
}
bool visited[1000];
void scan(int node, vector<vector<int>> graph){
	cout << node << endl;
	visited[node] = true;
	for(auto child: graph[node]){
		if(!visited[child])
			scan(child, graph);
	}

}
int main(int argc, char* argv[])
{
	int n;
	test_cases{
		cin >> n;
		string s1(n-1,'(');
		string s2(n-1,')');
		string s3="()";
		s1 += s2;
		if(n==1){
			cout<<s3;
			continue;
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < s1.size(); j++)
			{
				if(i == j)
					cout << s3;
				cout << s1[j];
			}
			cout << endl;

		}

	}



	return 0;
}











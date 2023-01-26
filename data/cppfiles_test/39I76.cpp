#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
 
using namespace std;
 
typedef long long ll;
 
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
const int MOD = 1'000'000'007;
const int MX = 400'005;
//long double PI = 3.14159265358979323846264338327950;

int n;

int pergunta_a(int pos){
	
	cout<<"? ";
	
	for(int i=1; i<=n; i++){
		if(i!=pos) cout<<"2 ";
		else cout<<"1 ";
	}
	cout<<'\n';
	cout.flush();
	
	int y; cin>>y;
	return y;
}

int pergunta_b(int pos){
	
	cout<<"? ";
	
	for(int i=1; i<=n; i++){
		if(i!=pos) cout<<"1 ";
		else cout<<"2 ";
	}
	cout<<'\n';
	cout.flush();
	
	int y; cin>>y;
	return y;
}

void caso_teste(){
	
	cin>>n;
	
	int predecessor[n+1];
	int sucessor[n+1];
	int ans[n+1];
	int inicio;
	int fim;
	
	for(int i=1; i<=n; i++){
		int a=pergunta_a(i);
		if(a==0){
			ans[i]=1;
			predecessor[i]=-1;
			inicio=i;
		}else if(a!=i){
			predecessor[i]=a;
			sucessor[a]=i;
		}
	}
	
	for(int i=1; i<=n; i++){
		int b=pergunta_b(i);
		if(b==0){
			ans[i]=n;
			sucessor[i]=-1;
			fim=i;
		}else if(b!=i){
			sucessor[i]=b;
			predecessor[b]=i;
		}
	}
	
	for(int i=1; i<=n; i++){
		cout<<sucessor[i]<<' ';
	}
	cout<<'\n';
	
	int y=sucessor[inicio];
	int cont=2;
	while(cont<n){
		ans[y]=cont;
		cont++;
		y=sucessor[y];
	}
	
	cout<<"! ";
	for(int i=1; i<=n; i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
	cout.flush();
}
	
int main(){
	
	cin.tie(0);ios_base::sync_with_stdio(0);
	//freopen ("in.txt","r",stdin);
	
	int n_casos=1; //cin>>n_casos;
	
	/*roubar o test_case
	for(int i=1; i<=n_casos; i++){
		if(i==MOD){
			int n,k;
			cin>>n>>k; cout<<n<<' '<<k<<'\n';
			int a,b;
			for(int j=1; j<n; j++){
				cin>>a>>b;
				cout<<a<<' '<<b<<'\n';
			}
		}else{
			caso_teste();
		}
	}
	*/
	while(n_casos--) caso_teste();
}
/*
5
1
2
0
4
1
1
1
2
0
4
*/

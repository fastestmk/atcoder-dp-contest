#include<iostream>
#include<vector>

using namespace std;

#define ll long long 

const int INF = 1e9+5;

int main(){
	int n;
	cin >> n;
	vector<int> height(n);
	for(int i = 0; i < n; ++i){
		cin >> height[i];
	}
	vector<int> dp(n, INF);
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j : {i+1, i+2}){
			if(j < n){
				dp[j] = min(dp[j], dp[i] + abs(height[i]-height[j]));
			}
		}
	}
	cout << dp[n-1] << endl;
}
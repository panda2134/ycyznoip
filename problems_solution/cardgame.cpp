/*
	CODEVS 1704 
	By panda_2134
*/
#include<iostream>
#include<deque>
using namespace std;
int main(){
	deque<int> cards;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cards.push_back(i);
	while(cards.size()>=2){
		cout<<cards.front()<<" ";
		cards.pop_front();
		cards.push_back(cards.front());
		cards.pop_front();
	}
	cout<<cards.front();
	return 0;
}

#include <iostream>
#include <vector>
#include <ios>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
struct word{
	int num;
	string s;
};
istream& read(istream& in, vector<word>& vec){
	word w;
	w.num = 1;
	while(in >> w.s){ //不是while(in)
		int flag = w.num;
		vector<string>::size_type size = vec.size();
		for (int i = 0; i != size; i++){
			if (w.s == vec[i].s){
				vec[i].num++;
				flag = vec[i].num;
			}
		}
		if (flag == 1)
			vec.push_back(w);
	}
	in.clear();
	return in;
}
int main(){
	vector<word> w;
	read(cin, w);
	typedef vector<word>::size_type vec_sz;
	vec_sz size = w.size();
	int numOfWord = 0;
	for (int i = 0; i != size; i++)
		numOfWord += w[i].num;
	string::size_type maxLen = 0;
	cout << "The number of words are: " << numOfWord << endl;
	for (vec_sz i = 0; i != size; i++)
		maxLen = max(maxLen, w[i].s.size());
	for (vec_sz i = 0; i != size; i++){
		cout << setw(maxLen);
		cout << w[i].s << setw(3) << w[i].num << endl;
	}
	return 0;
}
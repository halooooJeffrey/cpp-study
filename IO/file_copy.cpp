#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char x;
	FILE *in_fp = fopen("c:\\users\\jeffrey\\desktop\\data.txt", "r");
	if (in_fp == NULL){
		cerr << "can not open!" << endl;
		exit(-1);
	}
	FILE *out_fp = fopen("c:\\users\\jeffrey\\desktop\\mydata.txt", "w");
	if (out_fp == NULL){
		cerr << "can not open!" << endl;
		exit(-1);
	}
	while (!feof(in_fp)){
		x = fgetc(in_fp);
		fputc(x, out_fp);
	}
	fclose(in_fp);
	fclose(out_fp);
	return 0;
}
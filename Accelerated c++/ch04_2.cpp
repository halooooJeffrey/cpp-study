#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ios>
#include <iomanip>
using namespace std;
struct Student_info{
	string name;
	double midterm, final;
	vector<double> homework;
};
double grade(double midterm, double final, double homework){
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}
double median(vector<double> vec){
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");
	sort(vec.begin(), vec.end());
	vec_sz mid = size / 2;
	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
double grade(double midterm, double final, const vector<double>& hw){
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm, final, median(hw));
}
istream& read_hw(istream& in, vector<double>& hw){
	if (in){
		hw.clear();
		double x;
		while (in >> x)
			hw.push_back(x);
		in.clear(); //因为不清除的话，错误标记一直在in中，后面无法输入
	}
	return in;
}
bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name; //string
}
istream& read(istream& is, Student_info& s){
	is >> s.name >> s.midterm >> s.final;
	read_hw(is, s.homework);
	return is;
}
double grade(const Student_info& s){
	return grade(s.midterm, s.final, s.homework);
}

int main(){
	vector<Student_info> student;
	Student_info record;
	string::size_type maxlen = 0;
	while (read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		student.push_back(record);
	}
	sort(student.begin(), student.end(), compare);
	for (vector<Student_info>::size_type i = 0; i != student.size(); i++){
		cout << setw(maxlen + 1) << student[i].name;
	try{
		double final_grade = grade(student[i]);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	} catch (domain_error e){
		cout << e.what();
	}
	cout << endl;
	}
	return 0;
}
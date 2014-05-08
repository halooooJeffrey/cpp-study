//6.1分析字符串
for (vector<string>::const_iterator it = bottem.begin(); it != bottom.end(), ++it){
	ret.push_back(*it);
}

ret.insert(ret.end(), bottom.begin(). bottom.end());

copy(bottom.begin(), bottom.end(), back_inserter(ret));

//6.1.1 另一个实现split的方法
bool space(char c){
	return isspace(c);
}
bool not_space(char c){
	return !isspace(c);
}
vector<string> split(const string& str){
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	while (i != str.begin()){
		i = find_if(i, str.end(), not_space);
		iter j = find_if(i, str.end(), space);
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

//6.1.2 回文
bool is_palindrome(const string& s){
	return equal(s.begin(), s.end(), s.rbegin());
}
//rbegin返回一个迭代器，这个迭代器会从容器的最后一个元素开始，并且从后向前地
//逆向访问容器
//equal函数比较了两个序列以判断他们是否包含有相等的值。头两个迭代器指定了第一
//个序列，第三个参数则是第二个序列的起点，equal函数假定第二个序列的长度与第一个相同

//6.1.3 查找URL
vector<string> find_urls(const strong& s){
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = s.begin(), e = s.end();
	while (b != e){
		b = url_beg(b, e);
		if (b != e){
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}
string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
	return find_if(b, e, not_url_char);
}
bool not_url_char(char c){
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_end());
}
//我们仅仅在第一次调用not_url_char的时候构造并初始化字符串url_ch，而随后的调用
//将使用第一次调用所构造的对象
//isalnum()在<cctype>，这个函数将检测它的参数是否是一个字母或一个数字
//find找特定的值即第三个参数，找到返回一个迭代器，只是了第一次出现这个值的位置，没找到返回
//第二个参数
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
	static const string sep = "://";
	typedef string::const_iterator iter;
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e){
		if (i != b && i + sep.size() != e){
			iter beg = i;
			while (beg != b && isalpha(beg[-1]))
				--beg;
			if (beg != i && i + sep.size() != e && !not_url_char(i[sep.size()]))
				return beg;
		}
		if (i != e)
			i += sep.size();
		}
		return e;
	}
}
//search函数有两对迭代器参数，第一对指示了我们要查找的序列，而第二对则指示了一个
//序列--我们希望为这个序列定位，即指示“：”

//6.2.1 处理学生记录
bool did_all_hw(const Student_info& s){
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}
vector<Student_info> did, didnt;
Student_info student;
while (read(cin, student)){
	if (did_all_hw(student))
		did.push_back(student);
	else
		didnt.push_back(student);
}
if (did.empty()){
	cout << "No student did all the homework!" << endl;
	return 1;
}
if (didnt.empty()){
	cout << "Every student did all the homework!" << endl;
	return 1;
}
//empty函数当容器为空时返回true

//6.2.2 分析成绩
double median_analysis(const vector<Student_info>& students){
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade);
	return median(grades);
}
//transform函数的参数是三个迭代器和一个函数，开头的两个迭代器指定了待转换元素的区间，
//第三个迭代器是一个目的地，它将保存函数的运行结果，第四个参数是一个函数，transform
//将这个函数应用于输入序列的每个元素中以获得输出序列中的对应元素
//grade函数有几个重载的版本，不知道应该调用哪一个版本，而且无法处理异常

//辅助函数，明确地调用grade
double grade_aux(const Student_info& s){
	try{
		return grade(s);
	}
	catch (domain_error){
		return grade(s.midterm, s.final, 0);
	}
}

//thus
double median_analysis(const vector<Student_info>& students){
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
	return median(grades);
}

//使用write_analysis比较两个学生数据集合
void write_analysis(ostream& out, const string& name, souble analysis(const bector<Student_info>&),
					const vector<Student_info>& did, const vector<Student_info>& didnt){
	out << name << ": median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

int main(){
	vector<Student_info> did, didnt;
	Student_info student;
	while (read(cin, student)){
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}
	if (did.empty()){
		cout << "No student did all the homework!" << endl;
		return 1;
	}
	if (didnt.empty()){
		cout << "Every student did all the homework!" << endl;
		return 1;
	}
	write_analysis(cout ,"median", median_analysis, did, didnt);
	write_analysis(cout, "average", average_analysis, did, didnt);
	write_analysis(cout, "median of homework turned in", optmistic_median_analysis, did, didnt);
	return 0;
}

double average(const vector<double>& v){
	return accumulate(v.begin(), v.end(), 0.0)
}
//accumulate在numeric头文件中，从第三个参数开始，第三个参数决定了类型

double average_grade(const Student_info& s){
	return grade(s.midterm, s.final, average(s.homework));
}
double average_analysis(const vector<Student_info>& students){
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), average_grade);
	return median(grades);
}
double optmistic_median(const Student_info& s){
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
	if (nonzero.empty())
		return grade(s.midterm, s.final, 0);
	else
		return grade(s.midterm, s.fianl, median(nonzero));
}

//6.3.1 一种两次传递的解决方案
vector<Student_info> extract_fails(vector<Student_info>& students){
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
	students.erase(remove_if(students.begin(), students.end(), fgrade), student.end());
	return fail;
}
//在原先的程序中，我们使用了一个名为iter的迭代器来向前访问容器，同时把成绩不及格的记录复制进fail中
//并使用erase成员函数来从students中清除这些记录，这里使用remove_copy_if函数来把不及格的成绩复制进fail中
//与remove_copy相似，只不过使用一个谓词而不是一个值。
bool pgrade(const Student_info& s){
	return !fgrade(s);
}
//remove_if来“删除”与不及格成绩相对应的元素。加引号实际上没有删除，因为remove_if使用了同一个的序列来作为
//它的源和目的地，实际上它所作的是把不满足谓词的元素复制到序列的开头。remove_if返回一个迭代器，这个迭代器
//指向最后一个不被删除的元素后面的那个位置
//这里的erase两个迭代器参数是删除它们之间的元素

//6.3.2 一种一次传递的解决方案
vector<Student_info> extract_fails(vector<Student_info>& students){
	vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), pgrade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());
	return fail;
}
//另一个角度：它以一个序列作为参数并重新排列元素，以使满足谓词的元素排在那些不满足谓词的元素之前
//partition可能会在每一种类内部重新排列元素，而stable_partiton除了划分区域以外还会让各区域内的元素的相互
//顺序保持不变

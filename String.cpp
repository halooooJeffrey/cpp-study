#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
class String
{
	char *str;
public:
	String(){str = NULL;}
	String(const char *p);
	~String();
	int length(){return strlen(str);}
	char &char_at(int i);
	const char *get_str(){return str;}
	String &copy(const char *p);
	String &copy(const String &s){return copy(s.str);}
	String &append(const char *p);
	String &append(const String &s){return append(s.str);}
	int compare(const char *p){return strcmp(str, p);}
	int compare(const String &s){return strcmp(str, s.str);}
	bool is_substring(const char *str);
	bool is_substring(const String &str);
	String substring(int strat, int length);
	int find_replace_str(const char *find_str, const char *replace_str);
	void remove_spaces();
	int to_int();
	void to_lower_case();
};
String::String(const char *p)
{
	str = new char[strlen(p) + 1];
	strcpy(str, p);
}
String::~String()
{
	delete []str;
	str = NULL;
}
String::String(const String &s)
{
	if (s.str == NULL){
		str = NULL;
		return;
	}
	str = new char[strlen(s.str) + 1]; //为什么不能将strlen(s.str)替换成s.length()？
	strcpy(str, s.str);
}
char & String::char_at(int i)
{
	if (i < 0 || i >= strlen(str)){
		cerr << "exceed the range of the character.\n";
		exit(-1);
	}
	return str[i];
}
String & String::copy(const char *p)
{
	char *p1 = new char[strlen(p) + 1];
	strcpy(p1, p);
	delete []str;
	str = p1;
	return *this;
}
String & String::append(const char *p)
{
	char *p1 = new char[strlen(str) + strlen(p) + 1];
	strcpy(p1, str);
	strcat(p1, p);
	delete []str;
	str = p1;
	return *this;
}
String String::substring(int start, int length)
{
	String temp;
	char *p = new char[length + 1];
	for (int i = start, j = 0; i <= length - 1 + start; i++){
		p[j] = str[i]; //如果直接temp.str[j]需要先给temp中的str分配空间，而默认构造函数没有分配空间。
		j++;
	}
	p[length] = '\0';	//最后补上终止符
	temp.copy(p);
	return temp;	//因为返回的是个String，又数据成员中有个指针变量，所以需要一个拷贝构造函数，见定义。
}
bool String::is_substring(const char *p)
{
	int len = strlen(p);
	for (int i = 0; i <= (*this).length() - len; i++){	//一段段提取出来与p比较，相等就true，for循环结束，说明没有相等，false
		String sub_str = (*this).substring(i, len);
		if (!sub_str.compare(p))	//compare函数相等返回0
			return true;
	}
	return false;
}
bool String::is_substring(const String &s)	//与上相同
{
	int len = strlen(s.str);
	for (int i = 0; i <= (*this).length() - len; i++){
		String sub_str = (*this).substring(i, len);
		if (!sub_str.compare(s))
			return true;
	}
	return false;
}
int String::find_replace_str(const char *find_str, const char *replace_str) //只是简单的将replace_str的长度和find_str的长度看作相等，也有可能小于或大于
{																			//这时候需要移位，简单一点可以另外创造一个String，一位位放进去，然后（*this)与这个
	int count = 0;															//String相等
	int len = strlen(find_str); 
	for (int i = 0; i <= (*this).length() - len; i++){						//效率的做法是将*this).length() - len在循环外计算好
		String sub_str = (*this).substring(i, len);
		if (!sub_str.compare(find_str)){
			count++;
			for (int j = i, k = 0; j < i + len; j++){
				str[j] = replace_str[k];
				k++;
			}
		}
	}
	return count;
}
void String::remove_spaces()
{
	int len = (*this).length();
	for (int i = 0; i < len; ++i){
		if (str[i] == ' '){
			for (int j = i; j < len - 1; j++){
				str[j] = str[j + 1];	//将后面的补过来
			}
			--i;	//为了移位以后还是从去掉空格的地方算起，不减就会++，会从后一个算起，这是为了避免出现连续空格而删不掉
			str[--len] = '\0'; //补过来以后终止位要前移一位
		}	
	}
}
int String::to_int()	//前提是这个数字字符串的位数不能超过int类型的位数
{
	int sum = 0;
	int len = (*this).length();
	for (int i = 0; i < len; i++)
		sum = sum + (str[i] - '0');	//str[i] - '0'是将字符数字转换成传统的数字
	return sum;
}
void String::to_lower_case()
{
	int len = (*this).length();
	for (int i = 0; i < len; i++){
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}
int main()
{
	String str1("abcdefghijklmn");
	String str2("defghi");
	String str3("jahsiw");
	String str4("shjkdaswidhaswdjwiepaswld");
	String str5("ab       cd ef gh ij k");
	String str6("2836490");
	String str7("AbCdEfGh");
	cout << "字符串1为:" << str1.get_str() << endl;
	cout << "提取从第0个开始，长度为5的子串：";
	cout << str1.substring(0, 5).get_str() << endl;
	cout << "hijk";
	if (str1.is_substring("hijk"))
		cout << "是字符串abcdefghijklmn的子串" << endl;
	else
		cout << "不是字符串abcdefghijklmn的子串" << endl;
	cout << "shwiu";
	if (str1.is_substring("shwiu"))
		cout << "是字符串abcdefghijklmn的子串" << endl;
	else
		cout << "不是字符串abcdefghijklmn的子串" << endl;
	cout << str2.get_str();
	if (str1.is_substring(str2))
		cout << "是字符串abcdefghijklmn的子串" << endl;
	else
		cout << "不是字符串abcdefghijklmn的子串" << endl;
	cout << str3.get_str();
	if (str1.is_substring(str3))
		cout << "是字符串abcdefghijklmn的子串" << endl;
	else
		cout << "不是字符串abcdefghijklmn的子串" << endl;
	cout << "字符串4是：" << str4.get_str() << "我们从中找出asw字符串并将它替换成000,替换次数为：" << str4.find_replace_str("asw", "000") 
		<< "替换后为: " << str4.get_str() << endl;
	cout << "字符串5为：" << str5.get_str() << ",我们去掉空格，去掉后为：";
	str5.remove_spaces();
	cout << str5.get_str() << endl;
	cout << "数字字符串6为：" << str6.get_str() << "将它转化成整数为：" << str6.to_int() << endl;
	cout << "字符串7为：" << str7.get_str() << "将其中的大写字母转换成小写字母,转换后为：";
	str7.to_lower_case();
	cout << str7.get_str() << endl;
	return 0;
}

// 
//

#include <iostream>
#include <vector>
#include <fstream>
#include "Binary_Search_Tree.h"
#include <map>

using namespace std;

vector<string> split(string c, char delimeter) {

	vector<string> v;
	string s = "";
	for (int i = 0;i < c.size();i++) {
		if (c[i] == delimeter ) {
			v.push_back(s);
			s = "";
		}
		else {
			s += c[i];
		}
	}
	v.push_back(s);
	return v;
}


int main()
{
	//vector<std::string> expression { "/", "*", "5" ,"NULL","NULL","3","NULL","NULL","-","6","NULL","NULL","*","2","NULL","NULL","1" };
	vector<MorseCode> vtree;
	map<char, string> morseCodeMap;

	ifstream fin("morse.txt");
	if (!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	// While there's data in the file, read in a line and calcuate it
	while (fin.good())
	{
		
		string line;
		fin >> line;

		string s(1, line.at(0));

		MorseCode m = MorseCode(s, line.substr(1, line.size()));
		morseCodeMap.insert(pair<char, string>( m.GetLetter()[0], m.GetCode()));
		vtree.push_back(m);
	}
	

	//GENERATE TREE
	Binary_Search_Tree<string> the_tree;
	the_tree.insert("ROOT");

	for (int i = 0;i < vtree.size();i++) {
		the_tree.insert(vtree[i].GetLetter(), vtree[i].GetCode());

	}
	cout<<the_tree.to_string();
	int height = the_tree.height();


	//DECODE 
	string decode = "_.. __.";
	vector<string> vdecode= split(decode, ' ');
	string sdecoded = "";
	for (int i = 0;i < vdecode.size();i++) {
		sdecoded+=the_tree.decode(vdecode[i]);
	}
	cout << "Decoded String:" << sdecoded<<endl;

	//ENCODE
	string encode = "ac";
	string sencoded = "";
	for (int i = 0;i < encode.size();i++) {
		sencoded+=morseCodeMap[encode[i]]+" ";

	}
	cout << "encoded String:" << sencoded <<endl;


}


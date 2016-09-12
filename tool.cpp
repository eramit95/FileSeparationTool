#include<iostream>
#include<cstring>
#include<string>
#include<fstream>

using namespace std;
void createDotH(const char*s,const ifstream &fin){
	char arr[100];
	strcpy(arr,s);
	strcat(arr,".h");
	ofstream fout(arr);
}
void createDotCPP(const char*s,ifstream&fin){
	char arr[100];
	strcpy(arr,s);
	strcat(arr,".cpp");
	ofstream fout(arr);
}

int main(){
	char path[]="main2.cpp";
	//I need to create this a string array...
	char arr[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	string sarr[5];
	string s, sub;
	int k=0;
	ifstream fin(path);
	ofstream fout;
	while(!fin.eof()){
		getline(fin,s);
		int i=0;
		while(s[i] != '\n'){
			if((s[i]=='c') && (s[i+1]=='l') && (s[i+2]=='a') && (s[i+3]=='s') && (s[i+4]=='s') && (s[i+5]==' ')){
				int j =0;
				i=i+6;
				while(s[i]!='{'){
					arr[j]=s[i];
					i++;
					j++;
				}
				string str(arr);
				sarr[k] = str;
				k++;
				break;
			}
			i++;				
		}
	}

	for(int ii=0; ii<5; ii++){
		if(sarr[ii] != ""){
			createDotH(sarr[ii].c_str(),fin);
			createDotCPP(sarr[ii].c_str(),fin); 	
		}
	}
	int i =0, j =1;
	k=0;
	fin.clear();
	fin.seekg(0);
	while(!fin.eof()){
		getline(fin, s);
		//for inserting all includes
		if(s.find("#") != string::npos || s.find("using") != string::npos){
			sub = sub + "\n" + s;
			k++;
		}
		//TO CREATE FILE OUTPUTS FOR .H
		if(sarr[i] != "" && s.find("class ") != string::npos){
			string str = sarr[i] + ".h";
			fout.open(str.c_str(), ios::out | ios::app);
			fout << sub << endl;
			fout << s << endl;
			i++;
		}
		if(fout.is_open()){
			if(s.find("}") != string::npos){
				j--;
			}
			if(j==0){
				fout << "};" << endl;
				fout.close();
				j=1;
			}
			else if(!( s.find("class ") != string::npos) && !(s.find("{")!= string::npos) && j == 1 && !(s.find("}")!= string::npos)){
				fout << s << endl;
			}
			if(s.find("{")!= string::npos && !( s.find("class ") != string::npos)){
				fout << s.replace(s.find("{"),1,";") << endl;
				j++;
			}
		}	
	}
	fin.close();
}

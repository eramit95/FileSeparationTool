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
	int i =0 ;
	k=0;
	while(!fin.eof()){
		getline(fin, s);
		//for inserting all includes
		if(s[0] =='#'){
			sub = sub + s;
			k++;
		}
		//TO CREATE FILE OUTPUTS FOR .H
		if(sarr[i] != ""){
			ofstream fout(sarr[i]+".h");
			fout << s;
		}	
	}
	fin.close();
}

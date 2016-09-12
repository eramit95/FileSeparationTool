#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;
void createDotH(char*s,const ifstream &fin){
	char arr[100];
	strcpy(arr,s);
	strcat(arr,".h");
	ofstream fout(arr,ios::app);
}
void createDotCPP(char*s,ifstream&fin){
	char arr[100];
	strcpy(arr,s);
	strcat(arr,".cpp");
	ofstream fout(arr,ios::app);

}
int main(){
	char path[] = "main.cpp";
	char arr[100];
	string s;
	ifstream fin(path);
	while(!fin.eof()){
		getline(fin,s);
		int i=0, j=0;
		while(s[i] != '\0'){
			if(s[i]=='c'&&s[++i]=='l'&&s[++i]=='a'&&s[++i]=='s'&&s[++i]=='s'&&s[++i]==' '){
				while(s[i]!='{'){
					arr[j]=s[i];
					i++;
					j++;
				}
				arr[j]='\0';
				cout<<"hello";
				createDotH(arr,fin);
                createDotCPP(arr,fin);
				memset(arr,0,100);
				break;
			}
			i++;

		}
		if(strcmp(arr,"")){
			createDotH(arr,fin);
			createDotCPP(arr,fin);
		}
	}
}

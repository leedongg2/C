#include <iostream>
#include <vector>
using namespace std;
class contacts{
public:
	string name, num, mail;
};
class phone{
private:
	vector <contacts> contact;
	int f;
public:
	void add(){
		contacts c;
		cout<<"name: "<<endl;
		cin.ignore();
		getline(cin,c.name);
		cout<<"phone number: "<<endl;
		getline(cin,c.num);
		cout<<"mail: "<<endl;
		getline(cin,c.mail);
		cout<<endl;
		contact.push_back(c);
	}
	void allprint(){
		for(f=0;f<contact.size();f++){
			cout<<"name: "<<contact[f].name<<" phone number: "<<contact[f].num<<" mail: "<<contact[f].mail<<endl;
		}
	}
	void find(){
		string finding;
		cout<<"name"<<endl;
		cin>>finding;
		for(f=0;f<contact.size();f++){
			if(finding==contact[f].name){
				cout<<"name: "<<contact[f].name<<" phone number: "<<contact[f].num<<" mail: "<<contact[f].mail<<endl;
				return;
			}
			
		}
		cout<<"찾는 연락처가 없습니다"<<endl;
	}
	void delet(){
		string what;
		char ans;
		cin>>what;
		for(f=0;f<contact.size();f++){
			if(what==contact[f].name){
				cout<<"Do you want to delete this number?(Y/N)";
				cin>>ans;
				if(ans=='Y'){
					contact.erase(contact.begin()+f);
					cout<<"deleted"<<endl;
				}
				else{
					cout<<"canceled"<<endl;
					return;
				}
			}
		}
	}		
};
int main(){
	int a,b=0,c,f;
	phone Phone;
	while(true){
		cout<<"1.add phone number"<<'\n'<<"2.print all phone number"<<'\n'<<"3.search phone number"<<'\n'<<"4.delete phone number"<<'\n'<<"5.modify phone number"<<'\n'<<"6.end this progam"<<endl;
		cout<<"write number"<<endl;
		cin>>a;
		switch(a){
			case 1:Phone.add(); break;
			case 2:Phone.allprint(); break;
			case 3:Phone.find(); break;
			case 4:Phone.delet(); break;
			case 5:cout<<"꼬우면 니가 만들던가"; break;
			case 6:b++; break;
		}
		if(b!=0){
			break;
		}
	}
	
}

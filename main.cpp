#include <bits/stdc++.h>
#include <fstream>
using namespace std;
//section 2: there is question
class Student{
public:
int id;
char name[30];
};
void writeRecords(){
fstream file;
   file.open("student.txt",ios::out|ios::app);
     char c='Y';
    Student s;
//هنا ليه عرفنا الاوبجيكت بره اللوب . هنا انا عملت اوبجيكت واحد بس وبغير في بياناته مش بعمل كذا ريكورد
    do{

    cout<<"what is your id? : ";
    cin>>s.id;
    cout<<"What is your name? : ";
    cin>>s.name;
    file.write((char*)&s,sizeof s);
        cout <<"Entre records again? (Y/N)"<<endl;
        cin>>c;
    }
    while (c=='Y');
    file.close();
}

// section 3
void readSimpleText(){

char ch,str[20];
    fstream input;
    input.open("test.txt", ios::in);
    if (input.is_open()){
        input>>str;
        cout <<str<<endl;
        input.get(ch);
        cout<<ch<<endl;
         input.get(str,20);
        cout <<str<<'\n';
        input.close();

    }
    else cout<<"Cannot work!"<<endl;

}
void Read_Record(){
    Student s;
    fstream input;
    input.open("student.txt", ios::in);
    if (input.is_open())
    {
        input.read((char*)&s,sizeof(s));
        while(!input.eof())
        {
            cout<<s.id<<'\t'<<s.name<<endl;
            input.read((char*)&s,sizeof(s));

        }
        input.close();

    }
    else cout<<"Cannot work!"<<endl;


}

//section 4
void searchRecord(){
    bool found=false;
    Read_Record();
    char name[20];
    cout<<"Entre the name you want get!\n";
    cin>>name;

    Student s;
    fstream input;
    input.open("student.txt", ios::in);
    if (input.is_open())
    {
        input.read((char*)&s,sizeof(s));
        while(!input.eof())
        {
            if(!strcmp(name,s.name))
            {
                cout<<s.id<<'\t'<<s.name<<endl;
                found=true;
            }
            input.read((char*)&s,sizeof(s));
        }
        if (!found) cout<<"not found!\n";

        input.close();

    }
    else cout<<"can bot work "<<endl;

}
void searchrecord_int(){
     bool found=false;
    Read_Record();
    int idno;
    cout<<"Entre the number you want get!\n";
    cin>>idno;

    Student s;
    fstream input;
    input.open("student.txt", ios::in);
    if (input.is_open())
    {
        input.read((char*)&s,sizeof(s));
        while(!input.eof())
        {
            if(idno==s.id)
            {
                cout<<s.id<<'\t'<<s.name<<endl;
                found=true;
            }
            input.read((char*)&s,sizeof(s));
        }
        if (!found) cout<<"not found!\n";

        input.close();

    }
    else cout<<"can not work "<<endl;

}
void seekingFiles(){
    fstream in;
    in.open("test.txt");
    if (in.is_open())
    {
        in.seekg(0,ios::end); //go and stop at the end of the file
        cout<<"the length of the file is: "<<in.tellg()<<endl;
        in.close();
    }
}
int main()
{

    return 0;
}

#include<fstream>
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

int main(){

/*出力フォーム*/
  cout << "同卓の４人を入力してください" << endl;
  string a,b,c,d;
  cin >> a >> b >> c >> d;

  cout << "着順を入力してください" << endl;
  int p1,p2,p3,p4;
  cout << a << " ";
  cin >> p1;
  cout << b << " ";
  cin >> p2;
  cout << c << " ";
  cin >> p3;
  cout << d << " ";
  cin >> p4;

/*csvへの追加 */
  ofstream out;
  out.open("member.csv",ios::app);

  out << a << "," << p1 << endl;
  out << b << "," << p2 << endl;
  out << c << "," << p3 << endl;
  out << d << "," << p4 << endl;

  out.close();

/*着順の整理 */
  int num=0;
  int nma,nmb,nmc,nmd;
  int suma, sumb, sumc, sumd;
  double moa,mob,moc,mod;
  double ra=1500;
  double rb=1500;
  double rc=1500;
  double rd=1500;

  ifstream ifs("member.csv", ios::in);

  string tmp;
  string tmp_conma;
  string str;
  string v[5];
  v[0]="0.0";
  v[1]="0.0";
  v[2]="0.0";
  v[3]="0.0";
  v[4]="0.0";
  v[5]="0.0";

  while(getline(ifs, tmp)){
    istringstream i_stream(tmp);
    while(getline(i_stream, tmp_conma, ',')){
      if(tmp_conma == a) {
        nma += 1;
        int i=0;
        while(getline(i_stream, str, ',')){
          v[i] = str;
          i++;
        }
        suma = suma + stoi(v[0]);
      }
      if(tmp_conma == b) {
        nmb += 1;
        int i=0;
        while(getline(i_stream, str, ',')){
          v[i] = str;
          i++;
        }
        sumb = sumb + stoi(v[0]);
      }
      if(tmp_conma == c) {
        nmc += 1;
        int i=0;
        while(getline(i_stream, str, ',')){
          v[i] = str;
          i++;
        }
        sumc = sumc + stoi(v[0]);
      }
      if(tmp_conma == d) {
        nmd += 1;
        int i=0;
        while(getline(i_stream, str, ',')){
          v[i] = str;
          i++;
        }
        sumd = sumd + stoi(v[0]);
      }

    }
    }


vector<string> result;
/*結果の書き込み*/

ifstream f("result.csv", ios::in);

string tempp;
string tempp_conma;
string st;

  while(getline(f,tempp)){
    int count = 0;
    istringstream i_str(tempp);
    while(getline(i_str, tempp_conma, ',')){

      if(tempp_conma == a){
        int i=0;
        count ++;
        while(getline(i_str, st, ',')){
          v[i]=st;
          i++;
        }

      moa = (double)(suma)/nma;
      ra = stod(v[3]);
      int q = 0;
      if(p1==1) q=30;
      if(p1==2) q =10;
      if(p1==3) q =-10;
      if(p1==4) q= -30;
      ra = ra + (1-nma*0.002) *q;
      string s1 = to_string(nma);
      string u1 = to_string(suma);
      string t1 = to_string(moa);
      string t2 = to_string(ra);
      string res = a + "," + s1 + "," + u1 + "," + t1 + "," + t2;
      result.push_back(res);
    }

    if(tempp_conma == b){
      int i=0;
      count ++;
      while(getline(i_str, st, ',')){
        v[i]=st;
        i++;
      }

      int q=0;
      if(p2==1){
        q=30;
      }
      if(p2==2){
        q=10;
      }
      if(p2==3){
        q=-10;
      }
      if(p2==4){
        q=-30;
      }

      rb = stod(v[3]);
      rb = rb + (1-nmb*0.002) * q;
      mob = (double)(sumb)/nmb;

    string s1 = to_string(nmb);
    string s2 = to_string(sumb);
    string s3 = to_string(mob);
    string s4 = to_string(rb);
    string res = b + "," + s1 + "," + s2 + "," + s3 + "," + s4;
    result.push_back(res);
  }

  if(tempp_conma == c){
    int i=0;
    count ++;
    while(getline(i_str, st, ',')){
      v[i]=st;
      i++;
    }

  rc = stod(v[3]);
  int q=0;
  if(p3==1)q=30;
  if(p3==2)q=10;
  if(p3==3)q=-10;
  if(p3==4)q=-30;
  rc = rc + (1-0.002*nmc) * q;
  moc = (double)(sumc)/nmc;
  string s1 = to_string(nmc);
  string u1 = to_string(sumc);
  string t1 = to_string(moc);
  string t2 = to_string(rc);
  string res = c + "," + s1 + "," + u1 + "," + t1 + "," +t2;
  result.push_back(res);
}

if(tempp_conma == d){
  int i=0;
  count ++;
  while(getline(i_str, st, ',')){
    v[i]=st;
    i++;
  }

rd = stod(v[3]);
int q=0;
if(p4==1)q=30;
if(p4==2)q=10;
if(p4==3)q=-10;
if(p4==4)q=-30;

rd = rd + (1-0.002*nmd)*q;
mod = (double)(sumd)/nmd;
string s1 = to_string(nmd);
string u1 = to_string(sumd);
string t1 = to_string(mod);
string t2 = to_string(rd);
string res = d + "," + s1 + "," + u1 + "," +t1 +"," +t2;
result.push_back(res);
}
    }
    if(count > 0) continue;

  result.push_back(tempp);

}

  f.close();

    ofstream out1;
    out1.open("result.csv", ios::trunc);

      int t = result.size();
      for(int i=0;i<t;i++){
        out1 << result[i] << endl;
      }

      out1.close();


      ifstream ff("result.csv", ios::in);
        while(getline(ff,str)){
          cout << str << endl;
        }


}

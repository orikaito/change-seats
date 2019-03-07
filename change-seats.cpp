#include <iostream>

#include <stdlib.h>	//http://www.sat.t.u-tokyo.ac.jp/~omi/random_variables_generation.html
#include <time.h>

#include <cctype>	//http://program.station.ez-net.jp/special/handbook/cpp/string/all_of.asp
#include <algorithm>

#include <fstream>	//https://teratail.com/questions/141589

#define VER 0.2
#define MAX_NUM 60	//最大出席番号
#define INPUT_FILE "input.csv"	//入力ファイル名
#define OUPUT_FILE "output.csv"	//出力ファイル名

const short max=60;			//人数（欠番含む）
short seats[10][10]={{-1}};	//[行][列]
bool settled[MAX_NUM]={false};
short count=0;
short col_num=0;
short row_num=0;

long CountNumbersOfTextLines( const char* filePath );//http://www.coderesume.com/modules/answer/?quiz=cpp00700
void get_lost(bool show);
void get_const();
void show();
void lottery();
void output();

int main(){
	std::cout<<"席替えプログラム (c)h28i13 ver"<<VER<<std::endl;
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			seats[i][j]=-1;

	for(int i=0;i<MAX_NUM;i++)
		settled[i]=false;
	while(true){
		std::cout<<"seed値を入力（0~4,294,967,295）（0:UNIX時間をseed値にします）"<<std::endl;
		std::cout<<">>";
		std::string seed;
		std::cin>>seed;
		if(std::any_of(seed.cbegin(), seed.cend(), isdigit)){
			srand(std::stoi(seed));
			break;
		}else{
			std::cout<<"範囲エラー．0か整数を入力してください"<<std::endl;
		}
	}
	get_lost(true);
	get_const();
	for(int i=0;i<MAX_NUM;i++)
		lottery();
	show();
	std::cout<<"抽選結果を"<<OUPUT_FILE<<"に保存しました．"<<std::endl;
	output();
	return 0;
}

long CountNumbersOfTextLines( const char* filePath ){
   	std::ifstream file;
   	file.open( filePath );
    long i = 0;
    if( file ){
		// 1行の長さが255文字以下なので、固定長のバッファでも良い。1文字分多くバッファをつけているのは、文字列終端文字'\0'のスペースのため。
        char buff[256];
        while( true ){
        	file.getline( buff, 256 );
            i++;
            if( file.eof() )
                break;
        }
    }
	return i;
}

void get_lost(bool show){
	std::ifstream stream(INPUT_FILE);
	std::string line;
	const std::string delim = ",";
		// delimを区切り文字として切り分け、intに変換してsettled[]に格納する
	getline(stream, line);
	if(show==true)std::cout<<"欠番:";
    for ( std::string::size_type spos, epos = 0;(spos = line.find_first_not_of(delim, epos)) != std::string::npos;) {
    	std::string token = line.substr(spos,(epos = line.find_first_of(delim, spos))-spos);
		if(std::stoi(token)>0){
			settled[std::stoi(token)-1] = true;
			count++;
			if(show==true)std::cout<<std::stoi(token)<<",";
		}
    }
	std::cout<<std::endl;
}

void get_const(){
	std::ifstream stream(INPUT_FILE);
 	std::string line;
  	const std::string delim = ",";
	int row = 0;
  	int col;
	getline(stream, line);
  	while ( getline(stream, line) ) {
    	col = 0;
    	// delimを区切り文字として切り分け、intに変換してdata[][]に格納する
    	for ( std::string::size_type spos, epos = 0;(spos = line.find_first_not_of(delim, epos)) != std::string::npos;) {
      		std::string token = line.substr(spos,(epos = line.find_first_of(delim, spos))-spos);
      		seats[row][col++] = std::stoi(token);
			if(std::stoi(token)>0){
				count++;
				settled[std::stoi(token)-1]=true;
			}
			if(col>col_num)
				col_num=col;
    	}
    	//++row;
		if(++row>row_num)
			row_num=row;
  	}
}

void show(){
	std::cout<<"     [教卓]"<<std::endl;
	for(int i=0;i<(CountNumbersOfTextLines(INPUT_FILE)-1);i++){
		for(int j=0;j<10;j++){
			if(seats[i][j]==-1){
				std::cout<<"   ";
			}else{
				if(seats[i][j]<10){
					std::cout<<0<<seats[i][j]<<" ";
				}else{
					std::cout<<seats[i][j]<<" ";
				}
			}
		}
		std::cout<<std::endl;
	}
}

void lottery(){
	if(count>MAX_NUM-1){
		return;
	}
	short n=0;
	n=rand()%MAX_NUM;	//rand()%(B-A+1)+A;	AからBまでの乱数
	if(settled[n]==false){
	bool search=true;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(seats[i][j]==0){
				seats[i][j]=n+1;
				count++;
				settled[n]=true;
				search=false;
				return;
			}
		}
	}	
	}else{
		lottery();
	}
}

void output(){
	std::ofstream ofs(OUPUT_FILE,std::ios::app);
	ofs<<"     [教卓]"<<std::endl;
	for(int i=0;i<row_num;i++){
		for(int j=0;j<col_num;j++){
			if(seats[i][j]>0){
				if(seats[i][j]<10){
					ofs<<0<<(int)seats[i][j]<<" ";
				}else{
					ofs<<(int)seats[i][j]<<" ";
				}
			}else if(seats[i][j]==-1){
				ofs<<"   ";
			}
		}
		ofs<<std::endl;
	}
	ofs<<std::endl;
	ofs.close();
}
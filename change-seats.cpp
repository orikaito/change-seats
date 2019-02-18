#include <iostream>

#include <stdlib.h>	//http://www.sat.t.u-tokyo.ac.jp/~omi/random_variables_generation.html
#include <time.h>

#include <cctype>	//http://program.station.ez-net.jp/special/handbook/cpp/string/all_of.asp
#include <algorithm>

#include <fstream>	//https://teratail.com/questions/141589

const char ver[]="0.1";
const char input_file[]="input.csv";
const char output_file[]="output.csv";

short seats[10][10]={{-1}};	//[行][列]
bool settled[60]={false};
short count=0;

long CountNumbersOfTextLines( const char* filePath );//http://www.coderesume.com/modules/answer/?quiz=cpp00700
void get_lost();
void get_const();
void show();
void lottery();
void output();

int main(){
	std::cout<<"席替えプログラム (c)h28i13 ver"<<ver<<std::endl;
	std::cout<<"seed値を入力（0~4,294,967,295）"<<">>";
	unsigned seed;
	std::cin>>seed;
	if(seed==0){srand((unsigned)time(NULL));}
	else{srand(seed);}
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			seats[i][j]=-1;
	while(true){
		std::string s;
		std::cout<<">>";
		std::cin>>s;
		short num;
		if(std::any_of(s.cbegin(), s.cend(), isdigit)){num=std::stoi(s);}
		else{std::cout<<"err"<<std::endl<<std::endl;continue;}
		if(num==-1){
			std::cout<<"終了します..."<<std::endl;
			return 0;
		}else if(num==1){
			std::cout<<"固定席表示"<<std::endl;
			get_lost();
			//get_const();
			show();
		}else if(num==2){
			std::cout<<"抽選結果"<<std::endl;

		}else{
			std::cout<<"err"<<std::endl<<std::endl;continue;
		}
		std::cout<<std::endl;
	}
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

void get_lost(){
	//std::ifstream stream(input_file);
	std::ifstream stream("input.csv");
	std::string line;
	const std::string delim = ",";
		// delimを区切り文字として切り分け、intに変換してsettled[]に格納する
    for ( std::string::size_type spos, epos = 0;(spos = line.find_first_not_of(delim, epos)) != std::string::npos;) {
    	std::string token = line.substr(spos,(epos = line.find_first_of(delim, spos))-spos);
		if(std::stoi(token)>0){
			settled[std::stoi(token)-1] = true;
			count++;
			std::cout<<std::stoi(token)<<std::endl;
		}
    }
}
/*
void get_const(){
	std::ifstream stream(input_file);
 	std::string line;
  	const std::string delim = ",";
	int row = 0;
  	int col;

  	while ( getline(stream, line) ) {
    	col = 0;
    	// delimを区切り文字として切り分け、intに変換してdata[][]に格納する
    	for ( std::string::size_type spos, epos = 0;(spos = line.find_first_not_of(delim, epos)) != std::string::npos;) {
      		std::string token = line.substr(spos,(epos = line.find_first_of(delim, spos))-spos);
      		data[row][col++] = std::stoi(token);
    	}
    	++row;
  	}
	for ( row = 0; row < CountNumbersOfTextLines("lost.csv"); ++row ) {
		win[data[row][0]-YEAR][data[row][1]-1]=true;
  	}
}
*/
void show(){
	std::cout<<"           [教卓]"<<std::endl;
	for(int i=0;i<(CountNumbersOfTextLines(input_file)-1);i++){
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
	short n=0;
	n=rand()%60;	//rand()%(B-A+1)+A;	AからBまでの乱数
	if(settled[n]==false){
		bool search=true;
		while(search){
			for(int i=0;i<10;i++){
				for(int j=0;j<10;j++){
					
				}
			}	
		}
		settled[n]=true;
		/*std::ofstream ofs("log.csv",std::ios::app);
        ofs << (int)g+YEAR<< ","<<(int)c+1<<std::endl;
		ofs.close();*/
	}else{
		lottery();
	}
}

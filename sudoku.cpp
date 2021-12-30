#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <vector>

bool valid_sudoku(const std::vector<int>& g);
bool check_sequence(const std::vector<int>& v);
int mfind(int n, const std::vector<int>& v);
void get_row(int r, const std::vector<int>& in, std::vector<int>& out);
void get_col(int c, const std::vector<int>& in, std::vector<int>& out);
void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out);
int twod_to_oned(int row, int col, int rowlen);

int main(){

    std::vector<int> s;
    std::string filename;

    std::cout << "please enter name of file containing the sudoku" << std::endl;

    std::ifstream infile;
    infile.open(filename.c_str());

    if(!infile.is_open()){
        std::cout << "error, can't open input file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int tmp;

    while(infile >> tmp){
        s.push_back(tmp);
    }
    int side = std::sqrt(s.size());


    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            std::cout << s[twod_to_oned(i,j,side)] << " ";
        }
        std::cout << std::endl;
    }

    bool valid = valid_sudoku(s);

    if(valid){
        std::cout << "valid" << std::endl;
    }
    else{
        std::cout << "not valid" << std::endl;
    }

    return 0;
}

int twod_to_oned(int row, int col, int rowlen){
    return row*rowlen+col;
}

bool valid_sudoku(const std::vector<int>& g){
    int side = std::sqrt(g.size());

    // for each row...
    for(int i = 0; i < side; i++){
        std::vector<int> row;
        get_row(i, g, row);

        if(!check_sequence(row)){
            return false;
        }
    }
    // for each column...
    for(int i = 0; i < side; i++){
      std::vector<int> column;
      get_row(i, g, column);

      if(!check_sequence(column)){
          return false;
      }
    }
    // for each subsquare...
   for(int i=0; i <side; i++){
     std::vector<int> subsquare;
     get_row(i, g, subsquare);

     if(!check_sequence(subsquare)){
         return false;
     }
    }
    return true;
}

//mfind는 vector 랑 int input 이고 input이 vector v 랑 int a 라고 햇을때
//v안에 a가 있는지 확인하는 functions
//mfind가 집접적으로 main에서 쓰이지는 않지만
//check_sequece 할때 스라고 되어있네요
int mfind(int n, const std::vector<int>& v){
    int i = 0;
    while(i<v.size()){
      if(n == v[i]){
        return i;
      }
      i++;
    }
    return -1;

bool check_sequence(const std::vector<int>& v){
    int a = v.size();
    while(a>0){
      if(mfind(a,v) == -1){
        return false;
      }

      a--;

      return true;
    }
}

void get_row(int r, const std::vector<int>& in, std::vector<int>& out){
    int side = std::sqrt(s.size());

    for(j=0; j<side; j++){
      out.push_back(s[twod_to_oned(r,j,side)]);
    }
}

void get_col(int c, const std::vector<int>& in, std::vector<int>& out){
    int side = std::sqrt(s.size());

    for(i=0; i<side; i++){
      out.push_back(s[twod_to_oned(r,i,side)]);
    }
}

void get_subsq(int subs, const std::vector<int>& in, std::vector<int>& out){

    int side = std::sqrt(s.size());
    int sqr = std::sqrt(side);

    for(i=((subs/sqr)*sqr); i<(subs/sqr+1); i++){
      for(j=((sub%sqr)*sqr); j<(subs%sqr+1); j++){
        out.push_back(s[twod_to_oned(j,i,side)]);
        }
      }
    }
}

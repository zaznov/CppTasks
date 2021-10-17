//============================================================================
// Name        : yellow_week1_matrix.cpp
// Author      : Dmitrii Zaznov
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;


class Matrix {
public:
	Matrix(){
		Cols = 0;
		Rows = 0;
		//table = {vector<int>(0)};
		table.assign(Rows, vector<int>(Cols,0));
	};
	Matrix(int num_rows, int num_cols ){
		if (num_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (num_cols < 0) {
			throw out_of_range("num_cols must be >= 0");
		}
		Cols = num_cols;
		Rows = num_rows;
		table.assign(Rows, vector<int>(Cols,0));

	};
	void Reset(int num_rows, int num_cols ){
		if (num_rows < 0) {
			throw out_of_range("num_rows must be >= 0");
		}
		if (num_cols < 0) {
			throw out_of_range("num_cols must be >= 0");
		}
		Cols = num_cols;
		Rows = num_rows;
		table.assign(Rows, vector<int>(Cols,0));
	};


	int At(int row, int col) const{
		if (row > Rows) {
			throw out_of_range("row must be <= " + Rows);
		}
		if (col > Cols) {
			throw out_of_range("col must be <= " + Cols);
		}
		return table.at(row).at(col);
	};

	int&  At(int row, int col){
		if (row > Rows) {
			throw out_of_range("row must be <= " + Rows);
		}
		if (col > Cols) {
			throw out_of_range("col must be <= " + Cols);
		}
			return table.at(row).at(col);
	};


  int Get_num_Cols() const{
	  return Cols;
  };
  int Get_num_Rows() const{
	  return Rows;
  };




private:
  int Cols;
  int Rows;
  vector<vector<int>> table;
};



ostream& operator << (ostream& stream, const Matrix& matr){
		int new_Cols = matr.Get_num_Cols();
		int new_Rows = matr.Get_num_Rows();
		stream << new_Rows;
		stream << " ";
		stream << new_Cols;
		stream << endl;

		for(int row = 0; row < new_Rows; row++){
			for(int col = 0; col < new_Cols; col++){
				stream << matr.At(row, col);
				stream << " ";
			}
			stream << endl;
		}
		return stream;
}

istream& operator >> (istream& stream, Matrix& matr){
	int new_Cols = 0;
	int new_Rows = 0;
	stream >> new_Rows;
	stream.ignore(1);
	stream >> new_Cols;
	matr.Reset(new_Rows, new_Cols);


	for(int row = 0; row < new_Rows; row++){
		for(int col = 0; col < new_Cols; col++){
			stream.ignore(1);
			stream >> matr.At(row, col);
		}
	}
	return stream;
}

istream& operator == (istream& stream, Matrix& matr){
	int new_Cols = 0;
	int new_Rows = 0;
	stream >> new_Rows;
	stream.ignore(1);
	stream >> new_Cols;
	matr.Reset(new_Rows, new_Cols);


	for(int row = 0; row < new_Rows; row++){
		for(int col = 0; col < new_Cols; col++){
			stream.ignore(1);
			stream >> matr.At(row, col);
		}
	}
	return stream;
}

bool operator == (const Matrix& lhs, const Matrix& rhs){

	if(lhs.Get_num_Cols() != rhs.Get_num_Cols()){
		return false;
	}
	if(lhs.Get_num_Rows() != rhs.Get_num_Rows()){
		return false;
	}


	for(int row = 0; row < lhs.Get_num_Rows(); row++){
		for(int col = 0; col < lhs.Get_num_Cols(); col++){
			if(lhs.At(row, col) != rhs.At(row, col)){
				return false;
			}
		}
	}
	return true;
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs){

	if(lhs.Get_num_Cols() != rhs.Get_num_Cols()){
		throw out_of_range("Rows must be equal");
	}
	if(lhs.Get_num_Rows() != rhs.Get_num_Rows()){
		throw out_of_range("Nums must be equal");
	}

	int rows_size = lhs.Get_num_Rows();
	int cols_size = lhs.Get_num_Cols();

	Matrix result;
	result.Reset(rows_size, cols_size);
	for(int row = 0; row < rows_size; row++){
		for(int col = 0; col < cols_size; col++){
			result.At(row, col) = lhs.At(row, col) + rhs.At(row, col);
		}
	}
	return result;
}



int main() {
  Matrix one;
  Matrix two;
  Matrix three;

  //one.Reset(5, 5);
  //cout <<one.At(3,3)<< endl;

  //one.At(3,3) = 3;

  //cout <<one.At(3,3)<< endl;
  cout << "Lets start" << endl;
  cin >> one;
  cout << endl << endl;
  cin >> two;
  cout << endl << endl;
  cout << one;
  cout << endl << endl;
  cout << two;

  if(one == two) {
	  cout << "true";
  }
  else{
	  cout << "false";
  }

  cout << endl << endl;
  three = one + two;
  cout << three;

  //cout <<one.At(1,1)<< endl;

 // cout << one + two << endl;
  return 0;
}

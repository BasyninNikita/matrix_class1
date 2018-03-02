#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class matrix_t {
  int ** data;
  unsigned int rows;
  unsigned int columns;
public:
	matrix_t{
	data=0;
	columns=0;
	rows=0;
	}
	matrix_t add (matrix_t other)const {
	matrix_t matrix3;	
	if (this->rows == other.rows2 && this->columns == other.columns){
	    matrix3.data = new int *[this->rows];
		for (unsigned int i = 0; i<this->columns; i++) {
			matrix3.data[i] = new int [this->columns];
		}
		matrix3.rows = this->rows;
		matrix3.columns = this->columns;	
		for (unsigned int i = 0; i<this->rows; i++){	
	 		for (unsigned int j = 0; j<this->columns; j++){
	 		  	matrix3[i][j] = this->data[i][j]+other.data[i][j];
			}
		}
	}
	else
	{
		cout<<"i can't do it";	
	}
	return matrix3;
}
	matrix_t sub (matrix_t other)const {
	matrix_t matrix3;	
	if (this->rows == other.rows2 && this->columns == other.columns){
	    matrix3.data = new int *[this->rows];
		for (unsigned int i = 0; i<this->columns; i++) {
			matrix3.data[i] = new int [this->columns];
		}
		matrix3.rows = this->rows;
		matrix3.columns = this->columns;	
		for (unsigned int i = 0; i<this->rows; i++){	
	 		for (unsigned int j = 0; j<this->columns; j++){
	 		  	matrix3[i][j] = this->data[i][j]-other.data[i][j];
			}
		}
	}
	else
	{
		cout<<"i can't do it";	
	}
	return matrix3;
}
	matrix_t mul (matrix_t other)const {
			matrix_t matrix3;
	if (this->columns == other.rows) {	
	matrix3.data = new int *[this->rows];
		for (unsigned int i = 0; i<this->columns; i++) {
			matrix3.data[i] = new int [this->columns];
		}
		matrix3.rows = other.rows;
		matrix3.columns = this->columns;
		for(unsigned int i = 0; i < other.rows; ++i ){
    			for(unsigned int j = 0; j < this->columns; ++j ){
      		  		int result = 0;
      		   		for( int k = 0; k < this->columns; ++k ){
       			 		result += this->data[i][k] * other.data[k][j];
      		   		}
      		  		matrix3.data[i][j] = result;
    			}
  		}
	}
	else
	{
		cout<<"i can't do it";
	}
	return matrix3;	
}
	matrix_t transpon (matrix_t other)const {	
	matrix_t matrix3;
	matrix3.data = new int *[other.columns];
		for (unsigned int i = 0; i<other.columns; i++) {
			matrix3.data[i] = new int [tother.rows];
		}
		matrix3.rows = other.columns;
		matrix3.columns = other.rows;
			for (int i=0; i<other.rows; i++){
					for (int j=0; j<cother.columns; j++){		
						matrix3.data[j][i]=other.data[i][j];
					}
				}
				return matrix3;
			}    
	matrix_t(const matrix_t & matrix) {
	this->rows = matrix.rows;
	this->columns = matrix.columns;
	this->data = new int *[this->rows];
	for (unsigned int i = 0; i < this->rows; ++i) {
			data[i] = new int[this->columns];
			for (unsigned int j = 0; j < this->columns; ++j) {
				this->data[i][j] = matrix.data[i][j];
			}
		}
	}
	
	matrix_t & operator=(const matrix_t & matrix) {
		for (unsigned int i = 0; i < rows; ++i) {
			delete[] this->data[i];
		}
		delete[] this->data;
		this->rows = matrix.rows;
		this->columns = matrix.columns;
		this->data = new int * [rows];
		for (unsigned int i = 0; i < this->rows; ++i) {
			this->data[i] = new int[this->columns];
			for (unsigned int j = 0; j < this->columns; ++j) {
				this->data[i][j] = matrix.data[i][j];
			}
		}			
	}
			
	std::ifstream & read( std::ifstream & fin ) {
  	char op;
	string line;
	getline(fin, line);
	istringstream stream(line);

	if (stream >> this->rows && stream >> op && op == ',' && stream >> this->columns) {
		this->data = new int *[this->rows];
		for (unsigned int i = 0; i<this->rows; i++) {
			this->data[i] = new int [this->columns];
			for (unsigned int j = 0; j<this->columns; j++) {
				fin >> this->data[i][j];
			}
		}
	}
	else {
		cout << "Error while reading input data";
	}
	fin.close();
	return fin;
  };
  
  std::ostream & write( std::ostream & stream ) {
  	for (unsigned int i = 0; i<this->rows; i++) {
		for (unsigned int j = 0; j<this->columns; j++) {
			cout << this->data[i][j] << ' ';
		}
		cout << endl;
	}
	return stream;
  };
	~matrix_t(){ 
	for (unsigned int i = 0; i < this->rows; i++) {
		delete [] this->data[i];
	}
	delete []this->data;
  }
  
};

bool files(string & name1,char & op,string name2)
{
	bool succ=false;
	string line;
	gitline(cin,line);
	istringstream stream(line);
	if(stream>>name1&&stream>>op)
	{
		if(op=='T')
		{
			succ=true;
			return succ;
		}
		else if(stream>>name2)
		{
			succ=!succ;
		}
	}
	return succ;
}
int main()
{
	matrix_1 matrix1;
	matrix_1 matrix2;
	matrix_1 matrix3;
	char op;	
  	string name1;
  	string name2;
  	if (!(files(name1, op, name2))) {
		cin.get();
		return 0;
	}
	ifstream fin;
	fin.open(name1.c_str());
	if(!fin.is_open())
	{
		cout<<"file isn't open"<<endl;
		return 0;
	}
	matrix1.read(fin);
	if(op!='T')
	{
	fin.open(name2.c_str());
	if(!fin.is_open())
	{
		cout<<"file isn't open"<<endl;
		return 0;
	}
	matrix2.read(fin);	
	}
          		if(op== '+') {
            		matrix3=matrix1.add(matrix2);
          		}
          		else if(op== '-'){
            		matrix3=matrix1.sub(matrix2);
          		}
          		else if(op =='*') {
            		matrix3=matrix1.mul(matrix2);
          		}
          		else if(op== 'T') {
            		matrix3=matrix1.transpon(matrix1);
          		}
          		else std::cout << "An error has occured while reading input data";
    matrix3.write(cout);

  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
const int row = 6;
const int col = 6;

class Matrix6x6 {
public:
	Matrix6x6()
	{	//intialises the matrix all to zero
		for(int i = 0; i < row; i++){
			for(int j = 0;j < col;j++){
				grid[i][j] = 0;
			}
		}
	}
	void enter1Element(int ROW, int COL,int value)
	{
		grid[ROW][COL] = value;
	}
	void fillArray()
	{
		int input;
		int x;
		int * p = grid[0];
		for(int i = 0; i < row; i++){
			for(int j = 0;j < col;j++){
				std::cout << "\nEnter Value:";
				std::cin >> input;
				x = (input);
				grid[i][j] = x;
				p++;
				for(int k = 0; k < row; k++){
					std::cout << '\n';
					for(int l = 0; l < col; l++){
						if(p == &grid[k][l]){
							std::cout << "X";
						}else{
							std::cout << grid[k][l];
						}
					}
				}
			}
		}
	}
	int sumOfdiagonal()
	{	//ruturns the sum of the diagonal components
		int sum;
		for(int i = 0, j = 0; i <row; i++, j++){
			sum += grid[i][j];
		}
		return sum;
	}
	void transpose()
	{	//stores the orginal array into a 'temp' to swap the orientation
		int tempGrid[row][col];
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				tempGrid[i][j] = grid[i][j];
			}
		}
		for(int i = 0; i < col; i++){
			for(int j = 0; j < row; j++){
				grid[j][i] = tempGrid[i][j];
			}
		}
	}
	void printMatrix()
	{
		for(int i = 0; i < row; i++){
			std::cout << '\n';
			for(int j = 0;j < col;j++){
				std::cout << grid[i][j] << ' ';
			}
		}
		std::cout << '\n';
	}
private:
	int grid[row][col];
};
void InputData(Matrix6x6& matrix);

int main()
{
	Matrix6x6 matrix;
	char c = 0;
	do{
		std::cout << "1) Sum of the diagonal.\n";
		std::cout << "2) transpose the matrix.\n";
		std::cout << "3) Print the matrix.\n";
		std::cout << "4) Input Data.\n";
		std::cout << "5) End the program.\n";
		std::cin >> c;
		switch(c){
			case '1':std::cout << "\nsum: " << matrix.sumOfdiagonal() << std::endl;break;
			case '2':matrix.transpose();break;
			case '3':matrix.printMatrix();break;
			case '4':InputData(matrix);break;
			case '5':std::cout <<"ceya!";break;
			default:std::cout << "\n**Inncorrect Input**\n";
		}
	}while(c != 4);
}

void InputData(Matrix6x6& matrix)
{
	std::cout << "\n\n1) Add individual element.\n";
	std::cout << "2) Fill in array.\n";
	std::cout << "Anything else to return to main Menu.\n";

	char c;
	do{
		std::cin >> c;
	}while(c < '1' && c > '3');
	if(c == '1'){
		int ROW, COL, value;
		do{
			std::cout << "Enter a row and a column (1-6) (row col): ";
			std::cin >> ROW;
			std::cin >> COL;
		} while(ROW < 1 && ROW > 6 && COL < 1 && COL > 6);
		std::cout << "\nEnter the value: ";
		bool isDigit(0);
		std::string input = "";
		do {
    		getline(std::cin, input);
    		std::stringstream myStream(input);
    		if (myStream >> value)
    			isDigit = 1;
        } while(!isDigit);
        matrix.enter1Element(ROW-1, COL-1, value);
	}else if (c == '2'){
		matrix.fillArray();
	}
}

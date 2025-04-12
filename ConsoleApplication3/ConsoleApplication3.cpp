#include <iostream>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <unordered_set> 

using namespace std;

#include "Massiv.h";
#include "Machine_word.h";
#include "Bit_vector.h";
#include "List.h";
int Set_mass::N = 17, Set_mass::cnt = 0;
int Set_m_w::cnt = 0;
int Set_bit::cnt = 0;
int Set_list::N = 17, Set_list::cnt = 0;
const long q0 = 10000;   //количество повторений цикла времени

int main() {
	srand(time(nullptr));
	Set_bit A('A'), B('B'), C('C'), D('D'), E;
	clock_t begin = clock();
	for (long q = 0; q < q0; q++) {
		E = A & B & C | D ;
	}
	clock_t end = clock();
	E.Show();
	//cout << '\n' << "Middle power = " << (A.power() + B.power() + C.power() + D.power() + E.power()) / 5 << '\n';
		cout<<'\n'<<"Time = " << end - begin << "/" << q0 << endl;
	cin.get();

	/*E = A & B & C | D;
	E.Show();*/

	return 0;
}
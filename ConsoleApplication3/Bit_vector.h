class Set_bit {
private:
	static int cnt;
	char S;
	bitset<17> b;
	int n;
public:
	Set_bit(char s): S('A' + cnt++), n(0){
		string U = ":.-+~!&*/%<>=^|?,";

		//cout << '\n' << "A random set constructor volunteered " << S;

		cout << '\n' << S << " = ";

		for (int i = 0; i < 17; i++) {
			if (rand() % 2) {
				b[i] = 1;
				n++;
				cout << U[i];
			}
		}
	}

	Set_bit(): S('A'+ cnt++), n(0){
		//cout << '\n' << "The set constructor volunteered " << S;
	}

	void Show() {
		string U = ":.-+~!&*/%<>=^|?,";
		cout << '\n' << S << " = ";

		for (int i = 0; i < 17; i++) {
			if (b[i]) {
				cout << U[i];
			}
		}
	}

	Set_bit& operator & (const Set_bit& other) {
		this->b = this->b & other.b;
		this->n = this->b.count();
		//cout << '\n' << "The operation & was performed for sets " << S << " and " << other.S;
		return *this;
	}

	Set_bit& operator | (const Set_bit& other) {
		this->b = this->b | other.b;
		this->n = this->b.count();
		//cout << '\n' << "The operation | was performed for sets " << S << " and " << other.S;
		return *this;
	}

	Set_bit& operator = (const Set_bit& other) {
		this->b = other.b;
		this->n = other.n;
		return *this;
	}

	int power() { return n; };

	~Set_bit() {
		//cout << '\n' << "The destructor of the set has volunteered " << S;
	}

};

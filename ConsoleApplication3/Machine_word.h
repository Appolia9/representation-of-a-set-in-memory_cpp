class Set_m_w {
private:
	static int cnt; //мощность унивёрсума и счётчик множеств массивов
	char S;
	long w;
	int n;

public:
	Set_m_w() : S('A' + cnt++),w(0), n(0) {
		//cout << '\n' << "The set constructor volunteered " << S;
	};
	void Show() {
		string U = ":.-+~!&*/%<>=^|?,";
		cout << '\n' << S << " = ";
		for (int i = 0; i < 17; i++) {
			if ((w >> i) & 1) cout << U[i];
		}
	}
	Set_m_w(char s): S('A' + cnt++),w(0), n(0) {
		string U = ":.-+~!&*/%<>=^|?,";
		//cout << '\n' << "A random set constructor volunteered " << S;
		for (int i = 0; i<17 ; i++) {
			if (rand() % 2) {
				w |= (1 << i);
				n++;
			}
		}
		cout << '\n' << S << " = ";
		for (int i = 0; i < 17; i++) {
			if ((w >> i) & 1) cout << U[i];
		}
	}

	Set_m_w& operator |(const Set_m_w &other) {
		this->w = this->w | other.w;
		//cout << '\n' << "The operation | was performed for sets " << S << " and " << other.S;
		return *this;
	}

	Set_m_w& operator &(const Set_m_w& other) {
		this->w = this->w & other.w;
		//cout << '\n' << "The operation & was performed for sets " << S << " and " << other.S;
		return *this;
	}

	Set_m_w& operator = (const Set_m_w& other) {
		//this->S = 'A'+ --cnt;
		this->S = 'E';
		this->w = other.w;
		return *this;
	}

	int power() { return n; };

	~Set_m_w() {
		//cout << '\n' << "The destructor of the set has volunteered " << S;
	}
};

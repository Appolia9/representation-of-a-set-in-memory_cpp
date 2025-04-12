class Set_mass {
private:
	static int N, cnt; //мощность унивЄрсума и счЄтчик множеств массивов

	char S, * A; //тег и пам€ть дл€ множеств
public:
	int n;
	Set_mass& operator |= (const Set_mass& B)
	{
		for (int i = 0; i < B.n; ++i) {
			bool f = true;
			for (int j = 0; j < n; ++j) {
				if (B.A[i] == A[j]) f = false;
			}
			if (f) A[n++] = B.A[i];
		}
		A[n] = '\0';
		//cout << '\n' << "The operation | was performed for sets " << S << " and " << B.S;
		return *this;
	};

	Set_mass operator | (const Set_mass& B)
	{
		Set_mass C(*this);
		
		return (C |= B);
	};

	Set_mass & operator &= (const Set_mass& B) {
		Set_mass C(*this);
		n = 0;
		for (int i = 0; i < C.n; ++i) {
			for (int j = 0; j < B.n; ++j) {
				if (C.A[i] == B.A[j]) {
					A[n++] = C.A[i];
					break; // ѕрерываем внутренний цикл, если нашли совпадение
				}
			}
		}
		A[n] = '\0'; // «авершаем строку

		//cout << '\n' << "The operation & was performed for sets " << C.S << " and " << B.S;

		return *this;
	}

	Set_mass operator & (const Set_mass& B) const
	{
		Set_mass C(*this);
		
		return (C &= B);
	};


	Set_mass & operator = (const Set_mass &B)
	{
		if (this != &B) {
			if (this->A != nullptr) {
				delete[] this->A;
			}
			this->n = B.n;
			//this->S = 'A' + --cnt;
			this->S = 'E';
			this->A = new char[B.n+1];
			for (int i = 0; i < B.n; i++) {
				this->A[i] = B.A[i];
			}
			A[n] = '\0';
		}
		return *this;
	};


	void Show()
	{
		cout << '\n' << S << " = [" << A << "]";
	};

	int power() { return n; };
	
	Set_mass(char s): S('A' + cnt++), A(new char[N+1]), n(0)			//конструктор случайного множетства
	{
		//cout << '\n' << "A random set constructor volunteered " << S;
		string U = ":.-+~!&*/%<>=^|?,";
		for (int i = 0; i < N; i++) {
			if (rand() % 2) A[n++] = U[i];
		}
		A[n] = '\0';
		cout << '\n' << S << " = [" << A << "]";
	}; 

	Set_mass() : S('A' + cnt++), A(new char[N + 1]), n(0)		//конструктор множества
	{
		//cout << '\n' << "The set constructor volunteered " << S;
		A[0] = '\0';
	};
	Set_mass(const Set_mass &B): S('A' + cnt++), n(B.n)			//конструктор копии
	{
		//cout << '\n' << "The constructor of a copy of the set volunteered " << S;
		this->A = new char[N + 1];
		for (int i = 0; i < n; i++) {
			this->A[i] = B.A[i];
		}
		
	}; 
	~Set_mass() { 
		//cout << '\n' << "The destructor of the set has volunteered " << S;
		delete[]A;
	}
};

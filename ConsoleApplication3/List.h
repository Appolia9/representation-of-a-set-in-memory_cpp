
#ifndef SET_LIST_H 
#define SET_LIST_H 

class Set_list
{
private:
    int n;
    struct Node {
        char data;
        Node* next;
        Node(char val) : data(val), next(nullptr) {}
    };

    Node* head;
    static int N, cnt; //мощность унивёрсума и счётчик множеств массивов 
    char S; //тег для множеств 
   

public:
    Set_list(char s) : head(nullptr), S('A' + cnt++), n(0)
    {
        string U = ":.-+~!&*/%<>=^|?,";
       // cout << '\n' << "Random set constructor volunteered " << S << endl;
        for (int i = 0; i < U.size(); i++)
        {
            if (rand() % 2) {
                this->append(U[i]);
                n++;
               // cout << '\n' << "An item has been added to the list " << S ;
            }
        }

        Node* current = head;
        cout <<'\n'<< S << " = ";
        while (current) {

            cout << current->data;
            current = current->next;
        }
        cout << endl;

    }

    Set_list() : head(nullptr), S('A' + cnt++),n(0)
    {
       // cout << '\n' << "The set constructor volunteered " << S;
    };

    ~Set_list() {
        //cout << '\n' << "The destructor of the set has volunteered " << S;
        clear();
    }

    void append(char value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
       
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        n = 0;
    }

    // Конструктор копирования 
    Set_list(const Set_list& other) : head(nullptr) {
       // cout << '\n' << "The constructor of a copy of the set volunteered " << S;
        Node* current = other.head;
        while (current) {
            append(current->data);  // Используем метод append для копирования 
            current = current->next;
        }
        this->n = other.n;
    }

    // Перегрузка оператора = 
    Set_list& operator=(const Set_list& other) {
        if (this != &other) {
            clear();
            Node* current = other.head;
            while (current) {
                append(current->data);
                current = current->next;
            }
            this->n = other.n;
        }
        return *this;
    }

    // Перегрузка оператора | 
    Set_list operator|(const Set_list& other) const {
        Set_list result;

        string U = ":.-+~!&*/%<>=^|?,";
        char uniqueElements[17];

        Node* current = head;
        int i = 0;
        while (current) {
            uniqueElements[i] = current->data;
            i++;
            current = current->next;
        }
        int n = i, f = 0;
        current = other.head;
        while (current) {
            for (int i = 0; i < n; i++)
            {
                if (current->data == uniqueElements[i])
                    f = 1;
            }
            if (f == 0) { uniqueElements[n] = current->data; n = n + 1; }
            f = 0;
            current = current->next;
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < n; j++)
                if (U[i] == uniqueElements[j]) result.append(U[i]); result.n++;
        }
        //cout << '\n' << "The operation | was performed for sets " << S << " and " << other.S;

        return result;
    }

    // Перегрузка оператора |= 
    Set_list& operator|=(const Set_list& other) {
        Set_list result(*this);
        string U = ":.-+~!&*/%<>=^|?,";
        unordered_set<char> uniqueElements;

        // Добавляем элементы текущего списка 
        Node* current = head;
        while (current) {
            uniqueElements.insert(current->data);
            current = current->next;
        }

        // Добавляем элементы другого списка 
        current = other.head;
        while (current) {
            uniqueElements.insert(current->data);
            current = current->next;
        }
        int n = uniqueElements.size();
        for (int i = 0; i < N; i++)
        {
            for (const auto& elem : uniqueElements)
                if (U[i] == elem) result.append(U[i]); result.n++;
        }

        return  *this;
    }

    // Перегрузка оператора & 
    Set_list operator&(const Set_list& other) const {
        Set_list result;

        string U = ":.-+~!&*/%<>=^|?,";
        char elements[17];

        Node* current = head;
        Node* following = other.head;
        int i = 0;
        while (current) {
            following = other.head;
            while (following) {
                if (current->data == following->data) {
                    elements[i] = current->data;
                    i++;
                    break;
                }
                following = following->next;
            }
            current = current->next;
        }
        int n = i;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < n; j++)
                if (U[i] == elements[j]) result.append(U[i]); result.n++;
        }
        //cout << '\n' << "The operation & was performed for sets " << S << " and " << other.S;

        return result;
    }


    // Перегрузка оператора &= 
    Set_list& operator&=(const Set_list& other) {
        unordered_set<char> otherElements;

        // Добавляем элементы другого списка в множество 
        Node* current = other.head;
        while (current) {
            otherElements.insert(current->data);
            current = current->next;
        }

        // Очищаем текущий список 
        clear();
        cout << '\n' << "The list " << S << "has been cleared";
        // Заполняем текущий список только теми элементами, которые есть в другом списке 
        current = head; // Восстанавливаем текущий указатель на начало 
        while (current) {
            if (otherElements.find(current->data) != otherElements.end()) {
                append(current->data);
                this->n++;
            }
            current = current->next;
        }

        return *this;
    }



    void Show() const {
        Node* current = head;
        cout <<'\n'<< S << " = ";
        while (current) {

            cout << current->data;
            current = current->next;
        }

        cout << endl;
    }
};
//int power() { return n; }

#endif  SET_LIST_H

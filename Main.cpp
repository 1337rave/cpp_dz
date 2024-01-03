#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    // Конструктор за замовчуванням
    String() : str(nullptr), length(0) {}

    // Конструктор з параметрами
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // Деструктор
    ~String() {
        delete[] str;
    }

    // Оператор перевантаження []
    char operator[](int index) const {
        if (index >= 0 && index < length) {
            return str[index];
        }
        else {
            // Обробка виходу за межі масиву
            std::cerr << "Index out of bounds!" << std::endl;
            return '\0';  // Повертаємо порожній символ
        }
    }

    // Оператор перевантаження ()
    int operator()(char ch) const {
        for (int i = 0; i < length; ++i) {
            if (str[i] == ch) {
                return i;  // Знайдено символ, повертаємо індекс
            }
        }
        return -1;  // Символ не знайдено
    }

    // Оператор перетворення типу до int
    operator int() const {
        return length;  // Повертаємо довжину рядка
    }
};

int main() {
    String myString("Hello, World!");

    // Використання перевантаження []
    std::cout << "Character at index 7: " << myString[7] << std::endl;

    // Використання перевантаження ()
    int index = myString('W');
    if (index != -1) {
        std::cout << "Index of 'W': " << index << std::endl;
    }
    else {
        std::cout << "'W' not found in the string." << std::endl;
    }

    // Використання перетворення до int
    std::cout << "Length of the string: " << static_cast<int>(myString) << std::endl;

    return 0;
}

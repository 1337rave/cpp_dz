#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

class String {
private:
    char* str;
    int length;

public:
    // ����������� �� �������������
    String() : str(nullptr), length(0) {}

    // ����������� � �����������
    String(const char* s) {
        length = std::strlen(s);
        str = new char[length + 1];
        std::strcpy(str, s);
    }

    // ����������
    ~String() {
        delete[] str;
    }

    // �������� �������������� []
    char operator[](int index) const {
        if (index >= 0 && index < length) {
            return str[index];
        }
        else {
            // ������� ������ �� ��� ������
            std::cerr << "Index out of bounds!" << std::endl;
            return '\0';  // ��������� ������� ������
        }
    }

    // �������� �������������� ()
    int operator()(char ch) const {
        for (int i = 0; i < length; ++i) {
            if (str[i] == ch) {
                return i;  // �������� ������, ��������� ������
            }
        }
        return -1;  // ������ �� ��������
    }

    // �������� ������������ ���� �� int
    operator int() const {
        return length;  // ��������� ������� �����
    }
};

int main() {
    String myString("Hello, World!");

    // ������������ �������������� []
    std::cout << "Character at index 7: " << myString[7] << std::endl;

    // ������������ �������������� ()
    int index = myString('W');
    if (index != -1) {
        std::cout << "Index of 'W': " << index << std::endl;
    }
    else {
        std::cout << "'W' not found in the string." << std::endl;
    }

    // ������������ ������������ �� int
    std::cout << "Length of the string: " << static_cast<int>(myString) << std::endl;

    return 0;
}

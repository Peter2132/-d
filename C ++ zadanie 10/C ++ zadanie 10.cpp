#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <Windows.h>

void reverse(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; ++i) {
        std::swap(str[i], str[length - i - 1]);
    }
}


void removeVowels(char* str) {
    int length = strlen(str);
    int currentIndex = 0;

    for (int i = 0; i < length; ++i) {
        if (!strchr("aeiouAEIOU", str[i])) {
            str[currentIndex++] = str[i];
        }
    }

    str[currentIndex] = '\0'; 
}


void removeConsonants(char* str) {
    int length = strlen(str);
    int currentIndex = 0;

    for (int i = 0; i < length; ++i) {
        if (!strchr("bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ", str[i])) {
            str[currentIndex++] = str[i];
        }
    }

    str[currentIndex] = '\0';
}


void shuffle(char* str) {
    int length = strlen(str);

    std::default_random_engine generator(std::time(nullptr));
    for (int i = length - 1; i > 0; --i) {
        int j = std::uniform_int_distribution<int>(0, i)(generator);
        std::swap(str[i], str[j]);
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char word[100]; 
    int choice;
    
    std::cout << "Введите слово: ";
    std::cin.getline(word, 100); 

    std::cout << "Выберите действие:\n";
    std::cout << "1. Слово выводится задом наперед.\n";
    std::cout << "2. Вывести слово без гласных.\n";
    std::cout << "3. Вывести слово без согласных.\n";
    std::cout << "4. Рандомно раскидывать буквы заданного слова.\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        reverse(word);
        std::cout << "Результат: " << word << std::endl;
        break;
    case 2:
        removeVowels(word);
        std::cout << "Результат: " << word << std::endl;
        break;
    case 3:
        removeConsonants(word);
        std::cout << "Результат: " << word << std::endl;
        break;
    case 4:
        shuffle(word);
        std::cout << "Результат: " << word << std::endl;
        break;
    default:
        std::cout << "Некорректный выбор.\n";
        break;
    }

    return 0;
}
#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <iostream>

// Клас шифрування для простого шифрування та дешифрування рядків
class Encryption {
public:
    // Функція шифрування рядка за допомогою простого шифру Цезаря
    static std::string encrypt(const std::string& data) {
        std::string encrypted = data;
        for (char& c : encrypted) {
            c += 1; // Шифр Цезаря 
        }
        return encrypted;
    }

    // Функція для розшифровки рядка, зашифрованого вищевказаним методом
    static std::string decrypt(const std::string& data) {
        std::string decrypted = data;
        for (char& c : decrypted) {
            c -= 1; 
        }
        return decrypted;
    }
};

#endif // ENCRYPTION_H


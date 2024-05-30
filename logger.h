#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <string>
#include <ctime>

// Logger class 
class Logger {
private:
    std::ofstream logFile;

    // Функція для отримання поточного часу у вигляді рядка
    std::string getCurrentTime() const {
        std::time_t now = std::time(nullptr);
        std::tm timeinfo;
        localtime_s(&timeinfo, &now);
        char buf[100];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &timeinfo);
        return buf;
    }

public:
    // Конструктор для відкриття log file
    Logger(const std::string& filename) {
        logFile.open(filename, std::ios_base::app);
        if (!logFile.is_open()) {
            throw std::runtime_error("Unable to open log file.");
        }
    }

    // Деструктор для закриття log file
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Функція для реєстрації повідомлення з міткою часу
    void log(const std::string& message) {
        logFile << "[" << getCurrentTime() << "] " << message << std::endl;
    }
};

#endif 


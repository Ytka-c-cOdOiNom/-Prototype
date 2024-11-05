#include <iostream>
#include <memory>
#include <string>
#include <windows.h>
using namespace std;

// Базовий клас для документів
class Document {
public:
    virtual unique_ptr<Document> clone() const = 0;
    virtual void show() const = 0;
    virtual ~Document() = default;
};

// Клас для резюме
class Resume : public Document {
private:
    string name;
    string skills;

public:
    Resume(const string& name, const string& skills) : name(name), skills(skills) {}

    // Реалізація клонування для резюме
    unique_ptr<Document> clone() const override {
        return make_unique<Resume>(*this);
    }

    void show() const override {
        cout << "Резюме:\nІм'я: " << name << "\nНавички: " << skills << endl;
    }
};

// Клас для супровідного листа
class CoverLetter : public Document {
private:
    string name;
    string content;

public:
    CoverLetter(const string& name, const string& content) : name(name), content(content) {}

    // Реалізація клонування для супровідного листа
    unique_ptr<Document> clone() const override {
        return make_unique<CoverLetter>(*this);
    }

    void show() const override {
        cout << "Супровідний лист:\nІм'я: " << name << "\nТекст: " << content << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Створення об'єктів прототипів
    unique_ptr<Document> resumePrototype = make_unique<Resume>("Іван Петренко", "C++, Java, Python");
    unique_ptr<Document> coverLetterPrototype = make_unique<CoverLetter>("Іван Петренко", "Маю великий досвід програмування...");

    // Клонування об'єктів
    unique_ptr<Document> clonedResume = resumePrototype->clone();
    unique_ptr<Document> clonedCoverLetter = coverLetterPrototype->clone();

    // Відображення клонованих об'єктів
    cout << "Клоновані документи:\n";
    clonedResume->show();
    cout << endl;
    clonedCoverLetter->show();

}


#include <iostream>
#include <string>

class Person {
    char* name;
    int age;

    public:
        Person() = default;

        Person(const char* newName, int newAge) : age(newAge) {
            name = new char[strlen(newName) + 1];
            strcpy_s(name, strlen(newName) + 1, newName);
        }

        void Print() const {
            std::cout << "Name: " << name << "\tAge: " << age << "\t";
        }

        void Input() {
            char buff[20];
            std::cout << "Enter Name: ";
            std::cin.getline(buff, 20);
            name = new char[strlen(buff) + 1];
            strcpy_s(name, strlen(buff) + 1, buff);
            std::cout << "Enter Age: ";
            std::cin >> age;
        }

        ~Person() {
            delete[] name;
        }
};

class Student : public Person {
    char* university;

    public:
        Student() = default;

        Student(const char* newName, int newAge, const char* newUniversity) : Person(newName, newAge) {
            university = new char[strlen(newUniversity) + 1];
            strcpy_s(university, strlen(newUniversity) + 1, newUniversity);
        }

        ~Student() {
            delete[] university;
        }

        void Input(const char* newUniversity) {
            delete[] university;
            university = new char[strlen(newUniversity) + 1];
            strcpy_s(university, strlen(newUniversity) + 1, newUniversity);
            Person::Input();
        }

        void Print() const {
            Person::Print();
            std::cout << "\tUniversity: " << university << "\n\n";
        }
};

class Teacher : public Person {
    char* school;
    int salary;
    std::string* schoolItems;
    int sizeItems;

    public:
        Teacher() = default;

        Teacher(const char* newName, int newAge, const char* newSchool, int newSalary, std::string newSchoolItems[], int newSizeItems)
            : Person(newName, newAge), salary(newSalary), sizeItems(newSizeItems) {

            school = new char[strlen(newSchool) + 1];
            strcpy_s(school, strlen(newSchool) + 1, newSchool);

            schoolItems = new std::string[newSizeItems];

            for (int i = 0; i < newSizeItems; i++) {
                schoolItems[i] = newSchoolItems[i];
            }
        }

        ~Teacher() {
            delete[] school;
            delete[] schoolItems;
        }

        void Input(const char* newSchool, int newSalary, std::string newSchoolItems[], int newSizeItems) {
            delete[] school;
            delete[] schoolItems;

            salary = newSalary;
            sizeItems = newSizeItems;

            schoolItems = new std::string[newSizeItems];

            for (int i = 0; i < newSizeItems; i++) {
                schoolItems[i] = newSchoolItems[i];
            }

            school = new char[strlen(newSchool) + 1];
            strcpy_s(school, strlen(newSchool) + 1, newSchool);
            Person::Input();
        }

        void Print() const {
            Person::Print();
            std::cout << "\tSchool: " << school << "\t Salary: " << salary << "$\tItems: ";
            for (int i = 0; i < sizeItems; i++) {
                if (i == sizeItems - 1) {
                    std::cout << schoolItems[i];
                }
                else {
                    std::cout << schoolItems[i] << ", ";
                }
            }
            std::cout << "\n\n";
        }
};

class Doctor : public Person {
    char* speciality;
    int experience;
    bool familyDoctor;

    public:
        Doctor() = default;

        Doctor(const char* newName, int newAge, const char* newSpeciality, int newExperience, bool newFamilyDoctor)
            : Person(newName, newAge), experience(newExperience), familyDoctor(newFamilyDoctor) {

            speciality = new char[strlen(newSpeciality) + 1];
            strcpy_s(speciality, strlen(newSpeciality) + 1, newSpeciality);
        }

        ~Doctor() {
            delete[] speciality;
        }

        void Input(const char* newSpeciality, int newExperience, bool newFamilyDoctor) {
            delete[] speciality;
            speciality = new char[strlen(newSpeciality) + 1];
            strcpy_s(speciality, strlen(newSpeciality) + 1, newSpeciality);
            experience = newExperience;
            familyDoctor = newFamilyDoctor;
            Person::Input();
        }

        void Print() const {
            Person::Print();
            std::cout << "\tSpeciality: " << speciality << "\tExperience: " << experience
                << "\tFamily Doctor? " << (familyDoctor ? "Yes" : "No") << "\n\n";
        }
};

class Driver : public Person {
    char* carNumber;
    char* driverCard;

    public:
        Driver() = default;

        Driver(const char* newName, int newAge, const char* newCarNumber, const char* newDriverCard)
            : Person(newName, newAge) {
            carNumber = new char[strlen(newCarNumber) + 1];
            strcpy_s(carNumber, strlen(newCarNumber) + 1, newCarNumber);

            driverCard = new char[strlen(newDriverCard) + 1];
            strcpy_s(driverCard, strlen(newDriverCard) + 1, newDriverCard);
        }

        ~Driver() {
            delete[] carNumber;
            delete[] driverCard;
        }

        void Input(const char* newCarNumber, const char* newDriverCard) {
            delete[] carNumber;
            delete[] driverCard;

            carNumber = new char[strlen(newCarNumber) + 1];
            strcpy_s(carNumber, strlen(newCarNumber) + 1, newCarNumber);

            driverCard = new char[strlen(newDriverCard) + 1];
            strcpy_s(driverCard, strlen(newDriverCard) + 1, newDriverCard);
            Person::Input();
        }

        void Print() const {
            Person::Print();
            std::cout << "\tCar Number: " << carNumber << "\tDriver Card: " << driverCard << "\n\n";
        }
};

int main() {
    Student student("Anna", 20, "Computer Science University");
    Teacher teacher("John", 35, "High School", 50000, new std::string[3]{ "Physics", "Chemistry", "Biology" }, 3);
    Doctor doctor("Emma", 40, "Cardiologist", 15, false);
    Driver driver("Michael", 30, "XYZ123", "DL-456");

    std::cout << "Student Information:\n";
    student.Print();

    std::cout << "Teacher Information:\n";
    teacher.Print();

    std::cout << "Doctor Information:\n";
    doctor.Print();

    std::cout << "Driver Information:\n";
    driver.Print();

    std::cout << "Enter new information for the student:\n";

    student.Input("Engineering University");

    std::cout << "Updated Student Information:\n";
    student.Print();

    return 0;
}
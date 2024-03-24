#include <iostream> 
#include <string> 
#include <ctime> 

#define random(min,max) (min + rand() % (max - min + 1)) 
using namespace std;

const char LETTERS[]{ 'A','B', 'E', 'K', 'M', 'H','O', 'P', 'C', 'T', 'X', }; //index 10
//const char NUMBERS[]{ '1','2', '3', '4', '5', '6', '7', '8', '9'}; 
const string COLORS[]{ "white","blue", "black", "yellow","red" }; //5 
const string MODELS[]{ "Mercedes","Toyota", "BMW", "Lexus","Tesla" }; //5 




class Car {
private:
    static string lastNumber;
    string number;
    string model;
    string color;


public:
    Car() {};
    Car(string model, string color) {
        lastNumber =  generateNumber();
        this->number = lastNumber;
        this->model = model;

        this->color = color;
        string createNumber = generateNumber();
        if (createNumber != "-") {
            lastNumber = createNumber;
        }
        else
        {
            lastNumber = generateNumber();
        }
        
    }

    


    string getNumber() {
        return number;
    }
    void carInfo() {
        cout << "Car number: " << number << "\nModel: " << model << "\nColor: " << color << "\n\n";
    }

    string getColor() {
        return color;
    }
    string getModel() {
        return model;
    }

    void setColor(string color) {
        this->color = color;
    }


private:
     string generateNumber() {
        string letters = "";
            letters += lastNumber[0];
            letters += lastNumber[4];
            letters += lastNumber[5];
            int number = stoi(lastNumber.substr(1, 3));
            if (number >= 999) {
                number = 0;
                if (letters[2] == 'X') {
                    letters[2] = LETTERS[0];
                    if (letters[1] == 'X') {
                        letters[1] = LETTERS[0];
                        if (letters[0] == 'X') {
                            return "-";
                        }
                        else
                        {
                            letters[0] = findNextLetter(letters[0]);
                        }
                        
                    }
                    else
                    {
                        letters[1] = findNextLetter(letters[1]);
                    }

                }
                else {
                   
                    letters[2] = findNextLetter(letters[2]);
                }
            }
            else {
                number++;
            }
            int count = 1;
            if (number < 100 && number > 9) count = 2;
            else if (number < 1000 && number > 99) count = 3;




            string newNumber = "";
            newNumber += letters[0];
            for (int i = 0; i < 3-count; i++)
            {
                newNumber += '0';

            }
            newNumber += to_string(number);
            newNumber += letters[1];
            newNumber += letters[2];

            return newNumber;
            
    }
     char findNextLetter(char currentLetter) {
        
         for (int i = 0; i < 11; i++)
         {
             if (LETTERS[i] == currentLetter) {
                
                 return LETTERS[i + 1];
             }
         }
     }

};



class Parking {
private:
    string name;
    int capacity;
    int size=0;
    float price;
    Car* Cars = new Car[size];
public:
    Parking(string name, int capacity, float price) {
        this->name = name;
        this->capacity = capacity;
        this->price = price;
    }
    void setName(string name) {
        this->name;
    }
    
    string getName() {
        return name;
    }

    void setPrice(float price) {
        this->price = price;
    }

    float getPrice() {
        return price;
    }

    int getSize() {
        return size;
    }
};

  


string Car::lastNumber ="A000AA";


int main()
{
    srand(time(NULL));
    Car cars[100];
    for (int i = 0; i < 100; i++) {
        cars[i] = Car(MODELS[random(0, 4)], COLORS[random(0, 4)]);
    }

    for (int i = 0; i < 100; i++) {
        cars[i].carInfo();
    }

    Parking park1("ItTopParking", 100, 10);

    cout << park1.getName() << endl;
    cout << park1.getSize() << endl;
    cout << cars[99].getColor();
    
}

  
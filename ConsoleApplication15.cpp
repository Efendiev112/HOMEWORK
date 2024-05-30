#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <concepts>
using namespace std;

class Ammo {
protected:
    int damage;
    string name;
public:
    virtual int getDamage() = 0;
    virtual string getName() = 0;
};

class Ammo556 : public Ammo { //abstract Ammo
};

class Ammo762 : public Ammo {
};

class Ammo919 : public Ammo {
};



class Ammo_5_56_BP : public Ammo556 { //concrete ammo
public:
    Ammo_5_56_BP() {
        this->damage = 5;
        this->name = "Ammo_5_56_BP";
    };
    int getDamage() { return this->damage; }
    string getName() { return this->name; }

};

class Ammo_5_56_PS : public Ammo556 {
public:
    Ammo_5_56_PS() {
        this->damage = 8;
        this->name = " Ammo_5_56_PS";
    };
    int getDamage() { return this->damage; }
    string getName() { return this->name; }

};

class Ammo_7_62_BP : public Ammo762 {
public:
    Ammo_7_62_BP() {
        this->damage = 17;
        this->name = "Ammo_7_62_BP";
    };
    int getDamage() { return this->damage; }
    string getName() { return this->name; }

};

class Ammo_7_62_PS : public Ammo762 {
public:
    Ammo_7_62_PS() {
        this->damage = 23;
        this->name = "Ammo_7_62_PS";
    };
    int getDamage() { return this->damage; }
    string getName(){ return this->name; }
};

class Ammo_9_19_BP : public Ammo919 {
public:
    Ammo_9_19_BP() {
        this->damage = 15;
        this->name = "Ammo_9_19_BP";
    };
    int getDamage() { return this->damage; }
    string getName() { return this->name; }

};

class Ammo_9_19PS : public Ammo919 {
public:
    Ammo_9_19PS() {
        this->damage = 8;
        this->name = "Ammo_9_19PS";

    };

    int getDamage() { return this->damage; }
    string getName() { return this->name; }

};



template<typename T>
concept AmmoType = is_base_of<Ammo,remove_pointer_t<T>>::value && !is_same_v<Ammo,remove_pointer_t<T>>;

template<AmmoType T>
class Magazine {
    int amount;
    stack<T> bullets;
public:
    Magazine(int amount) : amount(amount) {};

    void load(T bullet) {
        if (bullets.size() >= amount) {
            cout << "Магаин полон" << endl;
            return;
                
        }
        
        bullets.push(bullet);
       
    }


    T unload() {
        if (bullets.empty()) {
            cout << "Магазин пуст " << endl;
            return nullptr;
        }
        
        T bullet = bullets.top();
        bullets.pop();
        return bullet;
    }

    stack<T> fullUnload() {
        if (bullets.empty()) throw out_of_range("empty");
        stack<T>unloadBullets = bullets;
        while (!bullets.empty()) bullets.pop();
        return unloadBullets;
    }
    

    void info() {

        cout << "Type: " <<bullets.top()->getName() << endl;
        cout << "Bullets: "<< bullets.size() << endl;
    }
};




class Magazine_5_56 {
    stack<Ammo556> bullets;
public:
};

class Magazine_7_62 {
    stack<Ammo556> bullets;
public:
};

class Magazine_9_19 {
    stack<Ammo556> bullets;
public:
};


class Weapon {
private:

public:

};


class Human {
private:

public:


};



int main() {
    
    setlocale(LC_ALL, "");

    Magazine<Ammo556*> m5_56(5);
    for (int i = 0; i < 5; i++) {
        m5_56.load(new Ammo_5_56_BP);
    }
    m5_56.info();
    m5_56.unload();
    m5_56.info();
    

}
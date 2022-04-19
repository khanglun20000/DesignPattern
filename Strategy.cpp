#include <iostream>
using namespace std;

//interface for quack methods
class QuackBehaviour{
public:
    virtual void DoQuack(){};
};

//implementing the quack behaviours
class Squeak : public QuackBehaviour
{
public:
    void DoQuack() override{
        cout << "Squeak" << endl;
    }
};

class Quack : public QuackBehaviour
{
public:
    void DoQuack() override{
        cout << "Squeak" << endl;
    }
};

class MuteQuack : public QuackBehaviour
{
public:
    void DoQuack() override{
        cout << "Can't quack" << endl;
    }
};

//interface for fly methods
class FlyBehaviour{
public:
    virtual void DoFly(){};
};

//implementing the fly behaviours
class FlyWithWings : public FlyBehaviour
{
public:
    void DoFly() override{
        cout << "Fly with wings" << endl;
    }
};

class FlyNoWay : public FlyBehaviour
{
public:
    void DoFly() override{
        cout << "Can't Fly" << endl;
    }
};


//base class for ducks
class Duck{
public:
    QuackBehaviour* quackBehaviour;
    FlyBehaviour* flyBehaviour;
    
    void PerformQuack(){
        quackBehaviour->DoQuack();
    }
    void PerformFly(){
        flyBehaviour->DoFly();
    }
    
    void SetFlyBehaviour(FlyBehaviour* flyBehaviour){
        this->flyBehaviour = flyBehaviour;
    }
    
    virtual void Display(){};
};


class MallardDuck : public Duck
{
public:
    MallardDuck() : Duck(){
        quackBehaviour = new Quack;
        flyBehaviour = new FlyWithWings;
    }
    
    void Display() override{
        cout << "I'm a Mallard Duck" << endl;
    }
};

class DecoyDuck : public Duck
{
public:
    DecoyDuck(){
        quackBehaviour = new MuteQuack;
        flyBehaviour = new FlyNoWay;
    }
    
    void Display() override{
        cout << "I'm a Decoy Duck" << endl;
    }
};


int main(int argc, const char * argv[]) {
    Duck* mallardDuckPtr = new MallardDuck();
    mallardDuckPtr->Display();
    mallardDuckPtr->PerformQuack();
    mallardDuckPtr->PerformFly();
    mallardDuckPtr->SetFlyBehaviour(new FlyNoWay);
    mallardDuckPtr->PerformFly();
    cout << endl;
    
    Duck* decoyDuckPtr = new DecoyDuck();
    decoyDuckPtr->Display();
    decoyDuckPtr->PerformQuack();
    decoyDuckPtr->PerformFly();
    return 0;
}

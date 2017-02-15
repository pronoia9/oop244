#ifndef SICT_ANIMAL_H__
#define SICT_ANIMAL_H__
namespace sict{
  class Animal{
    char _name[41];
  public:
    Animal(const char* name = "Nameless");
    const char* name()const; 
    void name(const char* value); 
    virtual void act();
    void move();
    virtual void sound();
    ~Animal();
  };



}
#endif
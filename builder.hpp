#ifndef BUILDER_HPP
#define BUILDER_HPP
#include <iostream>
#include <memory>
#include <string>

// Product
class Pizza
{
private:
    std::string dough = "classic";
    std::string sauce = "classic";
    std::string topping = "classic";
public:
    Pizza() { }
    ~Pizza() { }
    void SetDough(const std::string& d) { dough = d; }
    void SetSauce(const std::string& s) { sauce = s; }
    void SetTopping(const std::string& t) { topping = t; }
    void ShowPizza()
    {
        std::cout <<  "Yummy!!!"  << std::endl
        <<  "Pizza with Dough as "<< dough
        << ", Sauce as " << sauce
        << " and Topping as "<< topping
        << " !"<< std::endl;
    }

};

// Abstract Builder
class PizzaBuilder
{
protected:
    std::shared_ptr<Pizza> pizza;
    PizzaBuilder() {}
public:
    std::shared_ptr<Pizza> GetPizza() { return pizza; }
    void createNewPizzaProduct() { pizza.reset (new Pizza); }
    virtual void buildDough() {}
    virtual void buildSauce() {}
    virtual void buildTopping() {}
};


// ConcreteBuilder
class HawaiianPizzaBuilder : public PizzaBuilder
{
public:
    HawaiianPizzaBuilder() : PizzaBuilder() {}
    ~HawaiianPizzaBuilder(){}
    void buildSauce() { pizza->SetSauce("mild");}
    void buildTopping() { pizza->SetTopping( "ham and pineapple");}
};

// ConcreteBuilder
class SpicyPizzaBuilder : public PizzaBuilder
{
public:
    SpicyPizzaBuilder() : PizzaBuilder() {}
    ~SpicyPizzaBuilder() {}
    void buildDough() { pizza->SetDough( "pan baked");}
    void buildSauce() { pizza->SetSauce(  "hot");}
    void buildTopping() { pizza->SetTopping( "pepperoni and salami"); }
};

// Director
class Waiter
{
private:
    PizzaBuilder* pizzaBuilder; public:
    Waiter() : pizzaBuilder(NULL) {}
    ~Waiter() { }
    void SetPizzaBuilder(PizzaBuilder* b) { pizzaBuilder = b; }
    std::shared_ptr<Pizza> GetPizza() { return pizzaBuilder->GetPizza(); }
    void ConstructPizza()
    {
        pizzaBuilder->createNewPizzaProduct();
        pizzaBuilder->buildDough();
        pizzaBuilder->buildSauce();
        pizzaBuilder->buildTopping();
    }
};



#endif // BUILDER_HPP

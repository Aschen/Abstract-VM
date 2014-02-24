//
// Operand.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Tue Feb 18 16:05:55 2014 brunne-r
// Last update Mon Feb 24 12:10:44 2014 brunne-r
//

#include "AbstractVm.hh"
#include <iostream>
#include <iomanip>

template<typename C>
Operand<C>::Operand(std::string const& value, eOperandType const& type): _type(type)
{
  this->_accuracy = sizeof(C);
  this->_value = Transform::stringToValue<C>(value);
  this->_str = value;
}

template<typename C>
Operand<C>::~Operand()
{
}

template<typename C>
std::string const &Operand<C>::toString() const
{
  return this->_str;
}

template<typename C>
int Operand<C>::getPrecision() const
{
  return this->_accuracy;
}

template<typename C>
eOperandType	Operand<C>::getType() const
{
  return this->_type;
}

template<typename C>
IOperand *Operand<C>::operator+(const IOperand &rhs) const
{
  C		a(0), b(0), result(0);
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  result = a + b;
  Transform::valueToString<C>(result, s);
  return Factory::createOperand(this->getType(), s);
}

template<typename C>
IOperand *Operand<C>::operator-(const IOperand &rhs) const
{
  C		a(0), b(0), result(0);
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  result = a - b;
  Transform::valueToString<C>(result, s);
  return Factory::createOperand(this->getType(), s);
}

template<typename C>
IOperand *Operand<C>::operator*(const IOperand &rhs) const
{
  C		a(0), b(0), result(0);
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  result = a * b;
  Transform::valueToString<C>(result, s);
  return Factory::createOperand(this->getType(), s);
}

template<typename C>
IOperand *Operand<C>::operator/(const IOperand &rhs) const
{
  C		a(0), b(0), result(0);
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  if (b == 0)
    std::cerr << "Division by 0" << std::endl;
  else
    result = a / b;
  Transform::valueToString<C>(result, s);
  return Factory::createOperand(this->getType(), s);
}

template<typename C>
IOperand *Operand<C>::operator%(const IOperand &rhs) const
{
  C		a(0), b(0), result(0);
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  if (b == 0)
    std::cerr << "Modulo by 0" << std::endl;
  else
    {
      result = a / b;      
      result = a - result * b;
    }
  Transform::valueToString<C>(result, s);
  return Factory::createOperand(this->getType(), s);
}

template Operand<int8>::Operand(std::string const& value, eOperandType const& type);
template Operand<int16>::Operand(std::string const& value, eOperandType const& type);
template Operand<int32>::Operand(std::string const& value, eOperandType const& type);
template Operand<float>::Operand(std::string const& value, eOperandType const& type);
template Operand<double>::Operand(std::string const& value, eOperandType const& type);

void view(IOperand *p)
{
  std::cout << p->toString() << " , ";
  std::cout << "Accuracy :" << p->getPrecision() << ", ";
  switch(p->getType())
    {
    case Int8:
      std::cout << "Int8";
      break;
    case Int16:
      std::cout << "Int16";
      break;
    case Int32:
      std::cout << "Int32";
      break;
    case Float:
      std::cout << "Float";
      break;
    case Double:
      std::cout << "Double";
      break;
    }
  std::cout << std::endl;
}

int main()
{
  IOperand *a(NULL), *b(NULL), *c(NULL);

  std::cout << "OP+" << std::endl;
  a = Factory::createOperand(Int8, "20");
  b = Factory::createOperand(Int8, "66");
  c = b->operator+(*a);
  std::cout << a->toString() << "+" << b->toString() << "=" << c->toString() << std::endl;
  delete a;
  delete b;
  delete c;

  std::cout << "OP-" << std::endl;
  a = Factory::createOperand(Int8, "20");
  b = Factory::createOperand(Int8, "66");
  c = a->operator-(*b);
  std::cout << a->toString() << "-" << b->toString() << "=" << c->toString() << std::endl;
  delete a;
  delete b;
  delete c;

  std::cout << "OP*" << std::endl;
  a = Factory::createOperand(Int8, "2");
  b = Factory::createOperand(Int8, "20");
  c = a->operator*(*b);
  std::cout << a->toString() << "*" << b->toString() << "=" << c->toString() << std::endl;
  delete a;
  delete b;
  delete c;

  std::cout << "OP/" << std::endl;
  a = Factory::createOperand(Int8, "20");
  b = Factory::createOperand(Int8, "10");
  c = a->operator/(*b);
  std::cout << a->toString() << "/" << b->toString() << "=" << c->toString() << std::endl;
  delete a;
  delete b;
  delete c;

  std::cout << "OP%" << std::endl;
  a = Factory::createOperand(Int8, "40");
  b = Factory::createOperand(Int8, "15");
  c = a->operator%(*b);
  std::cout << a->toString() << "%" << b->toString() << "=" << c->toString() << std::endl;
  delete a;
  delete b;
  delete c;

  return 0;
}

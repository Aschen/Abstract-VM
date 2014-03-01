//
// Operand.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Tue Feb 18 16:05:55 2014 brunne-r
// Last update Sat Mar  1 12:40:57 2014 brunne-r
//

#include "Operand.hh"

template<typename C>
Operand<C>::Operand(std::string const& value, eOperandType const& type): _type(type)
{
  this->_accuracy = this->_type;
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
  size_t	tmp;
  std::string	s;

  b = Transform::stringToValue<C>(rhs.toString());
  a = Transform::stringToValue<C>(this->toString());
  if (b == 0)
    std::cerr << "Modulo by 0" << std::endl;
  else
    {
      tmp = a / b;
      result = C(tmp) * b;
      result = a - result;
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
    default:
      std::cout << "nil";
      break;
    }
  std::cout << std::endl;
}

//
// Factory.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Wed Feb 19 13:37:06 2014 brunne-r
// Last update Fri Feb 21 12:22:06 2014 brunne-r
//

#include "Factory.hh"
#include "Limits.hh"

IOperand	*Factory::createOperand(eOperandType type, const std::string& value)
{
  memptr_Factory	tabPtr[5];
  memptr_Factory	actu;

  tabPtr[Int8] = &Factory::createInt8;
  tabPtr[Int16] = &Factory::createInt16;
  tabPtr[Int32] = &Factory::createInt32;
  tabPtr[Float] = &Factory::createFloat;
  tabPtr[Double] = &Factory::createDouble;
  actu = tabPtr[type];
  return (*actu)(value);
}

IOperand *Factory::createInt8(const std::string& value)
{
  Limits::check<int8>(value);
  return new Operand<int8>(value, Int8);
}

IOperand *Factory::createInt16(const std::string& value)
{
  Limits::check<int16>(value);
  return new Operand<int16>(value, Int16);
}

IOperand *Factory::createInt32(const std::string& value)
{
  Limits::check<int32>(value);
  return new Operand<int32>(value, Int32);
}

IOperand *Factory::createFloat(const std::string& value)
{
  Limits::check<float>(value);
  return new Operand<float>(value, Float);
}

IOperand *Factory::createDouble(const std::string& value)
{
  Limits::check<double>(value);
  return new Operand<double>(value, Double);
}

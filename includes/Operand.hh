//
// Operand.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Tue Feb 18 16:05:58 2014 brunne-r
// Last update Thu Feb 20 16:13:47 2014 brunne-r
//

#include "AbstractVm.hh"
#include "IOperand.hh"
#include "Transform.hh"
#include "Factory.hh"

#ifndef OPERAND_H
# define OPERAND_H

template<typename C>
class	Operand : public IOperand
{
private:
  std::string	_str;
  C		_value;
  int		_accuracy;
  eOperandType	_type;
public:
  Operand(std::string const& value, eOperandType const& type);
  ~Operand();
  std::string const& toString() const;
  int	getPrecision() const;
  eOperandType	getType() const;
  IOperand *operator+(const IOperand &rhs) const;
  IOperand *operator-(const IOperand &rhs) const;
  IOperand *operator%(const IOperand &rhs) const;
  IOperand *operator*(const IOperand &rhs) const;
  IOperand *operator/(const IOperand &rhs) const;
};

#endif /* !OPERAND_H */

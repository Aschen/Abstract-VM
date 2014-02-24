//
// IOperand.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/sources/execution
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Tue Feb 18 11:28:46 2014 brunne-r
// Last update Fri Feb 21 14:54:00 2014 brunne-r
//

#ifndef IOPERAND_H
# define IOPERAND_H

# include "AbstractVm.hh"

class	IOperand
{
public:
  virtual std::string const& toString() const = 0;
  virtual int	getPrecision() const = 0;
  virtual eOperandType	getType() const = 0;
  virtual IOperand *operator+(const IOperand &rhs) const = 0;
  virtual IOperand *operator-(const IOperand &rhs) const = 0;
  virtual IOperand *operator%(const IOperand &rhs) const = 0;
  virtual IOperand *operator*(const IOperand &rhs) const = 0;
  virtual IOperand *operator/(const IOperand &rhs) const = 0;
  virtual ~IOperand() {}
};

#endif /* !IOPERAND_H */

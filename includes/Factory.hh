//
// ActionsOp.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Wed Feb 19 13:28:09 2014 brunne-r
// Last update Fri Feb 21 12:23:52 2014 brunne-r
//

#include "AbstractVm.hh"
#include "IOperand.hh"

#ifndef ACTIONSOP_H
# define ACTIONSOP_H

#include "Operand.hh"

class	Factory
{
private:
  static IOperand *createInt8(const std::string& value);
  static IOperand *createInt16(const std::string& value);
  static IOperand *createInt32(const std::string& value);
  static IOperand *createFloat(const std::string& value);
  static IOperand *createDouble(const std::string& value);
public:
  static IOperand *createOperand(eOperandType type, const std::string& value);
};

typedef	IOperand *(*memptr_Factory)(const std::string&);

#endif /* !ACTIONSOP_H */

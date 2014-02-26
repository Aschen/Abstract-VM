//
// ActionsOp.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Wed Feb 19 13:28:09 2014 brunne-r
// Last update Wed Feb 26 17:37:04 2014 brunne-r
//

#include "AbstractVm.hh"
#include "IOperand.hh"

#ifndef ACTIONSOP_H
# define ACTIONSOP_H

#include "Operand.hh"
#include "Exceptions.hh"

class	Factory
{
public:
    class   Error : public AvmException
    {
    public:
        Error(const std::string error);
        ~Error(void) throw() {}
        const std::string   getMessage(void) const;
    };
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

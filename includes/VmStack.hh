//
// DoInstruct.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Mon Feb 24 12:20:26 2014 brunne-r
// Last update Wed Feb 26 15:31:18 2014 brunne-r
//


#ifndef VMSTACK_H
# define VMSTACK_H

#include "AbstractVm.hh"
#include "IOperand.hh"
#include "Factory.hh"

class VmStack
{
  typedef bool	(VmStack::*StackMem)(void);
private:
  std::vector<IOperand*>	stack;
  Value				argument;
  StackMem			fptr[11];
public:
  VmStack();
  ~VmStack();
  bool	push(void);
  bool	pop(void);
  bool	dump(void);
  bool	assert(void);
  bool	prepareOp(IOperand **a, IOperand **b);
  bool	add(void);
  bool	sub(void);
  bool	mul(void);
  bool	div(void);
  bool	mod(void);
  bool	print(void);
  bool	exit(void);
public:
  bool	exec(Instruction instr);
};

#endif /* !VMSTACK_H */

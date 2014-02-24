//
// DoInstruct.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Mon Feb 24 12:20:26 2014 brunne-r
// Last update Mon Feb 24 12:39:54 2014 brunne-r
//

#ifndef VMSTACK_H
# define VMSTACK_H

#include "AbstractVm.h"

class VmStack
{
private:
  std::vector<IOperand*> stack;
public:
  VmStack();
  ~VmStack();
  bool	pop(void);
  bool	dump(void) const;
  bool	assert(const std::string &value) const;
  bool	add(void);
  bool	sub(void);
  bool	mul(void);
  bool	div(void);
  bool	mod(void);
  bool	print(void) const;
  void	exit(void) const;
public:
  bool	exec(Instruction instr);
};

#endif /* !VMSTACK_H */



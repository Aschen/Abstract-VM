//
// AvmCore.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Wed Feb 26 14:42:30 2014 brunne-r
// Last update Wed Feb 26 15:43:54 2014 brunne-r
//

#ifndef AVMCORE_H
# define AVMCORE_H

# include "AbstractVm.hh"
# include "VmStack.hh"

class AvmCore
{
private:
  VmStack	_Stack;
public:
  AvmCore();
  ~AvmCore();
  void		run(const std::vector<Instruction> &list);
};

#endif /* !AVMCORE_H */

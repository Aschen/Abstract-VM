//
// AvmCore.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/rompart
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Wed Feb 26 14:42:30 2014 brunne-r
// Last update Wed Feb 26 19:00:44 2014 brunne-r
//

#ifndef AVMCORE_H
# define AVMCORE_H

# include "AbstractVm.hh"
# include "VmStack.hh"
# include "Exceptions.hh"

class AvmCore
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
  VmStack	_Stack;
  bool		_ex;
public:
  AvmCore();
  ~AvmCore();
  void		run(const std::vector<Instruction> &list);
};

#endif /* !AVMCORE_H */

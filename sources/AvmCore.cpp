//
// AvmCore.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/sources
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Wed Feb 26 15:35:36 2014 brunne-r
// Last update Wed Feb 26 15:42:26 2014 brunne-r
//

#include "AvmCore.hh"

AvmCore::AvmCore()
{
}

AvmCore::~AvmCore()
{
}

void	AvmCore::run(const std::vector<Instruction> &list)
{
  bool						state(true);
  std::vector<Instruction>::const_iterator	it, end;

  it = list.begin();
  end = list.end();
  while (it < end && state)
    {
      state = this->_Stack.exec(*it);
      ++it;
    }
}

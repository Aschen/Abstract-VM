//
// AvmCore.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/sources
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Wed Feb 26 15:35:36 2014 brunne-r
// Last update Wed Feb 26 19:23:26 2014 brunne-r
//

#include "AvmCore.hh"

AvmCore::AvmCore() : _ex(false)
{
}

AvmCore::~AvmCore()
{
}

void	AvmCore::check(void) const
{
  if (!this->_ex)
    throw AvmCore::Error("unable to find \"exit\" instruction");
}

void	AvmCore::run(const std::vector<Instruction> &list)
{
  bool						state(true);
  std::vector<Instruction>::const_iterator	it, end;

  it = list.begin();
  end = list.end();
  while (it < end && state)
    {
      if ((*it).first == EXIT)
	this->_ex = true;
      state = this->_Stack.exec(*it);
      ++it;
    }
}

AvmCore::Error::Error(const std::string error) : AvmException(error)
{
}

const std::string AvmCore::Error::getMessage(void) const
{
    std::stringstream   ss;

    ss << "Execution Error : " << this->getError();
    return ss.str();
}

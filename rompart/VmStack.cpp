//
// VmStack.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Mon Feb 24 12:39:02 2014 brunne-r
// Last update Mon Feb 24 17:02:51 2014 brunne-r
//

#include "AbstractVm.hh"

VmStack::VmStack()
{
}

VmStack::~VmStack()
{
}

bool	VmStack::pop(void)
{
  if (this->stack.empty())
    std::cerr << "pop on a empty stack" << std::endl;
  else
    this->stack.pop_back();
  return true;
}

bool	VmStack::dump(void)
{
  std::vector<IOperand*>::const_iterator beg, end;

  if (this->stack.empty())
    std::cerr << "dump on a empty stack" << std::endl;
  else
    {
      beg = this->stack.begin();
      end = this->stack.end();
      for (; beg < end; beg++)
	{
	  std::cout << (*beg)->toString() << std::endl;
	}
    }
  return true;
}

bool		VmStack::assert(void)
{
  IOperand	*last;

  if (this->stack.empty())
    std::cerr << "assert on a empty stack" << std::endl;
  else
    {
      last = this->stack.back();
      if (!last || last->toString() != this->argument)
	std::cerr << "assert is false" << std::endl;
    }
  return true;
}

bool		VmStack::prepareOp(IOperand **a, IOperand **b)
{
  IOperand	*tmp;

  if (this->stack.size() < 2)
    std::cerr << "arithmetic operations requires 2 values at least" << std::endl;
  else
    {
      *a = this->stack.back();
      this->stack.pop_back();
      *b = this->stack.back();
      this->stack.pop_back();
      if (!*a || !*b)
	return false;
      else
	{
	  if ((*b)->getPrecision() > (*a)->getPrecision())
	    {
	      tmp = *b;
	      *b = *a;
	      *b = tmp;
	    }
	}
    }
  return true;
}

bool		VmStack::add(void)
{
  IOperand	*a, *b, *c;

  if (!this->prepareOp(&a, &b))
    return false;
  c = (*a) + (*b);
  delete a;
  delete b;
  this->stack.push_back(c);
  return true;
}

bool		VmStack::sub(void)
{
  IOperand	*a, *b, *c;

  if (!this->prepareOp(&a, &b))
    return false;
  c = (*a) - (*b);
  delete a;
  delete b;
  this->stack.push_back(c);
  return true;
}

bool		VmStack::div(void)
{
  IOperand	*a, *b, *c;

  if (!this->prepareOp(&a, &b))
    return false;
  c = (*a) / (*b);
  delete a;
  delete b;
  this->stack.push_back(c);
  return true;
}

bool		VmStack::mul(void)
{
  IOperand	*a, *b, *c;

  if (!this->prepareOp(&a, &b))
    return false;
  c = (*a) * (*b);
  delete a;
  delete b;
  this->stack.push_back(c);
  return true;
}

bool		VmStack::mod(void)
{
  IOperand	*a, *b, *c;

  if (!this->prepareOp(&a, &b))
    return false;
  c = (*a) % (*b);
  delete a;
  delete b;
  this->stack.push_back(c);
  return true;
}

bool		VmStack::print(void)
{
  IOperand	*p;

  if (this->stack.empty())
    std::cerr << "print on a empty stack" << std::endl;
  else
    {
      p = this->stack.back();
      if (p->getType() == Int8)
	std::cout << p->toString() << std::endl;
      else
	std::cerr << "print on a no-Int8 value" << std::endl;
    }
  return true;
}

bool	VmStack::exit(void)
{
  return false;
}

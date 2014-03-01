//
// VmStack.cpp for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Mon Feb 24 12:39:02 2014 brunne-r
// Last update Sat Mar  1 12:03:04 2014 brunne-r
//

#include "VmStack.hh"

VmStack::VmStack()
{
  this->fptr[PUSH] = &VmStack::push;
  this->fptr[ASSERT] = &VmStack::assert;
  this->fptr[POP] = &VmStack::pop;
  this->fptr[DUMP] = &VmStack::dump;
  this->fptr[ADD] = &VmStack::add;
  this->fptr[SUB] = &VmStack::sub;
  this->fptr[MUL] = &VmStack::mul;
  this->fptr[DIV] = &VmStack::div;
  this->fptr[MOD] = &VmStack::mod;
  this->fptr[PRINT] = &VmStack::print;
  this->fptr[EXIT] = &VmStack::exit;
}

VmStack::~VmStack()
{
  std::vector<IOperand*>::iterator	it,end;

  if (this->stack.size() > 0)
    {
      end = this->stack.end();
      for (it = this->stack.begin(); it < end; it++)
	{
	  delete (*it);
	}
    }
}

bool		VmStack::push(void)
{
  IOperand	*op;

  op = Factory::createOperand(this->argument.first, this->argument.second);
  if (op)
    {
      this->stack.push_back(op);
      return true;
    }
  else
    return false;
}

bool	VmStack::pop(void)
{
  if (this->stack.empty())
    {
      throw VmStack::Error("Stack","pop on a empty stack");
      return false;
    }
  else
    {
      this->stack.pop_back();
      return true;
    }
}

bool	VmStack::dump(void)
{
  std::vector<IOperand*>::const_iterator beg, end;

  if (this->stack.empty())
    return true;
  else
    {
      end = this->stack.end();
      for (beg = this->stack.begin(); beg < end; beg++)
	{
	  std::cout.precision(Transform::getStrPrecision((*beg)->toString()));
	  std::cout << (*beg)->toString() << std::endl;
	}
    }
  return true;
}

bool		VmStack::assert(void)
{
  IOperand	*last;

  if (this->stack.empty())
    {
      throw VmStack::Error("Stack", "assert on a empty stack");
      return false;
    }
  else
    {
      last = this->stack.back();
      if (!last || last->toString() != this->argument.second || last->getType() != this->argument.first)
	throw VmStack::Error("Execution", "assert is not verify");
    }
  return true;
}

bool		VmStack::prepareOp(IOperand **a, IOperand **b)
{
  IOperand	*tmp;

  if (this->stack.size() < 2)
    {
      throw VmStack::Error("Stack", "arithmetic operations requires 2 values at least");
      return false;
    }
  else
    {
      *b = this->stack.back();
      this->stack.pop_back();
      *a = this->stack.back();
      this->stack.pop_back();
      if (!*a || !*b)
	return false;
      if ((*b)->getPrecision() != (*a)->getPrecision())
	{
	  if ((*b)->getPrecision() > (*a)->getPrecision())
	    {
	      tmp = *a;
	      *a = Factory::createOperand((*b)->getType(), (*a)->toString());
	      delete tmp;
	    }
	  else
	    {
	      tmp = *b;
	      *b = Factory::createOperand((*a)->getType(), (*b)->toString());
	      delete tmp;
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
  if (b->toString() == "0")
    throw VmStack::Error("Floating", "division by 0");
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
  if (b->toString() == "0")
    throw VmStack::Error("Floating", "modulo by 0");
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
    {
      throw VmStack::Error("Stack", "print on a empty stack");
      return false;
    }
  else
    {
      p = this->stack.back();
      if (p->getType() == Int8)
	std::cout << Transform::stringToValue<int8>(p->toString()) << std::endl;
      else
	throw VmStack::Error("Execution", "print on a non-int8 value");
    }
  return true;
}

bool	VmStack::exit(void)
{
  return false;
}

bool		VmStack::exec(Instruction instr)
{
  Value		arg;
  StackMem	ptr;

  if (instr.first == PUSH || instr.first == ASSERT)
    {
      arg = instr.second;
      this->argument = arg;
    }
  ptr = this->fptr[instr.first];
  return ((this->*ptr)());
}

VmStack::Error::Error(const std::string &type, const std::string &error) : AvmException(error), _type(type)
{
}

const std::string VmStack::Error::getMessage(void) const
{
    std::stringstream   ss;

    ss << this->_type << " Error : " << this->getError();
    return ss.str();
}

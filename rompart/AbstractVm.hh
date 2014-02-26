//
// AbstractVm.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
// 
// Made by brunne-r
// Login   <brunne-r@epitech.net>
// 
// Started on  Thu Feb 20 16:02:48 2014 brunne-r
// Last update Tue Feb 25 15:07:17 2014 brunne-r
//

#ifndef ABSTRACTVM_HH_
# define ABSTRACTVM_HH_

typedef char Instruction;

typedef enum	eOperandType
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  }		eOperandType;

# define int8	char
# define int16	short
# define int32	int

# include <string>
# include <sstream>
# include <vector>
# include <iostream>

# include "IOperand.hh"
# include "Operand.hh"
# include "Factory.hh"
# include "Transform.hh"
# include "VmStack.hh"
# include "Limits.hh"

#endif /* !_ABSTRACTVM_HH_ */

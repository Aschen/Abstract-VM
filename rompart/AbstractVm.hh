//
// AbstractVm.hh for  in /home/brunne_r/Public/abstract_vm/cpp_abstractvm/includes
//
// Made by brunne-r
// Login   <brunne-r@epitech.net>
//
// Started on  Thu Feb 20 16:02:48 2014 brunne-r
// Last update Fri Feb 21 14:22:18 2014 brunne-r
//

#ifndef ABSTRACTVM_HH_
# define ABSTRACTVM_HH_

typedef enum	eOperandType
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  }		eOperandType;


# include <string>
# include <sstream>
# include "IOperand.hh"
# include "Operand.hh"
# include "Factory.hh"
# include "Transform.hh"

#endif /* !_ABSTRACTVM_HH_ */

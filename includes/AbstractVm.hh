#ifndef ABSTRACTVM_HH_
# define ABSTRACTVM_HH_

typedef enum	e_operandType
  {
    Int8 = 0,
    Int16,
    Int32,
    Float,
    Double
  }		eOperandType;

template<type T>
typedef struct	s_value
{
  eOperandType	type;
  T		value;
}		Value;

#endif /* !_ABSTRACTVM_HH_ */

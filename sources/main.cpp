#include "Input.hh"
#include "Lexer.hh"
#include "Parser.hh"
#include "Exceptions.hh"

void printUsage(char *name)
{
    std::cout << "Usage : " << std::endl;
    std::cout << std::setw(10) << name << " filename" << "\t" << "Read instructions from file 'filename'" << std::endl;
    std::cout << std::setw(10) << name << "\t\t" << "Read instructions from standard input until ';;'" << std::endl;
}

int main(int ac, char **av)
{
    std::string buf;

    try
    {
        if (ac == 1)
        {
            Input   avm;
            buf = avm.getBuf();
        }
        else if (ac == 2)
        {
            Input    avm(av[1]);
            buf = avm.getBuf();
        }
        else
        {
            printUsage(av[0]);
            return 0;
        }
        Lexer    lex(buf);
        Parser   parser(lex.getTokens());
        parser.dumpInstruction();
    }
    catch (AvmException &e)
    {
        std::cerr << e.getMessage() << std::endl;
        abort();
    }
    return 0;
}

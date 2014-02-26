#include "AbstractVm.hh"
#include "Input.hh"
#include "Lexer.hh"
#include "Parser.hh"
#include "Exceptions.hh"
#include "AvmCore.hh"

int printUsage(char *name)
{
    std::cout << "Usage : " << std::endl;
    std::cout << std::setw(10) << name << " -f filename" << "\t" << "Read instructions from file 'filename'" << std::endl;
    std::cout << std::setw(10) << name << "\t\t" << "Read instructions from standard input until ';;'" << std::endl;
    std::cout << std::setw(10) << name << " -i\t\t" << "Read instruction by instruction from standard input until ';;' or 'exit'" << std::endl;
    std::cout << std::setw(10) << name << " -h\t\t" << "Display this help" << std::endl;
    return 0;
}

int main(int ac, char **av)
{
    std::string buf;
    std::vector<Instruction> instrList;
    AvmCore		     core;

    int	i = 0;
    while (av[i])
      std::cout << av[i++] << std::endl;

    try
    {
        if (ac > 1 && ac <= 3)
        {
            std::string arg1(av[1]);
            if (arg1 == "-h" || arg1 == "--help")
                return printUsage(av[0]);
            else if (arg1 == "-i" || arg1 == "--interactive")
                Input(eFlag(INTERACTIVE));
            else if (arg1 == "-f" && ac == 3)
                buf = (Input(av[2])).getBuf();
            else
                return printUsage(av[0]);
        }
        else if (ac == 1)
            buf = (Input(NORMAL)).getBuf();
        else
            return printUsage(av[0]);
        instrList = Parser(Lexer(buf).getTokens(), NORMAL).getInstructions();
	core.run(instrList);
    }
    catch (AvmException &e)
    {
        std::cerr << e.getMessage() << std::endl;
        return 0;
    }
    return 0;
}

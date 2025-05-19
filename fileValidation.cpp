#include"fileValidation.h"
bool softValidation(const std::string &line)
{
    int semiColonAmount = 0, spaceAmount = 0, forwardSlashAmount = 0, commaAmount = 0;
    for(char c : line)
    {
        switch(c)
        {
        case ':':
            semiColonAmount++;
            break;
        case '/':
            forwardSlashAmount++;
            break;
        case ' ':
            spaceAmount++;
            break;
        case ',':
            commaAmount++;
            break;
        }
    }
    if(semiColonAmount != 1 || spaceAmount != 1 || forwardSlashAmount != 2 || commaAmount <= 0)
    {
        //std::cout << "SoftValidation Failed, Skipping Row." <<'\n';
        return false;
    }
    return true;
}
bool hardValidation(const Vector<std::string> &stringVec)
{
    if(stringVec.getSize() > 0)
    {
        for(int i = 1; i < stringVec.getSize(); i++)
        {
            if(!isValidFloat(stringVec[i]))
            {
                std::cout << "HardValidation Failed, Skipping Row." <<'\n';
                return false;
            }
        }
    }
    return true;
}


#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <string>

class Exception : public std::exception{

public:

    const char * what() const noexcept override =0;

};

class DeckFileNotFound: public Exception{

public:

    const char * what() const noexcept override
    {
        return "Deck File Error: File not found";
    }

};
class DeckFileFormatError:public Exception{

public:

    DeckFileFormatError(int line)
    {
        m_line = line;
        m_error = "Deck File Error: File format error in line " + std::to_string(m_line);
    }

    const char * what() const noexcept override
    {
        return m_error.c_str();
    }

private:

    int m_line;
    std::string m_error;
};
class DeckFileInvalidSize:public Exception{

public:

    const char * what() const noexcept override
    {
        return "Deck File Error: Deck size is invalid";
    }
};


#endif

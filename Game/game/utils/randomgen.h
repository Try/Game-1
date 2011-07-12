#ifndef RANDOMGEN_H
#define RANDOMGEN_H

class FileStream;

class RandomGen{
  public:
    RandomGen();
    typedef unsigned long Type;
    Type operator()();

    void reset();
    void serialize(FileStream &f);

    static const Type Max;
  private:
    Type m_z, m_w;
  };

#endif // RANDOMGEN_H

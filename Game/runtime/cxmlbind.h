#ifndef CXMLBIND_H
#define CXMLBIND_H

#include <QString>
#include <QXmlAttributes>

class CXMLBind {
  public:
    CXMLBind();

    void load(const char *);
  private:
    class Parser;
  };

#endif // CXMLBIND_H

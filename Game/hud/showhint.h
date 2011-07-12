#ifndef SHOWHINT_H
#define SHOWHINT_H

#include <QString>
#include <QQueue>
#include <QPixmap>

class QIcon;
class GameObjectClass;

class ShowHint {
  public:
    ShowHint();

    static ShowHint& instance();

    const QString& text();
    void setText( const QString& );

    QPixmap background;

    void addMessage( const QString & s, const QIcon &p );
    void addMessage( const GameObjectClass* str );

    class Message{
      public:
        Message(){}

        QString msg;
        int     time;
        QPixmap icon;
      };


    void tick();
    QQueue<Message>& messages();
  private:
    QString txt;
    static ShowHint* inst;

    QQueue<Message> msg;
  };

#endif // SHOWHINT_H

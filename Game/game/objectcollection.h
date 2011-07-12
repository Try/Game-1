#ifndef OBJECTCOLLECTION_H
#define OBJECTCOLLECTION_H

#include <vector>
#include <QRectF>

class GLObject;
class FileStream;

class ObjectCollection{
  public:
    ObjectCollection();
    ~ObjectCollection();

    void clear();

    GLObject& operator [](int id);
    const GLObject& operator [](int id) const;
    int find( const GLObject *);

		int size() const;
		void add(GLObject * );
		void del(GLObject *&);

		void select( QRectF selRect );
		void select( GLObject* );
		void select( double x, double y);

		GLObject* unitAt( double x, double y ) const;

		void unSelect();

		const std::vector<GLObject*>& selected() const;
		std::vector<GLObject*>& moviable();
		std::vector<GLObject*>& interactive();

		void command(float x, float y);
		void command( GLObject * taget );

		void aClick(float x, float y);
		void tick();

		void updateGUI();

		void serialize(FileStream &f, bool map = false);
		void sortPass();

		bool isGroupControlled();
	private:
		bool m_isGroupControlled;
		std::vector<GLObject*> object;
		std::vector<GLObject*> sunits, mvUnits, m_interactive;

		void destroyDeathUnits();

		void removeFromSets( GLObject *obj );

		void removeFrom(GLObject *obj,
										std::vector<GLObject*>& units);

    bool needToGuiUpdate;
    void toGuiUpdate();

    void coolMoveCommand(float x, float y);
  };

#endif // OBJECTCOLLECTION_H

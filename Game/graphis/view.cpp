#include "view.h"

#include <MyGL/GraphicsObject>
#include <MyGL/IMaterial>

View::View( MyGL::IScene &s ):scene(s){
    setViewsCount(1);
    }

View::~View(){
    for(size_t i=0; i<m_view.size(); ++i){
      MyGL::IMaterial*m =  m_view[i]->material();
      m_view[i]->setMaterial(0);
      delete m;
      }

    for(size_t i=0; i<m_view.size(); ++i)
      delete m_view[i];
    }

MyGL::StdMaterial* View::material(int i){
    return (MyGL::StdMaterial*)m_view[i]->material();
    }

void View::setViewsCount( int c ){
    while( int(m_view.size()) < c ){
      m_view.push_back( new MyGL::GraphicsObject(scene) );
      }

    while( int(m_view.size()) > c ){
      delete m_view.back();
      m_view.pop_back();
      }
    }

void View::setPosition(float x, float y, float z){
    for(size_t i=0; i<m_view.size(); ++i)
      m_view[i]->setPosition(x, y, z);
    }

void View::setSize(float x, float y, float z){
    for(size_t i=0; i<m_view.size(); ++i)
      m_view[i]->setSize(x, y, z);
    }


float View::x() const{
    return m_view[0]->x();
    }

float View::y() const{
    return m_view[0]->y();
    }

float View::z() const{
    return m_view[0]->z();
    }

float View::xSize() const{
    return m_view[0]->xSize();
    }

float View::ySize() const{
    return m_view[0]->ySize();
    }

float View::zSize() const{
    return m_view[0]->zSize();
    }

void View::setRotateZ(float r){
    for(size_t i=0; i<m_view.size(); ++i)
      m_view[i]->setRotateZ(r);
    }

void View::setRotateXY(float r){
    for(size_t i=0; i<m_view.size(); ++i)
      m_view[i]->setRotateY(r);
    }

void View::setVisible(bool v){
    for(size_t i=0; i<m_view.size(); ++i)
      m_view[i]->setVisible(v);
    }

float View::zRotation() const{
    return m_view[0]->zRotation();
    }

MyGL::IModel* View::model(){
    return m_view[0]->model();
    }

MyGL::GraphicsObject& View::view(int id){
    return *m_view[id];
    }

MyGL::GraphicsObject& View::operator[](int id){
    return view(id);
    }

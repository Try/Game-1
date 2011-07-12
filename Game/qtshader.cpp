#include "qtshader.h"

#include <MyGL/Uniform1f>
#include <MyGL/Uniform4f>
#include <MyGL/UniformMatrix4x4>
#include <MyGL/UniformSampler>
#include <MyGL/UniformArray>

#include <MyGL/IRender>
#include <MyGL/IErrorControl>

#include <string>
#include <QDebug>

QtShader::QtShader( MyGL::IRender &r):AbstractShader(r){

		}

void QtShader::loadVertexSource(const char * src){
		//loadSH(QGLShader::Vertex,   file);
//		qDebug() << src;
		if( !prog.addShaderFromSourceCode( QGLShader::Vertex, src ) ){
			qDebug() << src;
			std::string str = "Shader compile error: \n" + prog.log().toStdString();
			render().gl().errorCtrl()->compileError(this, str.data());
			}

		}

 void QtShader::loadFragmentSource(const char * src){
    //loadSH(QGLShader::Fragment, file);
    if( !prog.addShaderFromSourceCode( QGLShader::Fragment, src ) ){
      std::string str = "Shader compile error: \n" + prog.log().toStdString();
      render().gl().errorCtrl()->compileError(this, str.data());
      }
    }

 void QtShader::printInfoLog(){
    qDebug() << prog.log();
    }

 void QtShader::compile( bool autoLink ){

    if( autoLink )
      link();
    }

 void QtShader::link(){
    prog.link();
    }

 bool QtShader::isLinked(){
    return prog.isLinked();
    }

 void QtShader::use(){
    prog.bind();
    sendUniformsToGPU();
    }

 void QtShader::unUse(){
    prog.release();
    }

 const char* QtShader::getVSLog(){
    static const char * r = "QtShader::getVSLog not suporised";
    return r;
    }

 const char* QtShader::getFSLog(){
    static const char * r = "QtShader::getFSLog not suporised";
    return r;
    }

 MyGL::IUniformSampler* QtShader::uniformSampler( const char *name ){
   GLint h = prog.uniformLocation(name);

	 return uniform<MyGL::UniformSampler>(h);
	 }

 MyGL::IUniform1f* QtShader::uniform1f( const char* name ){
    GLint h = prog.uniformLocation(name);

    return uniform<MyGL::Uniform1f>(h);
    }

MyGL::IUniform4f* QtShader::uniform4f( const char* name ){
		GLint h = prog.uniformLocation(name);

		return uniform<MyGL::Uniform4f>(h);
		}

MyGL::IUniformMatrix4x4* QtShader::uniformMatrix4x4( const char *name ){
		GLint h = prog.uniformLocation(name);

		return uniform<MyGL::UniformMatrix4x4>(h);
		}

MyGL::UniformArray<MyGL::IUniformMatrix4x4>*
      QtShader::uniformMat4x4Array( const char* name, int s ){
    GLint h = prog.uniformLocation(name);

		return uniformArray< MyGL::UniformArray<MyGL::IUniformMatrix4x4> >(h, s);
		}

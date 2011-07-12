#ifndef QTSHADER_H
#define QTSHADER_H

#include <MyGL/AbstractShader>

namespace MyGL{
	class CGL;

	class IUniform1f;
	class IUniform4f;
	class IUniformMatrix4x4;
	}

#include <QtOpenGL/QGLShaderProgram>

class QtShader : public MyGL::AbstractShader{
	public:
		QtShader( MyGL::IRender &render );

		virtual void loadVertexSource(const char * src);
		virtual void loadFragmentSource(const char * src);

		virtual void printInfoLog();

		virtual void compile(bool autoLink = 1);
		virtual void link();
		virtual bool isLinked();

		virtual const char* getVSLog();
		virtual const char* getFSLog();

		MyGL::IUniform1f* uniform1f( const char* );
		MyGL::IUniform4f* uniform4f( const char* );
		MyGL::IUniformMatrix4x4* uniformMatrix4x4( const char* );

		MyGL::IUniformSampler* uniformSampler( const char* );
		MyGL::UniformArray<MyGL::IUniformMatrix4x4>*
					uniformMat4x4Array( const char *name , int size );
	private:
		virtual void use();
		virtual void unUse();

		QGLShaderProgram prog;
	};

#endif // QTSHADER_H

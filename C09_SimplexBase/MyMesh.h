#ifndef MY_MESH_H_
#define MY_MESH_H_

#include <vector>

// Include GLM
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\ext.hpp>
#include <glm\gtc\quaternion.hpp>

#include "Definitions.h"

struct vertex
{
	glm::vec3 position;
	glm::vec3 color;
};

class MyMesh
{
public:
	MyMesh();
	~MyMesh();

	std::vector<vertex> m_vertices;

	void Init();
	void InitShader();
	void InitTriangle();
	void InitQuad();

	void Draw();
	void SetScale(float size);
	
	static MyMesh* MakeTriangle(float size);
	static MyMesh* MakeQuad(float size);
private:
	GLuint m_uShaderProgramID = 0;
	GLuint m_uVAO = 0;
	GLuint m_uVBO = 0;

	float m_scale = 1.0f;
};

#endif // !MY_MESH_H_

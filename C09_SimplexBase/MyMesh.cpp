#include "MyMesh.h"


MyMesh::MyMesh()
{

}

MyMesh::~MyMesh()
{
	glDeleteShader(m_uShaderProgramID);
	glDeleteBuffers(1, &m_uVBO);
	glBindVertexArray(0);
	glDeleteVertexArrays(1, &m_uVAO);
}

void MyMesh::Init()
{
	// Create vertex arrays
	glGenVertexArrays(1, &m_uVAO);
	// Create buffer
	glGenBuffers(1, &m_uVBO);

	glBindVertexArray(m_uVAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_uVBO);

	InitShader();

	//InitTriangle();

	glBindVertexArray(0);
}

void MyMesh::InitShader()
{
	m_uShaderProgramID = LoadShaders("Shaders//BasicColor.vs", "Shaders//BasicColor.fs");
	glUseProgram(m_uShaderProgramID);
}

void MyMesh::InitTriangle()
{
	// Set the VAO to be used
	glBindVertexArray(m_uVAO);

	// Vertex 1 (Top)
	vertex vertexTopPoint;
	vertexTopPoint.position = glm::vec3(-1.0f, -1.0f, 0.0f);
	vertexTopPoint.color = glm::vec3(1.0f, 0.0f, 0.0f);

	m_vertices.push_back(vertexTopPoint);

	// Vertex 2 (left bottom)
	vertex vertexLeftBottomPoint;
	vertexLeftBottomPoint.position = glm::vec3(1.0f, -1.0f, 0.0f);
	vertexLeftBottomPoint.color = glm::vec3(0.0f, 1.0f, 0.0f);

	m_vertices.push_back(vertexLeftBottomPoint);

	// Vertex 3 (right bottom)
	vertex vertexRightBottomPoint;
	vertexRightBottomPoint.position = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexRightBottomPoint.color = glm::vec3(0.0f, 0.0f, 1.0f);

	m_vertices.push_back(vertexRightBottomPoint);

	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(vertex), &m_vertices[0], GL_STATIC_DRAW);

	// Count attribs
	int attributeCount = 2;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(1 * sizeof(glm::vec3)));

	// Unbind the VAO
	glBindVertexArray(0);
}

void MyMesh::InitQuad()
{
	// Set the VAO to be used
	glBindVertexArray(m_uVAO);

	float size = 0.5f;

	// Vertex 1 (TopLeft)
	vertex vertexTopLeftPoint;
	vertexTopLeftPoint.position = glm::vec3(-size, size, 0.0f);
	vertexTopLeftPoint.color = glm::vec3(1.0f, 0.0f, 0.0f);

	// Vertex 2 (top right)
	vertex vertexTopRightPoint;
	vertexTopRightPoint.position = glm::vec3(size, size, 0.0f);
	vertexTopRightPoint.color = glm::vec3(0.0f, 0.0f, 1.0f);

	// Vertex 3 (left bottom)
	vertex vertexLeftBottomPoint;
	vertexLeftBottomPoint.position = glm::vec3(-size, -size, 0.0f);
	vertexLeftBottomPoint.color = glm::vec3(0.0f, 1.0f, 0.0f);

	// Vertex 4 (right bottom)
	vertex vertexRightBottomPoint;
	vertexRightBottomPoint.position = glm::vec3(size, -size, 0.0f);
	vertexRightBottomPoint.color = glm::vec3(0.0f, 0.0f, 1.0f);


	m_vertices.push_back(vertexTopRightPoint);
	m_vertices.push_back(vertexTopLeftPoint);
	m_vertices.push_back(vertexLeftBottomPoint);

	m_vertices.push_back(vertexLeftBottomPoint);
	m_vertices.push_back(vertexRightBottomPoint);
	m_vertices.push_back(vertexTopRightPoint);

	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(vertex), &m_vertices[0], GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(vertex), &m_vertices[0], GL_STATIC_DRAW);

	// Count attribs
	int attributeCount = 2;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(vertex), (GLvoid*)(1 * sizeof(glm::vec3)));

	// Unbind the VAO
	glBindVertexArray(0);
}

void MyMesh::Draw()
{

	glBindVertexArray(m_uVAO);

	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());

	glBindVertexArray(0);
}

void MyMesh::SetScale(float size)
{
	m_scale = size;
}

MyMesh* MyMesh::MakeTriangle(float size)
{
	MyMesh* t = nullptr;
	t = new MyMesh;
	t->Init();
	t->InitTriangle();
	t->SetScale(size);
	return t;
}

MyMesh* MyMesh::MakeQuad(float size)
{
	MyMesh* t = nullptr;
	t = new MyMesh;
	t->Init();
	t->InitQuad();
	t->SetScale(size);
	return t;
}

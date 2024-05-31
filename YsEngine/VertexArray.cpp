#include "VertexArray.h"
#include <GL/glew.h>

VertexArray::VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices)
	:mNumIndices(numIndices),
	mNumVerts(numVerts)

{
	//사용할 Vertex Array에 대해 OpenGL ID 받아서 mVertexArray에 저장
	glGenVertexArrays(1, &mVertexArray);
	//사용할 VertexArray는 mVertexArray에 있는 것임을 OpenGL에 알려줌
	glBindVertexArray(mVertexArray);
	
	glGenBuffers(1, &mVertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, numVerts * 5 * sizeof(float), verts, GL_STATIC_DRAW);

	glGenBuffers(1, &mIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, numIndices * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, 0);
	//뒤에 두줄 생략

}

VertexArray::~VertexArray()
{
}

void VertexArray::SetActive()
{
}

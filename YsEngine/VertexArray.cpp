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
	

	//버텍스 배열 개체를 생성
	glGenBuffers(1, &mVertexBuffer);
	//버퍼 생성
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);



	glBufferData(
		GL_ARRAY_BUFFER,				// 데이터를 쓸 버퍼의 버퍼 타입
		numVerts * 5 * sizeof(float), // 복사할 바이트 크기
		verts,						 //복사할 소스(포인터)
		GL_STATIC_DRAW				// 이 데이터를 어떻게 사용할 것인가
	);


	//<인덱스 버퍼 생성하는 곳.>
	glGenBuffers(1, &mIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);


	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,			//인덱스 버퍼
		numIndices * sizeof(unsigned int),  //데이터의 크기
		indices,							//복사 소스
		GL_STATIC_DRAW);					//이 데이터를 어떻게 사용할 것인가



	glEnableVertexAttribArray(0); // 버텍스 속성 : 3개의 float인 레이아웃 지정
	glVertexAttribPointer(
		0,// 속성 인덱스 (첫번째 버텍스 속성 인덱스는 0)
		3,// 요소의 수 3
		GL_FLOAT,//요소의 타입
		GL_FALSE,//(정수형 타입에서만 사용된다)
		sizeof(float) * 5, 0 // 버텍스의 시작에서 이 속성까지의 오프셋
	); 
	//뒤에 두줄 생략

}

VertexArray::~VertexArray()
{
	glDeleteBuffers(1, &mVertexBuffer);
	glDeleteBuffers(1, &mIndexBuffer);
	glDeleteVertexArrays(1, &mVertexArray);
}

void VertexArray::SetActive()
{
}

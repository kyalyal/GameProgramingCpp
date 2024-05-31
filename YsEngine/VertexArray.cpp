#include "VertexArray.h"
#include <GL/glew.h>

VertexArray::VertexArray(const float* verts, unsigned int numVerts, const unsigned int* indices, unsigned int numIndices)
	:mNumIndices(numIndices),
	mNumVerts(numVerts)

{
	//����� Vertex Array�� ���� OpenGL ID �޾Ƽ� mVertexArray�� ����
	glGenVertexArrays(1, &mVertexArray);
	//����� VertexArray�� mVertexArray�� �ִ� ������ OpenGL�� �˷���
	glBindVertexArray(mVertexArray);
	

	//���ؽ� �迭 ��ü�� ����
	glGenBuffers(1, &mVertexBuffer);
	//���� ����
	glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);



	glBufferData(
		GL_ARRAY_BUFFER,				// �����͸� �� ������ ���� Ÿ��
		numVerts * 5 * sizeof(float), // ������ ����Ʈ ũ��
		verts,						 //������ �ҽ�(������)
		GL_STATIC_DRAW				// �� �����͸� ��� ����� ���ΰ�
	);


	//<�ε��� ���� �����ϴ� ��.>
	glGenBuffers(1, &mIndexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);


	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,			//�ε��� ����
		numIndices * sizeof(unsigned int),  //�������� ũ��
		indices,							//���� �ҽ�
		GL_STATIC_DRAW);					//�� �����͸� ��� ����� ���ΰ�



	glEnableVertexAttribArray(0); // ���ؽ� �Ӽ� : 3���� float�� ���̾ƿ� ����
	glVertexAttribPointer(
		0,// �Ӽ� �ε��� (ù��° ���ؽ� �Ӽ� �ε����� 0)
		3,// ����� �� 3
		GL_FLOAT,//����� Ÿ��
		GL_FALSE,//(������ Ÿ�Կ����� ���ȴ�)
		sizeof(float) * 5, 0 // ���ؽ��� ���ۿ��� �� �Ӽ������� ������
	); 
	//�ڿ� ���� ����

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

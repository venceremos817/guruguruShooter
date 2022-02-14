#pragma once
//========================================================
//	�ėp�o�������X�g
//--------------------------------------------------------
//	�I�u�W�F�N�g�����X�g�Ɋi�[���ĊǗ����邱�ƂŁA
//	�I�u�W�F�N�g���ꊇ�ŊǗ��ł���悤�ɂ��邱�Ƃ�ړI�Ƃ���B
//--------------------------------------------------------
//	2020.11.02	����J�n
//				���X�g�Ɋi�[����m�[�h����(Node.h)
//		.11.03	���X�g������Ƀm�[�h�Ɋi�[����Ă���I�u�W�F�N�g�͉�����Ȃ��悤�ɂ����B
//========================================================


//===== �C���N���[�h�� =====
#include "Node.h"

template<class T>
class List
{
public:
	List<T>();
	virtual ~List();

	void AddObject(T* pObj);				// ���X�g�̖����ɃI�u�W�F�N�g��ǉ�����B�m�[�h�͎����I�ɍ����
	T* CreateNewObj();						// ���X�g�̖����ɃI�u�W�F�N�g��V�K�쐬���A�ǉ�����B�m�[�h�͎����I�ɍ����B	(�g�p��	 CEnemy* pEnemy = list.CreateNewObj();
	void DestroyNode(Node<T>* pDestNode);	// �����ɓn���ꂽ�m�[�h��j���E�������B�m�[�h�ɕR�Â���ꂽ�I�u�W�F�N�g�͉�����Ȃ�
	void DestryoObj(T* pDestObj);			// �w�肳�ꂽ�I�u�W�F�N�g�Ƃ��̃m�[�h���������
	void ClearList();						// ���X�g���̃m�[�h��S�ĉ������B�I�u�W�F�N�g�͉�����Ȃ�
	void ClearAll();						// ���X�g���̂��ׂẴI�u�W�F�N�g�E�m�[�h���������

	Node<T>* GetHead() { return m_pHead; }	// ���X�g�ɓo�^����Ă���擪�̃m�[�h�̃|�C���^���擾�B���[�v�����̍ŏ��ɂ悭�g��
	Node<T>* GetTail() { return m_pTail; }	// ���X�g�ɓo�^����Ă��閖���̃m�[�h�̃|�C���^���擾
	Node<T>* GetPrev(Node<T> *pNode);		// �����ɓn�����m�[�h�̑O�̃m�[�h��Ԃ��B�O�̃m�[�h���Ȃ����nullptr���Ԃ�
//	Node<T>* GetRef();
	Node<T>* GetNext(Node<T> *pNode);		// �����ɓn�����m�[�h�̎��̃m�[�h��Ԃ��B���̃m�[�h���Ȃ����nullptr���Ԃ�

	void	Swap(Node<T> *pA, Node<T> *pB); // �m�[�h�̈ʒu�����ւ���


private:
	Node<T>	*m_pHead;		// ���X�g�̐擪
	Node<T>	*m_pTail;		// ���X�g�̖���
//	Node<T>	*m_pRef;	// ���݂̎Q�ƈʒu
};




////////////////////////////////////////////////////////////
// �����o�֐���ListBase.cpp�ɂĎ�������Ƒ�cpp����
// �֐��e���v���[�g�̒�`�������Ȃ��Ȃ邽�߁A�w�b�_�t�@�C����
// �����o�֐��̎������s��!!!!!!!!!!!!!!!!!!!!!!!!!!!
////////////////////////////////////////////////////////////


template<class T>
List<T>::List()
	: m_pHead(nullptr)
	, m_pTail(nullptr)
//	, m_pRef(nullptr)
{

}


template<class T>
List<T>::~List()
{
	ClearList();
	m_pHead = nullptr;
	m_pTail = nullptr;
}


template<class T>
void List<T>::AddObject(T* pObj)
{
	// �m�[�h��V�K�쐬 (���I�m��)
	Node<T> *pNewNode = new Node<T>(pObj);

	//--- ���X�g���J���̏ꍇ ---
	if (m_pHead == nullptr)
	{
		// �擪�Ɩ����ݒ�
		m_pHead = pNewNode;
		m_pTail = pNewNode;
		// ���̃m�[�h�͐擪�Ȃ̂őO��͖���
		pNewNode->SetPrevNext(nullptr, nullptr);
	}
	else	//--- ���X�g�Ƀm�[�h�����݂���ꍇ ---
	{
		// ���݂̖����̎��ɒǉ�
		GetTail()->SetNext(pNewNode);
		// �V����������m�[�h�̑O��֌W�ݒ�
		pNewNode->SetPrevNext(GetTail(), nullptr);
		// ���X�g�̖������V�K�m�[�h�ɂȂ�
		m_pTail = pNewNode;
	}
}


template<class T>
T* List<T>::CreateNewObj()
{
	T* NewObj = new T;
	AddObject(NewObj);

	return NewObj;
}


template<class T>
void List<T>::DestroyNode(Node<T>* pDestNode)
{
	// ���X�g���ŊY���̃m�[�h��T��
	Node<T> *pNode = nullptr;

	for (pNode = m_pHead; pNode != nullptr; pNode = pNode->GetNext())
	{
		if (pNode == pDestNode)
			break;
	}

	// ������Ȃ������ꍇ
	if (pNode == nullptr)
		return;

	//--- �������� ---
	// �擪�������Ƃ�
	if (pDestNode == m_pHead)
	{
		// 2�Ԗڂ��擪�ɂȂ�
		m_pHead = m_pHead->GetNext();
		m_pHead->SetPrev(nullptr);
		// �I�u�W�F�N�g���
		//pDestNode->DeleateObj();
		// �m�[�h���
		delete pDestNode;
		pDestNode = nullptr;
	}
	else if (pDestNode == m_pTail)	// �����������Ƃ�
	{
		// ��������2�Ԗڂ������ɂȂ�
		m_pTail = m_pTail->GetPrev();
		m_pTail->SetNext(nullptr);
		// �I�u�W�F�N�g���
		//pDestNode->DeleateObj();
		// �m�[�h���
		delete pDestNode;
		pDestNode = nullptr;
	}
	else	// ����ȊO
	{
		// �����m�[�h�̑O�����������
		pDestNode->m_pPrev->m_pNext = pDestNode->m_pNext;
		pDestNode->m_pNext->m_pPrev = pDestNode->m_pPrev;
		// �I�u�W�F�N�g���
		//pDestNode->DeleateObj();
		// �m�[�h���
		delete pDestNode;
		pDestNode = nullptr;
	}

}


template<class T>
void List<T>::DestryoObj(T* pDestObj)
{
	// ���X�g���ŊY���̃I�u�W�F�N�g�����m�[�h��T��
	Node<T> *pNode = nullptr;

	for (pNode = m_pHead; pNode != nullptr; pNode = pNode->GetNext())
	{
		if (pNode->GetObj() == pDestObj)
			break;
	}

	// ������Ȃ������ꍇ
	if (pNode == nullptr)
		return;

	//--- �������� ---
	// �擪�������Ƃ�
	if (pNode == m_pHead)
	{
		// 2�Ԗڂ��擪�ɂȂ�
		m_pHead = m_pHead->GetNext();
		// 2�Ԗڂ����݂���Ȃ�
		if (m_pHead != nullptr)
			m_pHead->SetPrev(nullptr);
		// �I�u�W�F�N�g���
		pNode->DeleateObj();
		// �m�[�h���
		delete pNode;
		pNode = nullptr;
	}
	else if (pNode == m_pTail)	// �����������Ƃ�
	{
		// ��������2�Ԗڂ������ɂȂ�
		m_pTail = m_pTail->GetPrev();
		m_pTail->SetNext(nullptr);
		// �I�u�W�F�N�g���
		pNode->DeleateObj();
		// �m�[�h���
		delete pNode;
		pNode = nullptr;
	}
	else	// ����ȊO
	{
		// �����m�[�h�̑O�����������
		pNode->m_pPrev->m_pNext = pNode->m_pNext;
		pNode->m_pNext->m_pPrev = pNode->m_pPrev;
		// �I�u�W�F�N�g���
		pNode->DeleateObj();
		// �m�[�h���
		delete pNode;
		pNode = nullptr;
	}
}


template<class T>
void List<T>::ClearList()
{
	Node<T>	*pNode = nullptr;
	Node<T> *pNextNode = nullptr;

	// �擪����I�u�W�F�N�g�̉���ƃm�[�h�̉�������Ă���
	for (pNode = m_pHead; pNode != nullptr; pNode = pNextNode)
	{
		// ���̃m�[�h���m��
		pNextNode = pNode->GetNext();

		// �I�u�W�F�N�g�̉��
		//pNode->DeleateObj();

		// �m�[�h�̊J��
		delete pNode;
		pNode = nullptr;
	}
	m_pHead = nullptr;
	m_pTail = nullptr;
}


template<class T>
void List<T>::ClearAll()
{
	Node<T>	*pNode = nullptr;
	Node<T> *pNextNode = nullptr;

	// �擪����I�u�W�F�N�g�̉���ƃm�[�h�̉�������Ă���
	for (pNode = m_pHead; pNode != nullptr; pNode = pNextNode)
	{
		// ���̃m�[�h���m��
		pNextNode = pNode->GetNext();

		// �I�u�W�F�N�g�̉��
		pNode->DeleateObj();

		// �m�[�h�̊J��
		delete pNode;
		pNode = nullptr;
	}
	m_pHead = nullptr;
	m_pTail = nullptr;
}


template<class T>
Node<T>* List<T>::GetPrev(Node<T>* pNode)
{
	return pNode->GetPrev();
}


template<class T>
Node<T>* List<T>::GetNext(Node<T> *pNode)
{
	return pNode->GetNext();
}


template<class T>
void List<T>::Swap(Node<T> *pA, Node<T> *pB)
{
	Node<T> *pTmp;

	pTmp = pA;
	pA = pB;
	pB = pTmp;
}
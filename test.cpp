/*#include "DxLib.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
//	ChangeWindowMode( TRUE ) ;
	

	if( DxLib_Init() == -1 )		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	int apple;
	apple = LoadGraph("picture/rinrinrin.png");
	DrawRotaGraph(230, 200, 0.1, 0, apple, TRUE);
	//DrawPixel( 320 , 240 , 0xffff ) ;	// �_��ł�
	//LoadGraphScreen( 0 , 0 , "picture/apple.png" , TRUE ) ;
	WaitKey() ;				// �L�[���͑҂�

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}
*/
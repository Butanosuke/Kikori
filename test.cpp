/*#include "DxLib.h"

// プログラムは WinMain から始まります
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
//	ChangeWindowMode( TRUE ) ;
	

	if( DxLib_Init() == -1 )		// ＤＸライブラリ初期化処理
	{
		return -1 ;			// エラーが起きたら直ちに終了
	}

	int apple;
	apple = LoadGraph("picture/rinrinrin.png");
	DrawRotaGraph(230, 200, 0.1, 0, apple, TRUE);
	//DrawPixel( 320 , 240 , 0xffff ) ;	// 点を打つ
	//LoadGraphScreen( 0 , 0 , "picture/apple.png" , TRUE ) ;
	WaitKey() ;				// キー入力待ち

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;				// ソフトの終了 
}
*/
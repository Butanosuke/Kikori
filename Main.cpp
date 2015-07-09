#include "DxLib.h"
#include "Opening.h"
#include "Play.h"
#include "MusicSelect.h"
#include "Result.h"

bool Process(char key[256]){
	if(ScreenFlip()!=0) return 0;
	if(ProcessMessage()!=0) return 0;
	if(ClearDrawScreen()!=0) return 0;
	if(GetHitKeyStateAll(key)!=0) return 0;
	return 1;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 16);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetMainWindowText("禁断の果実と楽園の護人");

	//int titlebg = LoadGraph("picture/taitol.bmp");
	int titletext = LoadGraph("picture/title.bmp");
	int bg = LoadGraph("picture/playbg_2.bmp");
	int tree = LoadGraph("picture/bigtreekai.bmp");
	char key[256];
	Opening openingscene;
	Play playscene;
	MusicSelect musicselect;
	Result resultscene;

	enum{
		OPENING,
		PLAY,
		MUSICSELECT,
		RESULT
	}scene=OPENING;

	while(Process(key)){
		switch(scene){
		case OPENING:
			DrawGraph(0, 0, bg, false);
			DrawGraph(0, 0, tree, true);
			DrawGraph(0, 0, titletext, true);
			if( ProcessMessage() == -1 ){
				break ;        // エラーが起きたらループを抜ける
			}
			openingscene.UpDate();
			openingscene.Draw();
			if(key[KEY_INPUT_LEFT]==1 || openingscene.HitJudge() == true){
				scene = MUSICSELECT;
				
			}

			if(key[KEY_INPUT_ESCAPE]==1){
				DxLib_End();
			}
			break;

		case MUSICSELECT:
			if( ProcessMessage() == -1 ){
				break ;        // エラーが起きたらループを抜ける
			}
			DrawGraph(0, 0, bg, false);
			DrawGraph(0, 0, tree, true);
			musicselect.UpDate();
			musicselect.Draw();
			if(musicselect.HitJudge() == true){
				playscene.Loadfile(musicselect.GetMusicfile());
				playscene.SetMusic(musicselect.GetMusic());
				playscene.SoundPlay();
				scene = PLAY;
			}
			if(key[KEY_INPUT_UP]==1){
				scene = PLAY;
			}

			if(key[KEY_INPUT_ESCAPE]==1){
				DxLib_End();
			}
			break;

		case PLAY:
			if( ProcessMessage() == -1 ){
				break ;        // エラーが起きたらループを抜ける
			}
			DrawGraph(0, 0, bg, false);
			DrawGraph(0, 0, tree, true);
			playscene.UpDate();
			playscene.Draw();
			if(key[KEY_INPUT_RIGHT]==1 || playscene.isPlaying() == false){
				playscene.SoundStop();
				scene = RESULT;
			}

			if(key[KEY_INPUT_ESCAPE]==1){
				DxLib_End();
			}
			break;
		
		case RESULT:
			DrawGraph(0, 0,bg, false);
			resultscene.Update();
			resultscene.Draw();
			if(key[KEY_INPUT_DOWN]==1 || resultscene.HitJudge() == true){
				scene = OPENING;
			}

			if(key[KEY_INPUT_ESCAPE]==1){
				DxLib_End();
			}
			break;
		}
	}
	DxLib_End();

	return 0;
}
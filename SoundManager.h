#pragma once

#include "Sound.h"

enum E_SOUND_EFFECT
{
	SE_SHOT,
	SE_BOMB,

	SE_MAX
};

enum E_SOUND_BGM
{
	BGM_GAME,

	BGM_MAX
};

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	HRESULT Init();
	void	Uninit();

	static IXAudio2SourceVoice* PlaySE(E_SOUND_EFFECT se);
	static void PlayBGM(E_SOUND_BGM bgm);
	static void StopBGM();
	static IXAudio2SourceVoice* GetBGMSpeaker();

private:
	static XAUDIO2_BUFFER** m_ppSoundEffect;
	static XAUDIO2_BUFFER** m_ppBGM;
	static IXAudio2SourceVoice* m_pBGMSpeaker;


private:
	void InitSE();
	void InitBGM();
	void UninitSoundSource();
};

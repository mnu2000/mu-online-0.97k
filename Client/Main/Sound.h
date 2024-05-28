#pragma once

/*
char* SoundList97[289] =
{
	"Data\\Sound\\aBat.wav",
	"Data\\Sound\\aBird1.wav",
	"Data\\Sound\\aBird2.wav",
	"Data\\Sound\\aCastleDoor.wav",
	"Data\\Sound\\aDoor.wav",
	"Data\\Sound\\aDungeon.wav",
	"Data\\Sound\\aForest.wav",
	"Data\\Sound\\aGrate.wav",
	"Data\\Sound\\aHeaven.wav",
	"Data\\Sound\\aMouse.wav",
	"Data\\Sound\\aRain.wav",
	"Data\\Sound\\aThunder01.wav",
	"Data\\Sound\\aThunder02.wav",
	"Data\\Sound\\aThunder03.wav",
	"Data\\Sound\\aTower.wav",
	"Data\\Sound\\aWater.wav",
	"Data\\Sound\\aWind.wav",
	"Data\\Sound\\blood1.wav",
	"Data\\Sound\\blood_attack1.wav",
	"Data\\Sound\\blood_attack2.wav",
	"Data\\Sound\\blood_die.wav",
	"Data\\Sound\\death1.wav",
	"Data\\Sound\\death_attack1.wav",
	"Data\\Sound\\death_die.wav",
	"Data\\Sound\\desert.wav",
	"Data\\Sound\\eBloodAttack.wav",
	"Data\\Sound\\eBlow.wav",
	"Data\\Sound\\eBlow1.wav",
	"Data\\Sound\\eBlow2.wav",
	"Data\\Sound\\eBlow3.wav",
	"Data\\Sound\\eBlow4.wav",
	"Data\\Sound\\eBow.wav",
	"Data\\Sound\\eBreak.wav",
	"Data\\Sound\\eCrossbow.wav",
	"Data\\Sound\\eCrow.wav",
	"Data\\Sound\\eDownGate.wav",
	"Data\\Sound\\eExplosion.wav",
	"Data\\Sound\\eFirecracker1.wav",
	"Data\\Sound\\eFirecracker2.wav",
	"Data\\Sound\\eGem.wav",
	"Data\\Sound\\eHitCristal.wav",
	"Data\\Sound\\eHitGate.wav",
	"Data\\Sound\\eHitGate2.wav",
	"Data\\Sound\\eIceArrow.wav",
	"Data\\Sound\\eMedal.wav",
	"Data\\Sound\\eMeteorite.wav",
	"Data\\Sound\\eMix.wav",
	"Data\\Sound\\ePhoenixExp.wav",
	"Data\\Sound\\ePiercing.wav",
	"Data\\Sound\\eRaidShoot.wav",
	"Data\\Sound\\eRidingSpear.wav",
	"Data\\Sound\\eShortBlow1.wav",
	"Data\\Sound\\eShortBlow2.wav",
	"Data\\Sound\\eShortBlow3.wav",
	"Data\\Sound\\eSoulBarrier.wav",
	"Data\\Sound\\eSwellLife.wav",
	"Data\\Sound\\eSwingLightSword.wav",
	"Data\\Sound\\eSwingWeapon1.wav",
	"Data\\Sound\\eSwingWeapon2.wav",
	"Data\\Sound\\eTelekinesis.wav",
	"Data\\Sound\\eThunder.wav",
	"Data\\Sound\\iBloodCastle.wav",
	"Data\\Sound\\iButtonClick.wav",
	"Data\\Sound\\iButtonError.wav",
	"Data\\Sound\\iButtonMove.wav",
	"Data\\Sound\\iCreateWindow.wav",
	"Data\\Sound\\iRepair.wav",
	"Data\\Sound\\iron1.wav",
	"Data\\Sound\\iron_attack1.wav",
	"Data\\Sound\\iTitle.wav",
	"Data\\Sound\\iWhisper.wav",
	"Data\\Sound\\jaikan1.wav",
	"Data\\Sound\\jaikan2.wav",
	"Data\\Sound\\jaikan_attack1.wav",
	"Data\\Sound\\jaikan_attack2.wav",
	"Data\\Sound\\jaikan_die.wav",
	"Data\\Sound\\mAlquamosAttack1.wav",
	"Data\\Sound\\mAlquamosDie.wav",
	"Data\\Sound\\mArgon1.wav",
	"Data\\Sound\\mArgon2.wav",
	"Data\\Sound\\mArgonAttack1.wav",
	"Data\\Sound\\mArgonAttack2.wav",
	"Data\\Sound\\mArgonDie.wav",
	"Data\\Sound\\mAssassin1.wav",
	"Data\\Sound\\mAssassinAttack1.wav",
	"Data\\Sound\\mAssassinAttack2.wav",
	"Data\\Sound\\mAssassinDie.wav",
	"Data\\Sound\\mBahamut1.wav",
	"Data\\Sound\\mBali1.wav",
	"Data\\Sound\\mBali2.wav",
	"Data\\Sound\\mBaliAttack1.wav",
	"Data\\Sound\\mBaliAttack2.wav",
	"Data\\Sound\\mBaliAttack2.wav",
	"Data\\Sound\\mBalrog1.wav",
	"Data\\Sound\\mBalrog1.wav",
	"Data\\Sound\\mBalrog2.wav",
	"Data\\Sound\\mBalrogDie.wav",
	"Data\\Sound\\mBeetle1.wav",
	"Data\\Sound\\mBeetleAttack1.wav",
	"Data\\Sound\\mBeetleDie.wav",
	"Data\\Sound\\mBepar1.wav",
	"Data\\Sound\\mBepar2.wav",
	"Data\\Sound\\mBlackSkullAttack.wav",
	"Data\\Sound\\mBlackSkullDie.wav",
	"Data\\Sound\\mBone1.wav",
	"Data\\Sound\\mBone2.wav",
	"Data\\Sound\\mBudge1.wav",
	"Data\\Sound\\mBudgeAttack1.wav",
	"Data\\Sound\\mBudgeDie.wav",
	"Data\\Sound\\mBull1.wav",
	"Data\\Sound\\mBull2.wav",
	"Data\\Sound\\mBullAttack1.wav",
	"Data\\Sound\\mBullAttack1.wav",
	"Data\\Sound\\mBullAttack2.wav",
	"Data\\Sound\\mBullDie.wav",
	"Data\\Sound\\mBullDie.wav",
	"Data\\Sound\\mBullDie.wav",
	"Data\\Sound\\mBullDie.wav",
	"Data\\Sound\\mCursedKing1.wav",
	"Data\\Sound\\mCursedKing2.wav",
	"Data\\Sound\\mCursedKingDie1.wav",
	"Data\\Sound\\mDarkKnight1.wav",
	"Data\\Sound\\mDarkKnight2.wav",
	"Data\\Sound\\mDarkKnightAttack1.wav",
	"Data\\Sound\\mDarkKnightAttack2.wav",
	"Data\\Sound\\mDarkKnightDie.wav",
	"Data\\Sound\\mDrakan1.wav",
	"Data\\Sound\\mDrakanAttack1.wav",
	"Data\\Sound\\mDrakanDie.wav",
	"Data\\Sound\\mGhaintOrgerDie.wav",
	"Data\\Sound\\mGhost1.wav",
	"Data\\Sound\\mGhost2.wav",
	"Data\\Sound\\mGhostAttack1.wav",
	"Data\\Sound\\mGhostAttack2.wav",
	"Data\\Sound\\mGhostDie.wav",
	"Data\\Sound\\mGiant1.wav",
	"Data\\Sound\\mGiant2.wav",
	"Data\\Sound\\mGiantAttack1.wav",
	"Data\\Sound\\mGiantAttack2.wav",
	"Data\\Sound\\mGiantDie.wav",
	"Data\\Sound\\mGoblin1.wav",
	"Data\\Sound\\mGoblin2.wav",
	"Data\\Sound\\mGoblinAttack1.wav",
	"Data\\Sound\\mGoblinAttack2.wav",
	"Data\\Sound\\mGoblinDie.wav",
	"Data\\Sound\\mGolem1.wav",
	"Data\\Sound\\mGolem2.wav",
	"Data\\Sound\\mGolemAttack1.wav",
	"Data\\Sound\\mGolemAttack2.wav",
	"Data\\Sound\\mGolemDie.wav",
	"Data\\Sound\\mGorgon1.wav",
	"Data\\Sound\\mGorgon2.wav",
	"Data\\Sound\\mGorgonAttack1.wav",
	"Data\\Sound\\mGorgonAttack2.wav",
	"Data\\Sound\\mGorgonAttack2.wav",
	"Data\\Sound\\mGorgonDie.wav",
	"Data\\Sound\\mGorgonDie.wav",
	"Data\\Sound\\mHellSpider1.wav",
	"Data\\Sound\\mHellSpiderAttack1.wav",
	"Data\\Sound\\mHellSpiderDie.wav",
	"Data\\Sound\\mHomord1.wav",
	"Data\\Sound\\mHomord2.wav",
	"Data\\Sound\\mHomordAttack1.wav",
	"Data\\Sound\\mHomordDie.wav",
	"Data\\Sound\\mHound1.wav",
	"Data\\Sound\\mHound2.wav",
	"Data\\Sound\\mHoundAttack1.wav",
	"Data\\Sound\\mHoundAttack2.wav",
	"Data\\Sound\\mHoundDie.wav",
	"Data\\Sound\\mHunter1.wav",
	"Data\\Sound\\mHunter2.wav",
	"Data\\Sound\\mHunter2.wav",
	"Data\\Sound\\mHunter2.wav",
	"Data\\Sound\\mHunter2.wav",
	"Data\\Sound\\mHunterAttack1.wav",
	"Data\\Sound\\mHunterAttack2.wav",
	"Data\\Sound\\mHunterDie.wav",
	"Data\\Sound\\mHydra1.wav",
	"Data\\Sound\\mHydraAttack1.wav",
	"Data\\Sound\\mIceMonster1.wav",
	"Data\\Sound\\mIceMonster2.wav",
	"Data\\Sound\\mIceMonsterDie.wav",
	"Data\\Sound\\mIceQueen1.wav",
	"Data\\Sound\\mIceQueen2.wav",
	"Data\\Sound\\mIceQueenAttack1.wav",
	"Data\\Sound\\mIceQueenAttack2.wav",
	"Data\\Sound\\mIceQueenDie.wav",
	"Data\\Sound\\mLarva1.wav",
	"Data\\Sound\\mLarva2.wav",
	"Data\\Sound\\mLizardKing1.wav",
	"Data\\Sound\\mLizardKing2.wav",
	"Data\\Sound\\mMagicSkull.wav",
	"Data\\Sound\\mMegaCrust1.wav",
	"Data\\Sound\\mMegaCrustAttack1.wav",
	"Data\\Sound\\mMegaCrustDie.wav",
	"Data\\Sound\\mMolt1.wav",
	"Data\\Sound\\mMoltAttack1.wav",
	"Data\\Sound\\mMoltDie.wav",
	"Data\\Sound\\mOgre1.wav",
	"Data\\Sound\\mOgre2.wav",
	"Data\\Sound\\mOgreAttack1.wav",
	"Data\\Sound\\mOgreAttack2.wav",
	"Data\\Sound\\mOgreDie.wav",
	"Data\\Sound\\mOrcArcherAttack1.wav",
	"Data\\Sound\\mOrcCapAttack1.wav",
	"Data\\Sound\\mPhantom1.wav",
	"Data\\Sound\\mPhantomAttack1.wav",
	"Data\\Sound\\mPhantomDie.wav",
	"Data\\Sound\\mPhoenix1.wav",
	"Data\\Sound\\mPhoenixAttack1.wav",
	"Data\\Sound\\mRainner1.wav",
	"Data\\Sound\\mRainnerAttack1.wav",
	"Data\\Sound\\mRainnerDie.wav",
	"Data\\Sound\\mRedSkull.wav",
	"Data\\Sound\\mRedSkullAttack.wav",
	"Data\\Sound\\mRedSkullDie.wav",
	"Data\\Sound\\mSatanAttack1.wav",
	"Data\\Sound\\mScorpion1.wav",
	"Data\\Sound\\mScorpion2.wav",
	"Data\\Sound\\mScorpionAttack1.wav",
	"Data\\Sound\\mScorpionAttack2.wav",
	"Data\\Sound\\mScorpionDie.wav",
	"Data\\Sound\\mShadow1.wav",
	"Data\\Sound\\mShadow2.wav",
	"Data\\Sound\\mShadowAttack1.wav",
	"Data\\Sound\\mShadowAttack1.wav",
	"Data\\Sound\\mShadowAttack2.wav",
	"Data\\Sound\\mShadowDie.wav",
	"Data\\Sound\\mSpider1.wav",
	"Data\\Sound\\mutant1.wav",
	"Data\\Sound\\mutant2.wav",
	"Data\\Sound\\mutant_attack1.wav",
	"Data\\Sound\\mValkyrie1.wav",
	"Data\\Sound\\mValkyrieDie.wav",
	"Data\\Sound\\mWizard1.wav",
	"Data\\Sound\\mWizard2.wav",
	"Data\\Sound\\mWizardAttack1.wav",
	"Data\\Sound\\mWizardAttack2.wav",
	"Data\\Sound\\mWizardAttack2.wav",
	"Data\\Sound\\mWizardDie.wav",
	"Data\\Sound\\mWoodMon1.wav",
	"Data\\Sound\\mWoodMon2.wav",
	"Data\\Sound\\mWoodMonAttack1.wav",
	"Data\\Sound\\mWoodMonAttack2.wav",
	"Data\\Sound\\mWoodMonDie.wav",
	"Data\\Sound\\mWorm1.wav",
	"Data\\Sound\\mWorm2.wav",
	"Data\\Sound\\mWormDie.wav",
	"Data\\Sound\\mYeti1.wav",
	"Data\\Sound\\mYeti1.wav",
	"Data\\Sound\\mYeti1.wav",
	"Data\\Sound\\mYeti1.wav",
	"Data\\Sound\\mYeti2.wav",
	"Data\\Sound\\mYetiAttack1.wav",
	"Data\\Sound\\mYetiDie.wav",
	"Data\\Sound\\mYetiDie.wav",
	"Data\\Sound\\mYetiDie.wav",
	"Data\\Sound\\nBlackSmith.wav",
	"Data\\Sound\\nHarp.wav",
	"Data\\Sound\\nMix.wav",
	"Data\\Sound\\pDrink.wav",
	"Data\\Sound\\pDropItem.wav",
	"Data\\Sound\\pDropMoney.wav",
	"Data\\Sound\\pEatApple.wav",
	"Data\\Sound\\pEnergy.wav",
	"Data\\Sound\\pFemaleScream1.wav",
	"Data\\Sound\\pFemaleScream2.wav",
	"Data\\Sound\\pGetItem.wav",
	"Data\\Sound\\pHeartBeat.wav",
	"Data\\Sound\\pMaleDie.wav",
	"Data\\Sound\\pMaleScream1.wav",
	"Data\\Sound\\pMaleScream2.wav",
	"Data\\Sound\\pMaleScream3.wav",
	"Data\\Sound\\pSwim.wav",
	"Data\\Sound\\pWalk(Grass).wav",
	"Data\\Sound\\pWalk(Snow).wav",
	"Data\\Sound\\pWalk(Soil).wav",
	"Data\\Sound\\sAquaFlash.wav",
	"Data\\Sound\\sEvil.wav",
	"Data\\Sound\\sFlame.wav",
	"Data\\Sound\\sHellFire.wav",
	"Data\\Sound\\sIce.wav",
	"Data\\Sound\\sKnightDefense.wav",
	"Data\\Sound\\sKnightSkill1.wav",
	"Data\\Sound\\sKnightSkill2.wav",
	"Data\\Sound\\sKnightSkill3.wav",
	"Data\\Sound\\sKnightSkill4.wav",
	"Data\\Sound\\sMagic.wav",
	"Data\\Sound\\sTornado.wav",
};
*/

class CSound
{
public:

	CSound();

	virtual ~CSound();

	void Init();

	void UpdateVolume(int volumeLevel);

private:

	void InitSoundConvertion();

	static void MyLoadWaveFile(int Buffer, TCHAR* strFileName, int MaxChannel, bool Enable);

	static void ReceiveLevelUpHook(BYTE* ReceiveBuffer);

	void SetMasterVolume(long vol);

	void SetVolume(int Buffer, long vol);

public:

	BYTE VolumeLevel;

private:

	long g_MasterVolume;
};

extern CSound gSound;
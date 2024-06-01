#pragma once

class CBuff
{
public:

	CBuff();

	virtual ~CBuff();

	void Init();

private:

	static void InsertBuffPhysicalEffect(eEffectState buff, DWORD o);

	static void ClearBuffPhysicalEffect(eEffectState buff, DWORD o);

	static INT16 CBuff::MoveEffectHook(DWORD o, int objectNumber);
	static void DrawObjectHook(DWORD o, bool Translate, int Select, int ExtraMon);
	static void CalculateGMBalloonPosition(DWORD owner, float* position);

};

extern CBuff gBuff;
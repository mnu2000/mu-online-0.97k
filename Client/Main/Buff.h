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

	static INT16 CBuff::MoveEffectHook(WORD* o, int objectNumber);
};

extern CBuff gBuff;
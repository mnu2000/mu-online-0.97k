#include "stdafx.h"
#include "ItemBag.h"
#include "DSProtocol.h"
#include "ItemOptionRate.h"
#include "ItemManager.h"
#include "Map.h"
#include "MemScript.h"
#include "Protocol.h"
#include "ServerInfo.h"
#include "Util.h"

CItemBag::CItemBag()
{
	this->Init();
}

CItemBag::~CItemBag()
{

}

void CItemBag::Init()
{
	memset(this->m_EventName, 0, sizeof(this->m_EventName));

	this->m_DropZen = 0;

	this->m_ItemDropRate = 0;

	this->m_ItemDropCount = 0;

	this->m_ItemDropType = 0;

	this->m_SendFirework = 0;

	this->m_count = 0;
}

void CItemBag::Load(char* path)
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);

		return;
	}

	if (lpMemScript->SetBuffer(path) == false)
	{
		ErrorMessageBox(lpMemScript->GetLastError());

		delete lpMemScript;

		return;
	}

	this->Init();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while (true)
			{
				if (section == 0)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					strcpy_s(this->m_EventName, lpMemScript->GetString());

					this->m_DropZen = lpMemScript->GetAsNumber();

					this->m_ItemDropRate = lpMemScript->GetAsNumber();

					this->m_ItemDropCount = lpMemScript->GetAsNumber();

					this->m_ItemDropType = lpMemScript->GetAsNumber();

					this->m_SendFirework = lpMemScript->GetAsNumber();
				}
				else if (section == 1)
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					ITEM_BAG_INFO info;

					memset(&info, 0, sizeof(info));

					info.Index = SafeGetItem(GET_ITEM(lpMemScript->GetNumber(), lpMemScript->GetAsNumber()));

					info.MinLevel = lpMemScript->GetAsNumber();

					info.MaxLevel = lpMemScript->GetAsNumber();

					info.SkillOption = lpMemScript->GetAsNumber();

					info.LuckOption = lpMemScript->GetAsNumber();

					info.AddOption = lpMemScript->GetAsNumber();

					info.ExceOption = lpMemScript->GetAsNumber();

					this->SetInfo(info);
				}
				else
				{
					if (strcmp("end", lpMemScript->GetAsString()) == 0)
					{
						break;
					}
				}
			}
		}
	}
	catch (...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	this->m_ItemBagEx.Load(path);

	delete lpMemScript;
}

void CItemBag::SetInfo(ITEM_BAG_INFO info)
{
	if (this->m_count < 0 || this->m_count >= MAX_BAG_ITEM)
	{
		return;
	}

	this->m_BagInfo[this->m_count++] = info;
}

ITEM_BAG_INFO* CItemBag::GetInfo(int index)
{
	if (index < 0 || index >= this->m_count)
	{
		return 0;
	}

	return &this->m_BagInfo[index];
}

int CItemBag::GetItemLevel(ITEM_BAG_INFO* lpInfo)
{
	if (lpInfo->MinLevel >= lpInfo->MaxLevel)
	{
		return lpInfo->MinLevel;
	}

	return (lpInfo->MinLevel + (GetLargeRand() % ((lpInfo->MaxLevel - lpInfo->MinLevel) + 1)));
}

int CItemBag::GetItemExceOption(ITEM_BAG_INFO* lpInfo, int dropType)
{
	int count = 0;

	int ExceOption = 0;

	lpInfo->ExceOption = (lpInfo->ExceOption == 0) ? lpInfo->ExceOption : (dropType == 0) ? lpInfo->ExceOption : ((GetLargeRand() % lpInfo->ExceOption) + 1);

	while (true)
	{
		if (count >= lpInfo->ExceOption || count >= MAX_EXC_OPTION)
		{
			break;
		}

		int value = 1 << (GetLargeRand() % MAX_EXC_OPTION);

		if ((ExceOption & value) == 0)
		{
			ExceOption |= value;

			count++;
		}
	}

	return ExceOption;
}

bool::CItemBag::GetRandomItemDropLocation(int map, int* ox, int* oy, int tx, int ty, int count)
{
	int x = (*ox);

	int y = (*oy);

	tx = ((tx < 1) ? 1 : tx);

	ty = ((ty < 1) ? 1 : ty);

	for (int n = 0; n < count; n++)
	{
		(*ox) = ((GetLargeRand() % (tx + 1)) * ((GetLargeRand() % 2 == 0) ? -1 : 1)) + x;

		(*oy) = ((GetLargeRand() % (ty + 1)) * ((GetLargeRand() % 2 == 0) ? -1 : 1)) + y;

		if (gMap[map].CheckAttr((*ox), (*oy), 4) == 0 && gMap[map].CheckAttr((*ox), (*oy), 8) == 0)
		{
			return 1;
		}
	}

	return 0;
}

bool CItemBag::GetItem(LPOBJ lpObj, CItem* lpItem)
{
	if (this->m_ItemBagEx.m_ItemBagInfo.empty() == 0)
	{
		return this->m_ItemBagEx.GetItem(lpObj, lpItem);
	}

	if (this->m_count == 0)
	{
		return 0;
	}

	ITEM_BAG_INFO* lpInfo = this->GetInfo(GetLargeRand() % this->m_count);

	if (lpInfo == 0)
	{
		return 0;
	}

	int level = this->GetItemLevel(lpInfo);

	int SkillOption = lpInfo->SkillOption;

	int LuckOption = lpInfo->LuckOption;

	int AddOption = lpInfo->AddOption;

	int ExceOption = this->GetItemExceOption(lpInfo, this->m_ItemDropType);

	if (this->m_ItemDropType != 0)
	{
		if (SkillOption != 0)
		{
			SkillOption = GetLargeRand() % 2;
		}

		if (LuckOption != 0)
		{
			LuckOption = GetLargeRand() % 2;
		}

		AddOption = 1 + (GetLargeRand() % gServerInfo.m_MaxItemOption);

		if ((GetLargeRand() % 100) < (AddOption * 3))
		{
			AddOption = (gServerInfo.m_MaxItemOption + 1) - AddOption;
		}
		else
		{
			AddOption = 0;
		}
	}

	lpItem->m_Level = level;

	lpItem->Convert(lpInfo->Index, SkillOption, LuckOption, AddOption, ExceOption);

	return 1;
}

bool CItemBag::DropItem(LPOBJ lpObj, int map, int x, int y)
{
	if (this->m_ItemBagEx.m_ItemBagInfo.empty() == 0)
	{
		return this->m_ItemBagEx.DropItem(lpObj, map, x, y);
	}

	for (int n = 0; n < this->m_ItemDropCount; n++)
	{
		int px = x;

		int py = y;

		if (this->m_ItemDropCount > 1 || (gMap[map].CheckAttr(px, py, 4) != 0 || gMap[map].CheckAttr(px, py, 8) != 0))
		{
			if (this->GetRandomItemDropLocation(map, &px, &py, 2, 2, 10) == 0)
			{
				px = lpObj->X;

				py = lpObj->Y;
			}
		}

		if ((GetLargeRand() % 100) >= this->m_ItemDropRate)
		{
			gMap[map].MoneyItemDrop(this->m_DropZen, px, py);

			continue;
		}

		CItem item;

		if (this->GetItem(lpObj, &item) != 0)
		{
			GDCreateItemSend(lpObj->Index, map, px, py, item.m_Index, (BYTE)item.m_Level, 0, item.m_SkillOption, item.m_LuckOption, item.m_AddOption, lpObj->Index, item.m_ExceOption);

			continue;
		}
	}

	if (this->m_SendFirework != 0)
	{
		GCFireworksSend(lpObj, lpObj->X, lpObj->Y);
	}

	return 1;
}